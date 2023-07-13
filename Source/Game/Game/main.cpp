#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Enemy.h"
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
	kiko::seedRandom((unsigned int)time(nullptr));
	kiko::g_renderer.Initialize();
	kiko::g_renderer.CreateWindow("CSC190", 800, 800);
	std::vector < kiko::vec2> points{{-10, 5}, { 10,5 }, { 0,-5 }};
	kiko::Model model{points};
	kiko::vec2 v{9, 9};
	kiko::vec2 position{400, 300};
	kiko::Transform transform{ position, 0, 3 };
	float speed = 20;
	float turnrate = kiko::DegToRad(180);
	/*for (int i = 0; i < 1000; i++)
	{
		points.push_back(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.Getheight())));
	}*/
	Player player{ 200,kiko::pi, {{400,300},0,6},model };
	std::vector<Enemy> enemies;
	for (int i = 0; i < 1000; i++)
	{
		Enemy enemy{ 300,kiko::pi, {{400,300},kiko::randomf(kiko::Twopi),4},model };
		enemies.push_back(enemy);
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
		player.Update(kiko::g_Time.GetDeltaTime());
		for (auto& enemy : enemies) enemy.Update(kiko::g_Time.GetDeltaTime());
		//if (inputSystem.getkeydown(W)) direction.Y=-1;
		//if (inputSystem.getkeydown(S)) direction.Y=1;
		//if (inputSystem.getkeydown(A)) direction.X=-1;
		//if (inputSystem.getkeydown(D)) direction.X=1;
		position += direction + speed * kiko::g_Time.GetDeltaTime();
		//model.Draw(renderer, transform.position, transform.rotation, transform.scale);
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
