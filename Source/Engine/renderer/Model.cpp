#include "Model.h"
namespace kiko {
	bool Model::Load(const std::string& filename) {

	}
	void Model::Draw(Renderer& renderer, const vec2& position,float rotation, float scale)
	{
		if (m_points.empty()) return;
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