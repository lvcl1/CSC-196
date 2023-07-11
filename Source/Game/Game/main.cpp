#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include <chrono>
#include <vector>
using namespace std;

class Star
{
public:
	Star(const kiko::Vector2& pos, const kiko::Vector2& vel):m_pos{ pos },m_vel{vel}{}
	void Update() {
		m_pos += m_vel;
	}

public:
	kiko::Vector2 m_pos;
	kiko::Vector2 m_vel;
};

int main()
{
	kiko::seedRandom((unsigned int)time(nullptr));
	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC190", 800, 800);
	std::vector < kiko::vec2> points{{-10, 5}, { 10,5 }, { 0,-5 }};
	kiko::Model model{points};
	kiko::vec2 v{9, 9};

	/*for (int i = 0; i < 1000; i++)
	{
		points.push_back(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.Getheight())));
	}*/
	while (true)
	{
		renderer.BeginFrame();
		for (auto point:points)
		{
			renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
			renderer.DrawPoint(point.X, point.Y);
		}
		//model.Draw(renderer,0,2);
		//renderer.EndFrame();
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
