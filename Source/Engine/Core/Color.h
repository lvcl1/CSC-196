#pragma once
#include "MathUtils.h"
#include <iostream>
#include<string>
#include <cstdint>
namespace kiko {
	class Color
	{
	public:
		float R, G, B, A;
		Color() :R{ 0 }, G{ 0 }, B{ 0 }, A{ 0 } {};
		Color(float r, float g, float b, float a = 1) :R{ r }, G{ g }, B{ b }, A{ a } {};
		static uint8_t ToInt(float c) { return static_cast<uint8_t>(Clamp(c, 0.0f, 1.0f) * 255); }

	private:

	};

	std::istream& operator >>(std::istream& stream, Color& color) {
		std::string line;
		std::getline(stream, line);
		std::string str = line.substr(line.find('{') + 1, line.find(',') - line.find('{'));
		color.R = std::stof(str);

		line = line.substr(line.find(',') + 1);

		str = line.substr(0, line.find(','));
		color.G = std::stof(str);

		str = line.substr(line.find(',') + 1, line.find('}') - line.find(',') - 1);
		color.B = std::stof(str);

		color.A = 1;

		return stream;
	}
}