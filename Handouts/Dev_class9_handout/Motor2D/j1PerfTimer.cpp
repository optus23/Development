// ----------------------------------------------------
// j1PerfTimer.cpp
// Slow timer with microsecond precision
// ----------------------------------------------------

#include "j1PerfTimer.h"
#include "SDL\include\SDL_timer.h"
#include "j1App.h"

uint64 j1PerfTimer::frequency = 0;

// ---------------------------------------------
j1PerfTimer::j1PerfTimer()
{
	// TODO 2: Fill Constructor, Start(),ReadMs() and ReadTicks() methods
	// they are simple, one line each!
	name.create("time");

	Start();
}

// ---------------------------------------------
void j1PerfTimer::Start()
{
	started_at = SDL_GetPerformanceCounter();// to get the current value of the high resolution counter.
	frequency = SDL_GetPerformanceFrequency(); // to get the count per second of the high resolution counter.;
}

// ---------------------------------------------
double j1PerfTimer::ReadMs() const
{
	

	return  (double)((SDL_GetPerformanceCounter() - started_at) /frequency) * 1000;
}

// ---------------------------------------------
uint64 j1PerfTimer::ReadTicks() const
{
	

	return (SDL_GetPerformanceCounter() - started_at);
}


