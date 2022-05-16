#pragma once
#include <string>
#include "Core/GameObject.h"
#include "Core/ResourceLocator.h"
#include "Keyboard/KeyboardClass.h"

using namespace::std;

// STATE
#define IDLE 0
#define WALKING 2
#define ATTACK 4
#define EATING 6
#define DEATH 8

#define FRAME_TIME 50

class Locust : public GameObject
{
public:
	Locust(string name, double width, double height, Vector pos);

	void Initialize();
	void Update(double delta);
	void Render(Matrix transMat);

private:
	int direction = RIGHT;
	int state = IDLE;
	bool ChangeState(int newState, int newDirection);

	void InitIdleAnimation(); // index 0 1
	void InitWalkingAnimation(); // index 2 3
	void InitAttackAnimation(); // index 4 5
	void InitEatingAnimation(); // index 6 7
	void InitDeathAnimation(); // index 8 9
};

#pragma once
