#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name, Scene* scene)
	: name(name), originPreset(Origins::TL), owner(scene)
{

}

void GameObject::SetScene(Scene* scene)
{
	owner = scene;
}

void GameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = { 0.f, 0.f };
}

void GameObject::Init()
{
}

void GameObject::Release()
{
}

void GameObject::Reset()
{
	owner = SCENE_MGR.GetCurrentScene();
}

void GameObject::Update(float dt)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
}
