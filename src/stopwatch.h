#pragma once

#include <chrono>

class stopwatch
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> fStart;
	std::chrono::duration<int64_t, std::nano> fElapsed;
public:
	void start();

	void stop();

	int64_t ms();
	int64_t ns();
};

