#pragma once
#include "Framework/Actor.h"
class Weapon : public kiko::Actor
{
public:
	Weapon() = default;
	Weapon(float speed, float turnrate, const kiko::Transform& transform, std::shared_ptr<kiko::Model> model) :
		Actor{ transform,model },
		m_speed{ speed },
		m_turnrate{ turnrate }
	{}

	void Update(float dt) override;
	void OnCollision(Actor* actor) override;

protected:
	float m_speed = 0;
	float m_turnrate = 0;
};