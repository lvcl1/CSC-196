#include "Player.h"
#include "Weapon.h"
#include "SpaceGame.h"
#include "Input/InputSystem.h"

void Player::Update(float dt)
{
	/*kiko::InputSystem inputSystem;
	inputSystem.Initialize();*/
	Actor::Update(dt);
	float m_rotate = 0;
	if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) m_rotate=-1;
	if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) m_rotate=1;
	m_transform.rotation += m_rotate * m_turnrate * kiko::g_Time.GetDeltaTime();
	float thrust = 0;
	if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
	kiko::vec2 forward = kiko::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	AddForce(forward * m_speed * thrust);
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
	
	if(kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_T))kiko::g_Time.SetTimeScale(.5f);
	else kiko::g_Time.SetTimeScale(1.0f);
}

void Player::OnCollision(Actor* actor)
{
	if (actor->m_tag!=m_tag)
	{
		m_health -= kiko::random(1, 10);
		if (m_health != 0)
		{
			m_game->SetLives(m_game->GetLives() - 1);
			m_destroyed = true;
			dynamic_cast<SpaceGame*>(m_game)->SetState(SpaceGame::eState::PlayerDeadStart);
		}
	}
}
