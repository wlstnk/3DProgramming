#include "MuSoenMath.h"
#include <iostream>

int main()
{
	const double PI = 3.1415926;

	mat3 Translate = mat3	(1, 0, 0,
							0, 1, 0,
							3, 5, 1);

	mat3 Rotate = mat3		(std::cos(30 * PI / 180), -std::sin(30 * PI / 180), 0,
							std::sin(30 * PI / 180), std::cos(30 * PI / 180), 0,
							0, 0, 1);

	mat3 Scale = mat3		(2, 0, 0,
							0, 2, 0,
							0, 0, 1);

	vec3 v(1, 2, 3);

	vec3 p = Translate * Rotate * Scale * v;   // 3,5 이동 | 30도 회전 | 2배 확대

	std::cout << p.x << " , " << p.y << " , " << p.z << "\n";
	return 0;
}