#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class list
{
	float
		distance = 0;

	float dist(float, float);

public:
	float
		x = -45.12,
		y = 13.103,
		z = -131.103;

	void out();
};


inline float list::dist(const float q, const float w)
{
	distance = abs(w-q);
	return distance;
}

inline void list::out()
{
	cout
		<< endl << R"(Расстояние x:y - )"
		<< dist(x, y)
		<< endl << R"(Расстояние y:z - )"
		<< dist(y, z)
		<< endl << R"(Расстояние x:z - )"
		<< dist(x, z) << endl;
}

