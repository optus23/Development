// ----------------------------------------------------
// j1Timer.cpp
// Fast timer with milisecons precision
// ----------------------------------------------------

#include "j1Timer.h"
#include "SDL\include\SDL_timer.h"

// ---------------------------------------------
j1Timer::j1Timer()
{
	Start();
}

// ---------------------------------------------
void j1Timer::Start()
{
	// TODO 1: Fill Start(), Read(), ReadSec() methods
	// they are simple, one line each!
	int timer_start = 0;
}

// ---------------------------------------------
uint32 j1Timer::Read() const
{
	int timer_current = SDL_GetTicks();
	return 0;
}

// ---------------------------------------------
float j1Timer::ReadSec() const
{
	float timer_curretsec = SDL_GetTicks();
	return 0.0f;
}