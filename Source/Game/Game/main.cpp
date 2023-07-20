#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include <chrono>
#include <vector>
#include <thread>
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

int main()
{
	kiko::MemoryTracker::Initialize();
	std::unique_ptr<int> up = std::make_unique<int>(10);
	//kiko::AudioSystem.AddAudio("Explosion", "Explosion.wav");

	kiko::seedRandom((unsigned int)time(nullptr));
	kiko::setFilePath("assets");
	kiko::g_renderer.Initialize();
	kiko::g_renderer.CreateWindow("CSC190", 800, 800);
	std::vector < kiko::vec2> points{{-10, 5}, { 10,5 }, { 0,-5 }};
	kiko::vec2 v{9, 9};
	kiko::vec2 position{400, 300};
	kiko::Transform transform{ position, 0, 3 };
	float speed = 20;
	constexpr float turnrate = kiko::DegToRad(180);
	kiko::Scene scene;
	unique_ptr<Player> player = make_unique<Player>(200, kiko::pi, kiko::Transform{ {400, 300}, 0, 6 }, kiko::g_manager.Get("ship.txt"));
	player->m_tag = "Player";
	scene.Add(move(player));
	for (int i = 0; i < 1000; i++)
	{
		unique_ptr<Enemy> enemy = make_unique<Enemy>(kiko::randomf(15.0f), kiko::pi, kiko::Transform{ {400, 300}, kiko::randomf(kiko::Twopi), 4 }, kiko::g_manager.Get("ship.txt"));
		enemy->m_tag = "Enemy";
		scene.Add(move(enemy));
	}
	while (true)
	{
		kiko::g_Time.Tick();
		kiko::g_renderer.BeginFrame();
		for (auto point:points)
		{
			kiko::g_renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
			kiko::g_renderer.DrawPoint(point.X, point.Y);
		}
		kiko::vec2 direction;
		scene.Update(kiko::g_Time.GetDeltaTime());
		//if (inputSystem.getkeydown(W)) direction.Y=-1;
		//if (inputSystem.getkeydown(S)) direction.Y=1;
		//if (inputSystem.getkeydown(A)) direction.X=-1;
		//if (inputSystem.getkeydown(D)) direction.X=1;
		position += direction + speed * kiko::g_Time.GetDeltaTime();
		//model.Draw(renderer, transform.position, transform.rotation, transform.scale);
		scene.Draw(kiko::g_renderer);
		kiko::g_renderer.EndFrame();
		//this_thread::sleep_for(chrono::milliseconds(100));
	}
	/*kiko::g_memoryTracker.displayInfo();
	int* p = new int;
	kiko::g_memoryTracker.displayInfo();
	delete p;
	kiko::g_memoryTracker.displayInfo();
	kiko::Time timer;
	for (int i = 0; i < 1000000; i++)
	{
	}
	cout << timer.GetElapsedSeconds() << endl;
	kiko::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		cout << kiko::random(30, 20) << endl;
	}
	cout << kiko::getFilePath() << endl;
	kiko::setFilePath("Assets");
	cout << kiko::getFilePath() << endl;
	size_t size;
	kiko::getFileSize("game.txt", size);
	cout << size << endl;
	string buffer;
	kiko::ReadFile("game.txt", buffer);
	cout << buffer << endl;*/
	return 0;
}
