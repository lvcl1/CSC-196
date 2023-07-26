#pragma once
#include "Framework/Game.h"
#include "renderer/Font.h"
//#include "renderer/text.h"
class SpaceGame : public kiko::Game
{
public:
	enum class eState
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDeadStart,
		PlayerDead,
		GameoverStart,
		Gameover
	};

	virtual bool Init() override;

	virtual void Shutdown() override;

	virtual void Update(float dt) override;

	virtual void Draw(kiko::Renderer& renderer) override;
	void SetState(eState state) { m_state = state; }

private:
	eState m_state = eState::Title;
	float m_spawnTimer = 0;
	float m_spawnTime = 3;
	float m_stateTimer = 0;
	std::shared_ptr<kiko::Font> m_font;
	//std::shared_ptr<kiko::Text> m_scoretext;
	//std::shared_ptr<kiko::Text> m_titletext;
	//std::shared_ptr<kiko::Text> m_gameovertext;
};