#include "Particle.h"
namespace kiko {
	void Particle::Update(float dt)
	{
		m_data.lifetimer += dt;
		if (m_data.lifetimer >= m_data.lifetime)
		{
			m_isActive = false;
			return;
		}
		m_data.prevPosition = m_data.position;
		m_data.position += m_data.velocity * dt;
		m_data.velocity *= std::pow(1.0f - m_data.damping, dt);
	}
	void Particle::Draw(Renderer& renderer)
	{
		renderer.SetColor(Color::ToInt(m_data.color.R), Color::ToInt(m_data.color.G), Color::ToInt(m_data.color.B), Color::ToInt(m_data.color.A));
		renderer.DrawLine(m_data.position.X, m_data.position.Y, m_data.prevPosition.X, m_data.prevPosition.Y);
	}
}
