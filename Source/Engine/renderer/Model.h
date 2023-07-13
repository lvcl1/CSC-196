#pragma once
#include "Core/Core.h"
#include "Renderer.h"
#include <vector>
namespace kiko {
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<vec2>& points) : m_points{ points } {};
		void Draw(Renderer& renderer, const vec2& position, float rotation, float scale);
		void Draw(Renderer& renderer, const Transform& transform);
		bool Load(const std::string& filename);
	private:
		std::vector<vec2> m_points;

	};
}