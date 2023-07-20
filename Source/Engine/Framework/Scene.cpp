#include "Scene.h"

namespace kiko {
	void Scene::Update(float dt)
	{
		//for (auto& actor : m_actors) actor->Update(dt);
		auto iter = m_actors.begin();
		while (iter != m_actors.end())
		{
			(*iter)->Update(dt);
			((*iter)->m_destroyed) ? m_actors.erase(iter) : iter++;
		}
		for (auto iter1 = m_actors.begin(); iter1 != m_actors.end(); iter1++) {
			for (auto iter2 = std::next(iter1, 1); iter2 != m_actors.end(); iter2++) {
				float dist = (*iter1)->m_transform.position.distance((*iter2)->m_transform.position);
				float rad = (*iter1)->GetRad() + (*iter2)->GetRad();
				if (dist <= rad)
				{
					(*iter1)->OnCollision(iter2->get());
					(*iter2)->OnCollision(iter1->get());
				}
			}
		}
	}
	void Scene::Draw(Renderer& renderer)
	{
		for(auto& actor:m_actors)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}
	void Scene::RemoveAll()
	{
		m_actors.clear();
	}
}
