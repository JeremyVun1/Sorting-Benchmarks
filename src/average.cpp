#include "average.h"

average::average() : fAvg(0), fSize(0) { }

average average::operator+(int num) {
	fSize++;
	fAvg = fAvg + ((num-fAvg) / (fSize));

	return *this;
}

void average::reset() {
	fAvg = 0;
	fSize = 0;
}

int average::avg() {
	return fAvg;
}

int average::size() {
	return fSize;
}
