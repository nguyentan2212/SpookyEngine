#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	double GetMilisecondsElapsed(); // from start to now
	double GetMilisecondsDelta(); // from previous frame to current frame
	void Restart();
	bool Stop();
	bool Start();
private:
	bool isrunning = false;
	double current = 0.0;
#ifdef _WIN32
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> stop;
#else
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> stop;
#endif
};

