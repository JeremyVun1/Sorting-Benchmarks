#include "stopwatch.h"

void stopwatch::start()
{
	fStart = std::chrono::high_resolution_clock::now();
}

void stopwatch::stop()
{
	auto end = std::chrono::high_resolution_clock::now();
	fElapsed = end - fStart;
}

int64_t stopwatch::ms() {
	return (fElapsed.count() / 1000000.0);
}

int64_t stopwatch::ns() {
	return fElapsed.count();
}
