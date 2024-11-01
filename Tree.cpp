#include "stdafx.h"
#include "Tree.h"
#include "Branch.h"
#include "EffectLog.h"
#include "Scene.h"

Tree::Tree(const std::string& name)
	: GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = -1;
}

Tree::~Tree()
{
	Release();
}

Sides Tree::RandomSide() const
{
	int rand = Utils::RandomRange(0, 2);
	if (rand > 1)
		return Sides::None;
	return (Sides)rand;
}

void Tree::Init()
{
	Release();

	tree.setTexture(TEXTURE_MGR.Get(treeTexId), true);
	Utils::SetOrigin(tree, Origins::BC);

	sf::Vector2f orginBranch;
	orginBranch.x = tree.getLocalBounds().width * -0.5f;
	sf::Texture& branchTex = TEXTURE_MGR.Get(branchTexId);
	orginBranch.y = branchTex.getSize().y * 0.5f;

	for (int i = 0; i < branchCount; ++i)
	{
		Branch* branch = new Branch(branchTexId);
		branch->SetOrigin(orginBranch);
		branch->Init();
		branch->SetSide(RandomSide());
		branches.push_back(branch);
	}

	effectLogPool.Init(owner, nullptr, 3);
	popEffectPool.Init(owner, nullptr, 10);
}

void Tree::Release()
{
	for (auto branch : branches)
	{
		branch->Release();
		delete branch;
	}
	branches.clear();
}


void Tree::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(treeTexId), true);
	for (auto branch : branches)
	{
		branch->Reset();
	}
	UpdateBranchPos();
	auto lastBranch = branches.front();
	lastBranch->SetSide(Sides::None);
	effectLogPool.Reset();
	popEffectPool.Reset();
}

void Tree::Update(float dt)
{
	for (auto branch : branches)
	{
		branch->Update(dt);
	}

	effectLogPool.Update();
	popEffectPool.Update();
}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(tree);
	for (auto branch : branches)
	{
		if (branch->IsActive())
		{
			branch->Draw(window);
		}
	}
}

void Tree::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	tree.setPosition(position);
	UpdateBranchPos();
}

void Tree::SetScale(const sf::Vector2f& treescale)
{
	sf::Vector2f prevscale= scale;
	scale = treescale;
	tree.setScale(treescale);
	sf::Vector2f orginBranch;
	orginBranch.x = tree.getGlobalBounds().width * -0.5f;
	orginBranch.y = TEXTURE_MGR.Get(branchTexId).getSize().y * 0.5f;
	for (auto& br : branches)
	{
		br->SetOrigin(orginBranch);
	}
	for (auto& log : effectLogPool.used)
	{
		sf::Vector2f logscale = log->GetScale();
		log->SetScale({ logscale .x*(scale.x/ prevscale .x),logscale.y * (scale.y / prevscale.y) });
	}
	for (auto& log : effectLogPool.unused)
	{
		sf::Vector2f logscale = log->GetScale();
		log->SetScale({ logscale.x * (scale.x / prevscale.x),logscale.y * (scale.y / prevscale.y) });
	}
}

Sides Tree::Chop(Sides side)
{
	if (side != Sides::None)
	{
		EffectLog* effect = effectLogPool.Take();
		effect->SetOrigin(Origins::BC);
		effect->SetPosition(position);
		effect->Fire({ side == Sides::Right ? -1000.f : 1000.f, -1000.f });
		popEffectPool.Take()->Effect({ position.x, position.y - 20 }, 2, 10);
	}

	Branch* temp = branches.front();
	branches.pop_front();
	temp->SetSide(RandomSide());
	branches.push_back(temp);
	UpdateBranchPos();
	return branches.front()->GetSide();
}


void Tree::UpdateBranchPos()
{
	sf::Vector2f pos = position;
	for (auto branch : branches)
	{
		pos.y -= brachOffsetY;
		branch->SetPosition(pos);
	}
}

