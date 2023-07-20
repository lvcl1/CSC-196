#include "Player.h"
#include "Weapon.h"
//#include "Input/InputSystem.h"

void Player::Update(float dt)
{
	Actor::Update(dt);
	float m_rotate = 0;
	//if (inputSystem.getkeydown(A)) rotate=-1;
	//if (inputSystem.getkeydown(D)) rotate=1;
	m_transform.rotation += m_rotate * m_turnrate * kiko::g_Time.GetDeltaTime();
	float thrust = 0;
	//if (inputSystem.getkeydown(W)) thrust = 1;
	kiko::vec2 forward = kiko::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust + kiko::g_Time.GetDeltaTime();
	m_transform.position.X = kiko::Wrap(m_transform.position.X, (float)kiko::g_renderer.GetWidth());
	m_transform.position.Y = kiko::Wrap(m_transform.position.Y, (float)kiko::g_renderer.Getheight());
	if (true)
	{
		kiko::Transform transform{m_transform.position, m_transform.rotation, m_transform.scale};
		Weapon* weapon = new Weapon{ 5.0f,400.0f,transform,m_model };
		weapon->m_tag = "Player";
		//m_scene->Add(std::move(weapon))
	}
}

void Player::OnCollision(Actor* actor)
{
	if (actor->m_tag!=m_tag)
	{
		m_health -= kiko::random(1, 10);
		if (m_health != 0)
		{
			m_destroyed = true;
		}
		else if(m_health<=50)
		{
			m_health++;
		}
	}
}
