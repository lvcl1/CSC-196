#include <iostream>
#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
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
	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC190", 800, 800);
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
	while (true)
	{
		kiko::g_Time.Tick();
		renderer.BeginFrame();
		for (auto point:points)
		{
			renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
			renderer.DrawPoint(point.X, point.Y);
		}
		float rotate = 0;
		//if (inputSystem.getkeydown(A)) rotate=-1;
		//if (inputSystem.getkeydown(D)) rotate=1;
		transform.rotation += rotate * turnrate * kiko::g_Time.GetDeltaTime();
		float thrust = 0;
		//if (inputSystem.getkeydown(W)) thrust = 1;
		kiko::vec2 forward = kiko::vec2{ 0,-1 }.Rotate(transform.rotation);
		transform.position += forward * speed * thrust + kiko::g_Time.GetDeltaTime();
		transform.position.X = kiko::Wrap(transform.position.X, renderer.GetWidth());
		transform.position.Y = kiko::Wrap(transform.position.Y, renderer.Getheight());
		kiko::vec2 direction;
		//if (inputSystem.getkeydown(W)) direction.Y=-1;
		//if (inputSystem.getkeydown(S)) direction.Y=1;
		//if (inputSystem.getkeydown(A)) direction.X=-1;
		//if (inputSystem.getkeydown(D)) direction.X=1;
		position += direction + speed * kiko::g_Time.GetDeltaTime();
		model.Draw(renderer, transform.position, transform.rotation, transform.scale);
		renderer.EndFrame();
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
