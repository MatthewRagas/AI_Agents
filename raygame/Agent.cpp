#include "Agent.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::update(float deltaTime)
{
	//Set total force to zero
	//for each Behacior in the Behavior list
		//Call the Behavior's update function
		//Add the return value to total force
	//Add total force times delta time to velocity
	//Add velocity times delta time to position
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 20, 20, RED);
}

void Agent::addedBehavior(Behavior * behavior)
{
}
