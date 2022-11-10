#pragma once
#include "MuSoenMath.h"
#include <iostream>

vec3::vec3(){}
vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void vec3::print()
{
	std::cout << "(" << x << "," << y << "," << z << ")\n\n";

}
vec3 vec3::operator+(vec3 m)
{
	vec3 result;
	result.x = this->x + m.x;
	result.y = this->y + m.y;
	result.z = this->z + m.z;
	return result;
}
vec3 vec3::operator-(vec3 m)
{
	vec3 result;
	result.x = this->x - m.x;
	result.y = this->y - m.y;
	result.z = this->z - m.z;
	return result;
}
vec3 vec3::operator*(mat3 m)
{
	vec3 result;

	result.x = m.val[0][0] * this->x + m.val[0][1] * this->y + m.val[0][2] * this->z;
	result.y = m.val[1][0] * this->x + m.val[1][1] * this->y + m.val[1][2] * this->z;
	result.z = m.val[2][0] * this->x + m.val[2][1] * this->y + m.val[2][2] * this->z;

	return result;
}



mat3::mat3()
{

}
//행렬 생성 시 9개의 값을 넣어 초기화할 수 있다
mat3::mat3(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8)
{
	initMatrix(v0, v1, v2, v3, v4, v5, v6, v7, v8);
}
void mat3::initMatrix(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8)
{


	this->val[0][0] = v0;
	this->val[0][1] = v1;
	this->val[0][2] = v2;
	this->val[1][0] = v3;
	this->val[1][1] = v4;
	this->val[1][2] = v5;
	this->val[2][0] = v6;
	this->val[2][1] = v7;
	this->val[2][2] = v8;
}
void mat3::initMatrixIdentity()
{
	initMatrix(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}
void mat3::initMatrixTranspose()
{
	float temp[3][3] = {};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = val[i][j];
		}
	}

	val[0][1] = temp[1][0];
	val[0][2] = temp[2][0];
	val[1][0] = temp[0][1];
	val[1][3] = temp[3][1];
	val[2][0] = temp[0][2];
	val[2][1] = temp[1][2];

}
void mat3::print() 
{
	std::cout << "(";
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			k++;
			std::cout << val[i][j];
			if(k>8)
			{
				std::cout << " ) ";
			}
			else
			{
				std::cout << " , ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

mat3 mat3::operator+(mat3 m)
{
	mat3 result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.val[i][j] = this->val[i][j] + m.val[i][j];
		}
	}
	return result;
}

mat3 mat3::operator-(mat3 m)
{
	mat3 result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.val[i][j] = this->val[i][j] - m.val[i][j];
		}
	}
	return result;
}

mat3 mat3::operator*(mat3 mat)
{
	mat3 result;
	result.val[0][0] = this->val[0][0] * mat.val[0][0] + this->val[1][0] * mat.val[0][1] + this->val[2][0] * mat.val[0][2];
	result.val[0][1] = this->val[0][1] * mat.val[0][0] + this->val[1][1] * mat.val[0][1] + this->val[2][1] * mat.val[0][2];
	result.val[0][2] = this->val[0][2] * mat.val[0][0] + this->val[1][2] * mat.val[0][1] + this->val[2][2] * mat.val[0][2];

	result.val[1][0] = this->val[0][0] * mat.val[1][0] + this->val[1][0] * mat.val[1][1] + this->val[2][0] * mat.val[1][2];
	result.val[1][1] = this->val[0][1] * mat.val[1][0] + this->val[1][1] * mat.val[1][1] + this->val[2][1] * mat.val[1][2];
	result.val[1][2] = this->val[0][2] * mat.val[1][0] + this->val[1][2] * mat.val[1][1] + this->val[2][2] * mat.val[1][2];

	result.val[2][0] = this->val[0][0] * mat.val[2][0] + this->val[1][0] * mat.val[2][1] + this->val[2][0] * mat.val[2][2];
	result.val[2][1] = this->val[0][1] * mat.val[2][0] + this->val[1][1] * mat.val[2][1] + this->val[2][1] * mat.val[2][2];
	result.val[2][2] = this->val[0][2] * mat.val[2][0] + this->val[1][2] * mat.val[2][1] + this->val[2][2] * mat.val[2][2];

	return result;

}

vec3 mat3::operator*(vec3 vec)
{
	vec3 result;

	result.x = this->val[0][0] * vec.x + this->val[1][0] * vec.y + this->val[2][0] * vec.z;
	result.y = this->val[0][1] * vec.x + this->val[1][1] * vec.y + this->val[2][1] * vec.z;
	result.z = this->val[0][2] * vec.x + this->val[1][2] * vec.y + this->val[2][2] * vec.z;

	return result;
}

