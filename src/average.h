#pragma once
class average
{
private:
	int fAvg;
	int fSize;
public:
	average();

	average operator+(int n);

	int avg();

	int size();

	void reset();
};

