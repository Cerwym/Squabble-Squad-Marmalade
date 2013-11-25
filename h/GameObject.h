#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "sprite.h"

enum ObjectType {Elevator, Button, Door, Terminal, Scenerary, Exit};

class GameObject : public Sprite
{
public:
	GameObject(const char* name, ObjectType t, bool collisionFlag);

	void AddChildObject(GameObject* obj) {m_Child = obj;}
	void AddTag(std::string tag) {m_Tag = tag;}
	void SetStartPosition(CIwFVec2& pos) {if (m_Type == Elevator) m_startPosition = pos;}
	void DoAbility(const CIwFVec2& target, const double dt);
	bool HasBeenUsed(){return m_AbilityUsed;}
	GameObject* Child(){return m_Child;}
	ObjectType GetType(){return m_Type;}

	bool IsActive;
private:
	ObjectType m_Type;

	void Raise();
	void Lower();

	bool m_AbilityUsed;
	
	// Pointer to the child object, so one object can be 'attached' to another
	GameObject* m_Child;
	CIwFVec2 m_startPosition;
	std::string m_Tag;
};

#endif