#pragma once
#include "GameObject.h"
#include "EffectLog2.h"

class Branch2;

class Tree2 : public GameObject
{
protected:
	sf::Sprite tree2;
	std::list<Branch2*> branches2;

	int branchCount = 6;
	std::string treeTexId = "graphics/tree.png";
	std::string branchTexId = "graphics/branch.png";

	float brachOffsetY = 150.f;

	ObjectPool<EffectLog2> effectLogPool;
	std::list<EffectLog2*> logEffects;

public:
	Tree2(const std::string& name = "");
	~Tree2();

	Sides RandomSide() const;
	Sides Chop2(Sides side);

	void UpdateBranchPos2();

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos) override;

	void ClearEffectLog();
};

