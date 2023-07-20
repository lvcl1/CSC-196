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
	}
	void Actor::Draw(Renderer& rederer)
	{
		m_model->Draw(rederer, m_transform);
	}

}
