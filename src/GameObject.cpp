#include "GameObject.h"

GameObject::GameObject(const char* name, ObjectType t, bool flag) : Sprite (name, flag)
{
	m_Type = t;
	IsActive = true;
	m_AbilityUsed = false;
}

void GameObject::DoAbility(const CIwFVec2& target, const double dt)
{
	if (m_Type == Elevator)
	{
		if (target != CIwFVec2(0,0)) // if the elevator is down
		{
			// get the difference between the start position and the target and move the elevator up by that amount / X every gameSecond
			if (GetPosition().y >= target.y)
				MoveBy(CIwFVec2(0, -4 * dt), 0);
		}
		else
		{
			if (GetPosition().y < m_startPosition.y)
				MoveBy(CIwFVec2(0, 2 * dt), 0);
		}
	}
}