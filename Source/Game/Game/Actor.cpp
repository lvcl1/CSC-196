#include "Actor.h"

void Actor::Draw(const kiko::Renderer& rederer)
{
	m_model.Draw(rederer, m_transform);
}
