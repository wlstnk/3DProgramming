#include "MuSoenMath.h"
#include <iostream>

int main()
{
	const double PI = 3.1415926;

	/*mat3 Translate = mat3	(1, 0, 3,
							0, 1, 5,
							0, 0, 1);

	mat3 Rotate = mat3		(std::cos(30 * PI / 180), std::sin(30 * PI / 180), 0,
							-std::sin(30 * PI / 180), std::cos(30 * PI / 180), 0,
							0, 0, 1);
	mat3 Scale = mat3(3, 0, 0,
		0, 2, 0,
		0, 0, 1);


	mat3 Translate_ = mat3(1, 0, 0,
		0, 1, 0,
		3, 5, 1);
	mat3 Rotate_ = mat3(std::cos(30 * PI / 180), -std::sin(30 * PI / 180), 0,
		std::sin(30 * PI / 180), std::cos(30 * PI / 180), 0,
		0, 0, 1);
	mat3 Scale_ = mat3(3, 0, 0,
		0, 2, 0,
		0, 0, 1);*/

	vec3 a(1, 2, 3);

	vec3 a2(2, 3, 4);

	mat3 b(	1, 2, 3,
			3, 4, 2,
			7, 6, 12);

	mat3 c(2, 67, 3,
		1, 2, 24,
		42, 4, 8);



	vec3 result = a * b * c;
	//result = math::AddVector(a,b);

	result.print();

	return 0;
}