#include "MuSoenMath.h"
#include <iostream>

int main()
{
	const double PI = 3.1415926;

	mat3 Translate = mat3	(1, 0, 3,
							0, 1, 5,
							0, 0, 1);

	mat3 Rotate = mat3		(std::cos(30 * PI / 180), std::sin(30 * PI / 180), 0,
							-std::sin(30 * PI / 180), std::cos(30 * PI / 180), 0,
							0, 0, 1);

	mat3 Scale = mat3		(2, 0, 0,
							0, 2, 0,
							0, 0, 1);

	vec3 v(1, 2, 3);

	std::cout << "Rotate\n";
	Rotate.print();

	vec3 p = v * Scale *Rotate *Translate;   // 3,5 �̵� | 30�� ȸ�� | 2�� Ȯ��

	std::cout << "p\n";
	p.print();
	return 0;
}