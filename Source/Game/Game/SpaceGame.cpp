#include "SpaceGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "renderer/Renderer.h"
#include "renderer/Font.h"
#include "Renderer/ModelManager.h"


bool SpaceGame::Init()
{
	//m_font = std::make_shared<kiko::Font>("", 100);

	m_scene = std::make_unique<kiko::Scene>();
	return true;
}

void SpaceGame::Shutdown()
{
}

void SpaceGame::Update(float dt)
{
	switch (m_state)
	{
	case SpaceGame::eState::Title:
		/*if (kiko::input.keydown(space))
		{

		}*/
		m_state = eState::StartGame;
		break;
	case SpaceGame::eState::StartGame:
		m_score = 0;
		m_lives = 3;
		m_state = eState::StartLevel;
		break;
	case SpaceGame::eState::StartLevel:
		m_scene->RemoveAll();
	{
		std::unique_ptr<Player> player = std::make_unique<Player>(20, kiko::pi, kiko::Transform{ {400, 300}, 0, 6 }, kiko::g_manager.Get("ship.txt"));
		player->m_tag = "Player";
		player->m_game = this;
		player->SetDamping(0.9f);
		m_scene->Add(std::move(player));
	}
		m_state = eState::Game;
		break;
	case SpaceGame::eState::Game:
		m_spawnTimer += dt;
		if (m_spawnTimer>=m_spawnTime)
		{
			m_spawnTimer = 0;
			std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(kiko::randomf(), kiko::randomf(), kiko::Transform{ {400, 300}, 0, 6 }, kiko::g_manager.Get("ship.txt"));
			enemy->m_tag = "Enemy";
			enemy->m_game = this;
			m_scene->Add(std::move(enemy));
		}
		break;
	case eState::PlayerDeadStart:
		m_stateTimer = 3;
		m_state = eState::PlayerDead;
		if (m_lives == 0) m_state = eState::Gameover;
		else  m_state = eState::PlayerDead;
		break;
	case SpaceGame::eState::PlayerDead:
		m_stateTimer -= dt;
		if (m_stateTimer <= 0) {
			m_state = eState::StartLevel;
		}
		break;
	case SpaceGame::eState::Gameover:
		m_stateTimer -= dt;
		if (m_stateTimer <= 0) {
			m_scene->RemoveAll();
			m_state = eState::Title;
		}
		break;
	default:
		break;
	}
	//m_scoreText->Create(kiko::g_renderer, std::to_string(m_score), { 1,1,1 }); 
	m_scene->Update(dt);
}

void SpaceGame::Draw(kiko::Renderer& renderer)
{
	if (m_state==eState::Title)
	{
		//m_titleText->Draw(renderer, 400, 300);
	}
	//m_scoreText->Draw(renderer, 40, 30);
	m_scene->Draw(renderer);
}
