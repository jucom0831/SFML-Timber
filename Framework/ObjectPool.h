#pragma once
#include "Scene.h"
#include "ObjectPoolable.h"
template<typename T>
class ObjectPool
{
public:
	std::list<T*> unused;
	std::list<T*> used;
private:
	bool isObjectPoolable;
	std::queue<T*> haveToErase;
public:
	ObjectPool()
	{
		T temp;
		isObjectPoolable = dynamic_cast<ObjectPoolable*>(&temp) != nullptr;
	}

	~ObjectPool()
	{
	}

	void Init(Scene* scene, T* copy = nullptr, int initSize = 10)
	{
		if (copy)
		{
			for (int i = 0; i < initSize; ++i)
			{
				auto obj = scene->AddGo(new T(*copy));
				obj->Init();
				unused.push_back(obj);
			}
			delete copy;
		}
		else
		{
			for (int i = 0; i < initSize; ++i)
			{
				auto obj = scene->AddGo(new T());
				obj->Init();
				unused.push_back(obj);
			}
		}
	}

	void Update()
	{
		if (isObjectPoolable)
		{
			for (auto obj = used.begin(); obj != used.end();)
			{
				if ((*obj)->IsSatisfiedCondition())
				{
					(*obj)->SetActive(false);
					(*obj)->Reset();
					unused.push_back(*obj);
					used.remove(*obj);
				}
				else
				{
					obj++;
				}
			}
		}

		while (!haveToErase.empty())
		{
			auto find = std::find(used.begin(), used.end(), haveToErase.front());
			unused.push_back(*find);
			used.erase(find);
			haveToErase.pop();
		}
	}

	T* Take()
	{
		if (unused.empty())
		{
			auto obj = SCENE_MGR.GetCurrentScene()->AddGo(new T());
			obj->Init();
			obj->Reset();
			used.push_back(obj);
			return obj;
		}

		auto obj = unused.front();
		unused.pop_front();
		used.push_back(obj);
		//obj->SetActive(true);
		obj->Reset();
		return obj;
	}

	void Return(T* obj)
	{
		auto find = std::find(used.begin(), used.end(), obj);
		if (find == used.end())
		{
			std::cout << "Invaild Obj" << std::endl;
			return;
		}
		obj->SetActive(false);
		obj->Reset();
		haveToErase.push(obj);
	}

	void Reset()
	{
		while (!used.empty())
		{
			auto obj = used.front();
			obj->SetActive(false);
			obj->Reset();
			used.pop_front();
			unused.push_back(obj);
		}
		for (auto& obj : unused)
		{
			obj->SetActive(false);
			obj->Reset();
		}
	}
};