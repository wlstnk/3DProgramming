#pragma once

class mat3;

class vec3
{
public:
	vec3();								//���� ���� �� 3���� ���� �־� �ʱ�ȭ�� �� �ִ�
	vec3(float x, float y, float z);
public:
	void print();
public:
	vec3 operator+(vec3 m);				//vec3���� ���� ����
	vec3 operator-(vec3 m);
	vec3 operator*(mat3 m);
public:
	float x;
	float y;
	float z;
};



class mat3
{
public:
	mat3();				//��� ���� �� 9���� ���� �־� �ʱ�ȭ�� �� �ִ�
	mat3(float v0, float v1, float v2,float v3, float v4, float v5,float v6, float v7, float v8);
public:
	void initMatrix(float v0, float v1, float v2,float v3, float v4, float v5,float v6, float v7, float v8);
	void initMatrixIdentity();
	void initMatrixTranspose();
	void print();
public:
	//mat3���� ���� ����
	mat3 operator+(mat3 m);
	mat3 operator-(mat3 m);
	mat3 operator*(mat3 mat); //mat3 �� mat3 �� �������Ѵ�. (������ �������� �� �Ͱ� ������ ������� ���´�)
	vec3 operator*(vec3 vec); //mat3 �� vec3 �� �������Ѵ�. (������ �������� �� �Ͱ� ������ ������� ���´�)
public:
	float val[3][3];

};

