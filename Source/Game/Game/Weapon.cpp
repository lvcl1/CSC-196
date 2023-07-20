#include "Weapon.h"

void Weapon::Update(float dt)
{
	Actor::Update(dt);
	kiko::vec2 forward = kiko::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * kiko::g_Time.GetDeltaTime();
	m_transform.position.X = kiko::Wrap(m_transform.position.X, (float)kiko::g_renderer.GetWidth());
	m_transform.position.Y = kiko::Wrap(m_transform.position.Y, (float)kiko::g_renderer.Getheight());
}

void Weapon::OnCollision(Actor* actor)
{
	if (actor->m_tag != m_tag)
	{
		m_destroyed = true;
	}
}
