#include <iostream>
#include "Core/random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <chrono>
using namespace std;

int main()
{
	kiko::g_memoryTracker.displayInfo();
	int* p = new int;
	kiko::g_memoryTracker.displayInfo();
	delete p;
	kiko::g_memoryTracker.displayInfo();
	kiko::Time timer;
	for (int i = 0; i < 1000000; i++)
	{
	}
	cout << timer.GetElapsedSeconds() << endl;
	/*kiko::seedRandom((unsigned int)time(nullptr));
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
}
