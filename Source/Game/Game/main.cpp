#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Renderer/Font.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include <chrono>
#include <vector>
#include <thread>
#include "SpaceGame.h"
#include "Input/InputSystem.h"
using namespace std;

class Star
{
public:
	Star(const kiko::Vector2& pos, const kiko::Vector2& vel):m_pos{ pos },m_vel{vel}{}
	void Update(int width, int height) {
		m_pos += m_vel * kiko::g_Time.GetDeltaTime();
		if (m_pos.X >= width) m_pos.X = 0;
		if (m_pos.Y >= height) m_pos.Y = 0;
	}

public:
	kiko::Vector2 m_pos;
	kiko::Vector2 m_vel;
};

int main(int argc, char* argv[])
{
	kiko::MemoryTracker::Initialize();
	//kiko::AudioSystem.AddAudio("Explosion", "Explosion.wav");

	kiko::seedRandom((unsigned int)time(nullptr));
	kiko::setFilePath("assets");
	cout << kiko::getFilePath() << endl;

	kiko::g_inputSystem.Initialize();
	kiko::g_renderer.Initialize();
	kiko::g_renderer.CreateWindow("CSC190", 800, 800);

	//std::vector < kiko::vec2> points{{-10, 5}, { 10,5 }, { 0,-5 }};
	kiko::vec2 v{9, 9};
	kiko::vec2 position{400, 300};
	kiko::Transform transform{ position, 0, 3 };
	float speed = 20;
	constexpr float turnrate = kiko::DegToRad(180);
	unique_ptr<SpaceGame> game = make_unique<SpaceGame>();
	game->Init();
	kiko::g_renderer.BeginFrame();
	kiko::Model model;
	model.Load("ship.txt");
	while (true)
	{
		kiko::g_inputSystem.Update();
		kiko::g_Time.Tick();
		model.Draw(kiko::g_renderer, transform);
		kiko::vec2 direction;
		game->Update(kiko::g_Time.GetDeltaTime());
		position += direction + speed * kiko::g_Time.GetDeltaTime();
		//model.Draw(renderer, transform.position, transform.rotation, transform.scale);
		game->Draw(kiko::g_renderer);
		kiko::g_renderer.EndFrame();
	}
	return 0;
}
