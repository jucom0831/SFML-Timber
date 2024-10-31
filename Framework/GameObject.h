#pragma once

class Scene;
class GameObject
{
protected:
	std::string name;
	
	bool active = true;
	bool active2 = true;

	sf::Vector2f position;
	sf::Vector2f scale;

	Origins originPreset;
	sf::Vector2f origin;
	Scene* owner;

public:
	SortingLayers sortingLayer = SortingLayers::Default;
	int sortingOrder = 0;

	GameObject(const std::string& name = "", Scene* scene=nullptr);
	virtual ~GameObject() = default;

	void SetScene(Scene* scene);

	const std::string& GetName() const { return name; }
	void SetName(const std::string& n) { name = n; }

	bool IsActive() const { return active; }
	void SetActive(bool a) { active = a; }
	bool IsActive2() const { return active2; }
	void SetActive2(bool b) { active2 = b; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetScale() const { return scale; }
	virtual void SetScale(const sf::Vector2f& scale) { this->scale = scale; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		origin = newOrigin;
		originPreset = Origins::Custom;
	}

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};

struct DrawOrderComparer
{
	bool operator()(GameObject* a, GameObject* b) const
	{
		if (a->sortingLayer != b->sortingLayer)
			return a->sortingLayer > b->sortingLayer;
		return a->sortingOrder > b->sortingOrder;
	}
};

