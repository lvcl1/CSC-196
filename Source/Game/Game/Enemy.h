#pragma once
#include "Framework/Actor.h"
class Enemy : public kiko::Actor
{
public:
	Enemy() = default;
	Enemy(float speed, float turnrate, const kiko::Transform& transform, std::shared_ptr<kiko::Model> model) :
		Actor{ transform,model },
		m_speed{ speed },
		m_turnrate{ turnrate }
	{
		m_fireTimer = 2.0f;
		m_fireRate = m_fireTimer;
	}

	void Update(float dt) override;
	void OnCollision(Actor* actor) override;

protected:
	float m_speed = 0;
	float m_turnrate = 0;
	float m_fireRate = 0;
	float m_fireTimer = 0;
};