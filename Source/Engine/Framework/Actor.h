#pragma once
#include "Core/Core.h"
#include "renderer/Model.h"
#include <memory>
namespace kiko {
	class Actor
	{
	public:
		Actor() = default;
		Actor(const kiko::Transform& transform, std::shared_ptr<Model> model) :
			m_transform{ transform },
			m_model{ model }
		{}
		Actor(const kiko::Transform& transform) :
			m_transform{ transform }
		{}
		virtual void Update(float dt);
		virtual void Draw(kiko::Renderer& rederer);
		float GetRad() { return (m_model) ? m_model->GetRad() * m_transform.scale : -10000; }
		virtual void OnCollision(Actor* other) {};
		void AddForce(const vec2& force) { m_vel += force; }
		void SetDamping(float damping) { m_damping = damping; }
		class Scene* m_scene = nullptr;
		friend class Scene;
		class Game* m_game = nullptr;

		Transform m_transform;
		std::string m_tag;
	protected:
		bool m_destroyed = false;
		float m_lifespan = -1.0f;
		std::shared_ptr<Model> m_model;
		vec2 m_vel;
		float m_damping = 0;
	};
}