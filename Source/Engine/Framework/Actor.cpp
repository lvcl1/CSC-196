#include "Actor.h"
namespace kiko {
	void Actor::Update(float dt)
	{
		if (m_lifespan != -1.0f)
		{
			m_lifespan -= dt;
			if (m_lifespan <= 0)
			{
				m_destroyed = true;
			}
		}
		m_transform.position += m_vel * dt;
		m_vel *= std::pow(1.0f - m_damping, dt);
	}
	void Actor::Draw(Renderer& rederer)
	{
		m_model->Draw(rederer, m_transform);
	}

}
