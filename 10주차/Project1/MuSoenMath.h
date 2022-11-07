#pragma once

class vec3
{
public:
	vec3()
	{
	}
	//���� ���� �� 3���� ���� �־� �ʱ�ȭ�� �� �ִ�
	vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
public:
	//vec3���� ���� ����
	vec3 operator+(vec3 m)
	{
		vec3 result;
		result.x = this->x + m.x;
		result.y = this->y + m.y;
		result.z = this->z + m.z;
		return result;
	}
	vec3 operator-(vec3 m)
	{
		vec3 result;
		result.x = this->x - m.x;
		result.y = this->y - m.y;
		result.z = this->z - m.z;
		return result;
	}
public:
	float x;
	float y;
	float z;
};

class mat3
{
public:
	mat3()
	{

	}
	//��� ���� �� 9���� ���� �־� �ʱ�ȭ�� �� �ִ�
	mat3(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8)
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
public:
	//mat3���� ���� ����
	mat3 operator+(mat3 m)
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
	
	mat3 operator-(mat3 m)
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

	//mat3 �� mat3 �� �������Ѵ�. (������ �������� �� �Ͱ� ������ ������� ���´�)
	mat3 operator*(mat3 mat)
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

	//mat3 �� vec3 �� �������Ѵ�. (������ �������� �� �Ͱ� ������ ������� ���´�)
	vec3 operator*(vec3 vec)
	{
		vec3 result;

		result.x = this->val[0][0] * vec.x + this->val[1][0] * vec.y + this->val[2][0] * vec.z;
		result.y = this->val[0][1] * vec.x + this->val[1][1] * vec.y + this->val[2][1] * vec.z;
		result.z = this->val[0][2] * vec.x + this->val[1][2] * vec.y + this->val[2][2] * vec.z;

	    return result;
	}
public:
	float val[3][3];

};


