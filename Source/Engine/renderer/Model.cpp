#include "Model.h"
namespace kiko {
	bool Model::Load(const std::string& filename) {
		std::string buffer;
		std::istringstream stream(buffer);
		stream >> m_color;
		std::string line;
		std::getline(stream, line);
		int numpoints = std::stoi(line);
		for (int i = 0; i < numpoints; i++)
		{
			vec2 point;
		}
		return true;
	}
	float Model::GetRad()
	{
		if (m_rad != 0) return m_rad;
		for (auto point: m_points)
		{
			float length = point.langth();
			m_rad = Max(m_rad, length);
		}
		return m_rad;
	}
	void Model::Draw(Renderer& renderer, const vec2& position,float rotation, float scale)
	{
		if (m_points.empty()) return;
		renderer.SetColor(Color::ToInt(m_color.R), Color::ToInt(m_color.G), Color::ToInt(m_color.B), Color::ToInt(m_color.R));
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			vec2 p1 = (m_points[i] * scale).Rotate(rotation) + position;
			vec2 p2 = (m_points[i + 1] * scale).Rotate(rotation) + position;
			renderer.DrawLine(p1.X, p1.Y, p2.X, p2.Y);

		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Draw(renderer, transform.position, transform.rotation, transform.scale);
	}
}