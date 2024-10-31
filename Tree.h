#pragma once
#include "GameObject.h"
#include "EffectLog.h"
#include "ParticleEffect.h"


class Branch;
class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	std::list<Branch*> branches;

	int branchCount = 6;
	std::string treeTexId = "graphics/tree.png";
	std::string branchTexId = "graphics/branch.png";

	float brachOffsetY = 150.f;
	ObjectPool<EffectLog> effectLogPool;
	ObjectPool<ParticleEffect> popEffectPool;

public:
	Tree(const std::string& name = "");
	~Tree();

	Sides RandomSide() const;
	Sides Chop(Sides side);

	void UpdateBranchPos();

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& treescale);

};

