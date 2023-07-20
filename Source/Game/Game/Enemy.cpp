#include "Enemy.h"
#include "Player.h"
#include "Weapon.h"
#include "Framework/Scene.h"
#include "renderer/Renderer.h"

void Enemy::Update(float dt)
{
	Actor::Update(dt);
	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		kiko::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.angle() + kiko::halfpi;
	}
	kiko::vec2 forward = kiko::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * kiko::g_Time.GetDeltaTime();
	m_transform.position.X = kiko::Wrap(m_transform.position.X, (float)kiko::g_renderer.GetWidth());
	m_transform.position.Y = kiko::Wrap(m_transform.position.Y, (float)kiko::g_renderer.Getheight());
	m_fireRate - dt;
	if (m_fireRate<=0)
	{
		kiko::Transform transform{m_transform.position, m_transform.rotation, m_transform.scale};
		Weapon* weapon = new Weapon{ 5.0f,400.0f,transform,m_model };
		m_fireRate = m_fireTimer;
	}
}

void Enemy::OnCollision(Actor* actor)
{
	//Player* p = dynamic_cast<Player>(actor);
	if (actor->m_tag != m_tag)
	{
		m_destroyed = true;
	}
}
