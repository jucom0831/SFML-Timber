#include "stdafx.h"
#include "Tree2.h"
#include "Branch2.h"
#include "EffectLog2.h"
#include "Scene.h"

Tree2::Tree2(const std::string& name)
	: GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = -1;
}

Tree2::~Tree2()
{
	Release();
}

Sides Tree2::RandomSide() const
{
	int rand = Utils::RandomRange(0, 2);
	if (rand > 1)
		return Sides::None;
	return (Sides)rand;
}

void Tree2::Init()
{
	Release();

	tree2.setTexture(TEXTURE_MGR.Get(treeTexId), true);
	Utils::SetOrigin(tree2, Origins::BC);

	sf::Vector2f orginBranch2;
	orginBranch2.x = tree2.getLocalBounds().width * -0.5f;
	sf::Texture& branchTex = TEXTURE_MGR.Get(branchTexId);
	orginBranch2.y = branchTex.getSize().y * 0.5f;


	for (int i = 0; i < branchCount; ++i)
	{
		Branch2* branch = new Branch2(branchTexId);
		branch->SetOrigin(orginBranch2);
		branch->Init();
		branch->SetSide(RandomSide());
		branches2.push_back(branch);
	}
}

void Tree2::Release()
{
	for (auto logEffect : logEffects)
	{
		effectLogPool.Return(logEffect);
		SCENE_MGR.GetCurrentScene()->RemoveGo(logEffect);
	}
	logEffects.clear();

	for (auto branch : branches2)
	{
		branch->Release();
		delete branch;
	}
	branches2.clear();
}


void Tree2::Reset()
{
	tree2.setTexture(TEXTURE_MGR.Get(treeTexId), true);
	for (auto branch : branches2)
	{
		branch->Reset();
	}
	UpdateBranchPos2();
	auto lastBranch = branches2.front();
	lastBranch->SetSide(Sides::None);
}

void Tree2::Update(float dt)
{

		for (auto branch : branches2)
		{
			branch->Update(dt);
		}

		auto it = logEffects.begin();
		while (it != logEffects.end())
		{
			auto logEffect = *it;
			if (!logEffect->IsActive())
			{
				effectLogPool.Return(logEffect);
				SCENE_MGR.GetCurrentScene()->RemoveGo(logEffect);
				it = logEffects.erase(it);
			}
			else
			{
				++it;
			}
		}
}

void Tree2::Draw(sf::RenderWindow& window)
{
	window.draw(tree2);
	for (auto branch : branches2)
	{
		if (branch->IsActive())
		{
			branch->Draw(window);
		}
	}
}

void Tree2::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	tree2.setPosition(position);
	UpdateBranchPos2();
}

void Tree2::ClearEffectLog()
{
	for (auto log : logEffects)
	{
		SCENE_MGR.GetCurrentScene()->RemoveGo(log);
		effectLogPool.Return(log);
	}
	logEffects.clear();
}

Sides Tree2::Chop2(Sides side)
{
	if (side != Sides::None)
	{
		EffectLog2* effect2 = effectLogPool.Take();
		SCENE_MGR.GetCurrentScene()->AddGo(effect2);
		effect2->SetOrigin(Origins::BC);
		effect2->SetPosition(position);
		effect2->Fire({ side == Sides::Right ? -1000.f : 1000.f, -1000.f });
		logEffects.push_back(effect2);
	}

	Branch2* temp = branches2.front();
	branches2.pop_front();
	temp->SetSide(RandomSide());
	branches2.push_back(temp);
	UpdateBranchPos2();
	return branches2.front()->GetSide();
}


void Tree2::UpdateBranchPos2()
{

		sf::Vector2f pos = position;
		for (auto branch2 : branches2)
		{
			pos.y -= brachOffsetY;
			branch2->SetPosition(pos);
		}
	
}

