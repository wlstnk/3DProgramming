#pragma once

class mat3;

class vec3
{
public:
	vec3();								//벡터 생성 시 3개의 값을 넣어 초기화할 수 있다
	vec3(float x, float y, float z);
public:
	void print();
public:
	vec3 operator+(vec3 m);				//vec3간의 덧셈 뺄셈
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
	mat3();				//행렬 생성 시 9개의 값을 넣어 초기화할 수 있다
	mat3(float v0, float v1, float v2,float v3, float v4, float v5,float v6, float v7, float v8);
public:
	void initMatrix(float v0, float v1, float v2,float v3, float v4, float v5,float v6, float v7, float v8);
	void initMatrixIdentity();
	void initMatrixTranspose();
	void print();
public:
	//mat3간의 덧셈 뺄셈
	mat3 operator+(mat3 m);
	mat3 operator-(mat3 m);
	mat3 operator*(mat3 mat); //mat3 를 mat3 와 곱연산한다. (연산은 역순으로 한 것과 동일한 결과값이 나온다)
	vec3 operator*(vec3 vec); //mat3 를 vec3 와 곱연산한다. (연산은 역순으로 한 것과 동일한 결과값이 나온다)
public:
	float val[3][3];

};

