#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	Enemy() = default;
	Enemy(float speed, float turnrate, const kiko::Transform& transform, const kiko::Model& model) :
		Actor{ transform,model },
		m_speed{ speed },
		m_turnrate{ turnrate }
	{}

	void Update(float dt) override;

protected:
	float m_speed = 0;
	float m_turnrate = 0;
};