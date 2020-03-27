#pragma once
#include "Condition.h"

class State;
class Agent;

class Transition
{
public:
	Transition(State* target, Condition* condition) : m_target(target), m_condition(condition) {}
	~Transition();
};

