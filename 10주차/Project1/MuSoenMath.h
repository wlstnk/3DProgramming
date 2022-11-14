#pragma once
#include <iostream>

//Class List
template <typename T, int S> class vec;
template <typename T, int S> class mat;
template <typename T, int S> class vec_vertical;
class math;

//Class Def
typedef vec<float, 1> vec1;
typedef vec<float, 2> vec2;
typedef vec<float, 3> vec3;
typedef vec<float, 4> vec4;

typedef vec_vertical<float, 1> vec1x1;
typedef vec_vertical<float, 2> vec1x2;
typedef vec_vertical<float, 3> vec1x3;
typedef vec_vertical<float, 4> vec1x4;

typedef mat<float, 1> mat1;
typedef mat<float, 2> mat2;
typedef mat<float, 3> mat3;
typedef mat<float, 4> mat4;

//Class
template <typename T, int S>
class vec
{
public:
	vec()
	{
		for (int i = 0; i < S; i++)
		{
			val[i] = 0;
		}
	}
	vec(T input1, T input2 = 0, T input3 = 0, T input4 = 0)
	{
		T input[4] = { input1, input2, input3, input4 };
		for (int i = 0; i < S; i++)
		{
			val[i] = input[i];
		}
	}
	~vec(){}
public:
	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < S; i++)
		{
			std::cout << val[i] << " ";
		}
		std::cout << ")\n\n";
	}
public:
	vec operator+(vec v)
	{
		return math::Add(*this, v);
	}
	vec operator-(vec v)
	{
		return math::Subtract(*this, v);
	}
	vec operator*(T s)
	{
		return math::Multiply(*this, s);
	}
	vec operator*(mat<T, S> m)
	{
		return math::Multiply(*this, m);
	}
	vec operator/(T s)
	{
		return math::Devide(*this, s);
	}

public:
	T x() { return val[0]; }
	T y() { return val[1]; }
	T z() { return val[2]; }
	T w() { return val[3]; }

public:
	T val[S];
};



template <typename T, int S>
class vec_vertical
{
public:
	vec_vertical()
	{
		for (int i = 0; i < S; i++)
		{
			val[i] = 0;
		}
	}
	vec_vertical(T input1, T input2 = 0, T input3 = 0, T input4 = 0)
	{
		T input[4] = { input1, input2, input3, input4 };
		for (int i = 0; i < S; i++)
		{
			val[i] = input[i];
		}
	}
public:
	void print()
	{
		std::cout << "(";
		for (int i = 0; i < S; i++)
		{
			std::cout << val[i];
			if(i<S-1)
			{
				std::cout <<"\n";
			}
		}
		std::cout << ")\n";
	}
public:
	vec_vertical operator+(vec_vertical v)
	{
		return math::Add(*this, v);
	}
	vec_vertical operator-(vec_vertical v)
	{
		return math::Subtract(*this, v);
	}
	vec_vertical operator*(T s)
	{
		return math::Multiply(*this, s);
	}
	vec_vertical operator*(mat<T, S> m)
	{
		return math::Multiply(*this, m);
	}
	vec_vertical operator/(T s)
	{
		return math::Devide(*this, s);
	}

public:
	T x() { return val[0]; }
	T y() { return val[1]; }
	T z() { return val[2]; }
	T w() { return val[3]; }
public:
	T val[S];
};


template <typename T, int S>
class mat
{
public:
	mat()
	{
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				val[i][j] = 0;
			}
		}
	}
	mat(T input1, T input2 = 0, T input3 = 0, T input4 = 0,
		T input5 = 0, T input6 = 0, T input7 = 0, T input8 = 0,
		T input9 = 0, T input10 = 0, T input11 = 0, T input12 = 0,
		T input13 = 0, T input14 = 0, T input15 = 0, T input16 = 0)
	{
		Init(input1, input2, input3, input4,
			input5, input6, input7, input8,
			input9, input10, input11, input12,
			input13, input14, input15, input16);
	}
public:
	void Init(T input1, T input2 = 0, T input3 = 0, T input4 = 0,
		T input5 = 0, T input6 = 0, T input7 = 0, T input8 = 0,
		T input9 = 0, T input10 = 0, T input11 = 0, T input12 = 0,
		T input13 = 0, T input14 = 0, T input15 = 0, T input16 = 0)
	{
		T input[16] = { input1, input2, input3, input4,
			input5, input6, input7, input8,
			input9, input10, input11, input12,
			input13, input14, input15, input16 };

		int index = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				val[i][j] = input[index];
				index++;
			}
		}
	}
	void InitIdentityMatrix()
	{
		Init(0,0,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0);

		for (int i = 0; i < S; i++)
		{
			val[i][i] = 1;
		}
	}
	void Transpose()
	{
		T temp[S][S];
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				temp[i][j] = val[i][j];
			}
		}


		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				val[i][j] = temp[j][i];
			}
		}
	}
	void print() 
	{
		std::cout << "(";
		int k = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				k++;
				std::cout << val[i][j];
				std::cout << " ";
			}
			if(i<S-1){
				std::cout << "\n";
			}
		}
		std::cout << ")\n";
	}
public:
	mat operator+(mat m)
	{
		return math::Add(*this, m);
	}
	mat operator-(mat m)
	{
		return math::Subtract(*this, m);
	}
	mat operator*(mat m)
	{
		return math::Multiply(*this, m);
	}
	mat operator*(vec<T,S> v)
	{
		return math::Multiply(*this, v);
	}
	mat operator*(vec_vertical<T, S> v)
	{
		return math::Multiply(*this, v);
	}

public:
	T val[S][S];

};


class math
{
public:
	math();

private:
	//Add
	template <typename T, int S>
	static vec<T, S> Add_(vec<T, S> v, vec<T, S> add_vec)
	{
		vec<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] + add_vec.val[i];
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Add_(vec_vertical<T, S> v, vec_vertical<T, S> add_vec)
	{
		vec_vertical<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] + add_vec.val[i];
		}
		return result;
	}

	template <typename T, int S>
	static mat<T, S> Add_(mat<T, S> m, mat<T, S> add_mat)
	{
		mat<T, S> result;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				result.val[j][i] = m.val[j][i] + add_mat.val[j][i];
			}
		}
		return result;
	}

	//Subtract
	template <typename T, int S>
	static vec<T, S> Subtract_(vec<T, S> v, vec<T, S> subtract_vec)
	{
		vec<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] - subtract_vec.val[i];
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Subtract_(vec_vertical<T, S> v, vec_vertical<T, S> add_vec)
	{
		vec_vertical<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] - add_vec.val[i];
		}
		return result;
	}

	template <typename T, int S>
	static mat<T, S> Subtract_(mat<T, S> m, mat<T, S> subtract_mat)
	{
		mat<T, S> result;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				result.val[j][i] = m.val[j][i] - subtract_mat.val[j][i];
			}
		}
		return result;
	}

	//Multiply
	template <typename T, int S>
	static vec<T, S> Multiply_(vec<T, S> v, T scalar)
	{
		vec<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] * scalar;
		}
		return result;
	}

	template <typename T, int S>
	static vec<T, S> Multiply_(vec<T, S> v, mat<T, S> m)
	{
		vec<T, S> result;
		T temp = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				temp += v.val[j] * m.val[j][i];
			}
			result.val[i] = temp;
			temp = 0;
		}
		return result;
	}

	template <typename T, int S>
	static vec<T, S> Multiply_(mat<T, S> m, vec<T, S> v)
	{
		vec<T, S> result;
		T temp = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				temp += m.val[i][j] * v.val[j] ;
			}
			result.val[i] = temp;
			temp = 0;
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Multiply_(vec_vertical<T, S> v, T scalar)
	{
		vec_vertical<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] * scalar;
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Multiply_(vec_vertical<T, S> v, mat<T, S> m)
	{
		vec_vertical<T, S> result;
		T temp = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				temp += v.val[j] *m.val[i][j] ;
			}
			result.val[i] = temp;
			temp = 0;
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Multiply_(mat<T, S> m, vec_vertical<T, S> v)
	{
		vec_vertical<T, S> result;
		T temp = 0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				temp += m.val[j][i] * v.val[j];
			}
			result.val[i] = temp;
			temp = 0;
		}
		return result;
	}

	template <typename T, int S>
	static mat<T, S> Multiply_(mat<T, S> v, mat<T, S> m)
	{
		mat<T, S> result;
		T temp = 0;
		int k=0;
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				for (int k = 0; k < S; k++)
				{
					temp += v.val[i][k] * m.val[k][j];
				}
				result.val[i][j] = temp;
				temp = 0;
			}
		}
		return result;
	}



	//Devide
	template <typename T, int S>
	static vec<T, S> Devide_(vec<T, S> v, T scalar)
	{
		vec<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] / scalar;
		}
		return result;
	}

	template <typename T, int S>
	static vec_vertical<T, S> Devide_(vec_vertical<T, S> v, T scalar)
	{
		vec_vertical<T, S> result;
		for (int i = 0; i < S; i++)
		{
			result.val[i] = v.val[i] / scalar;
		}
		return result;
	}

public:
	//Add
	static vec1 Add(vec1 v, vec1 add_vec) { return Add_<float, 1>(v, add_vec); }
	static vec2 Add(vec2 v, vec2 add_vec) { return Add_<float, 2>(v, add_vec); }
	static vec3 Add(vec3 v, vec3 add_vec) { return Add_<float, 3>(v, add_vec); }
	static vec4 Add(vec4 v, vec4 add_vec) { return Add_<float, 4>(v, add_vec); }

	static vec1x1 Add(vec1x1 v, vec1x1 add_vec) { return Add_<float, 1>(v, add_vec); }
	static vec1x2 Add(vec1x2 v, vec1x2 add_vec) { return Add_<float, 2>(v, add_vec); }
	static vec1x3 Add(vec1x3 v, vec1x3 add_vec) { return Add_<float, 3>(v, add_vec); }
	static vec1x4 Add(vec1x4 v, vec1x4 add_vec) { return Add_<float, 4>(v, add_vec); }

	static mat1 Add(mat1 m, mat1 add_mat) { return Add_<float, 1>(m, add_mat); }
	static mat2 Add(mat2 m, mat2 add_mat) { return Add_<float, 2>(m, add_mat); }
	static mat3 Add(mat3 m, mat3 add_mat) { return Add_<float, 3>(m, add_mat); }
	static mat4 Add(mat4 m, mat4 add_mat) { return Add_<float, 4>(m, add_mat); }

	//Subtract
	static vec1 Subtract(vec1 v, vec1 subtract_vec){ return Subtract_<float, 1>(v, subtract_vec); }
	static vec2 Subtract(vec2 v, vec2 subtract_vec){ return Subtract_<float, 2>(v, subtract_vec); }
	static vec3 Subtract(vec3 v, vec3 subtract_vec){ return Subtract_<float, 3>(v, subtract_vec); }
	static vec4 Subtract(vec4 v, vec4 subtract_vec){ return Subtract_<float, 4>(v, subtract_vec); }

	static vec1x1 Subtract(vec1x1 v, vec1x1 subtract_vec) { return Subtract_<float, 1>(v, subtract_vec); }
	static vec1x2 Subtract(vec1x2 v, vec1x2 subtract_vec) { return Subtract_<float, 2>(v, subtract_vec); }
	static vec1x3 Subtract(vec1x3 v, vec1x3 subtract_vec) { return Subtract_<float, 3>(v, subtract_vec); }
	static vec1x4 Subtract(vec1x4 v, vec1x4 subtract_vec) { return Subtract_<float, 4>(v, subtract_vec); }

	static mat1 Subtract(mat1 m, mat1 subtract_mat) { return Subtract_<float, 1>(m, subtract_mat); }
	static mat2 Subtract(mat2 m, mat2 subtract_mat) { return Subtract_<float, 2>(m, subtract_mat); }
	static mat3 Subtract(mat3 m, mat3 subtract_mat) { return Subtract_<float, 3>(m, subtract_mat); }
	static mat4 Subtract(mat4 m, mat4 subtract_mat) { return Subtract_<float, 4>(m, subtract_mat); }

	//Multiply
	static vec1 Multiply(vec1 v, float scalar){ return Multiply_<float, 1>(v, scalar); }
	static vec2 Multiply(vec2 v, float scalar){ return Multiply_<float, 2>(v, scalar); }
	static vec3 Multiply(vec3 v, float scalar){ return Multiply_<float, 3>(v, scalar); }
	static vec4 Multiply(vec4 v, float scalar){ return Multiply_<float, 4>(v, scalar); }

	static vec1 Multiply(vec1 v, mat1 m) { return Multiply_<float, 1>(v, m); }
	static vec2 Multiply(vec2 v, mat2 m) { return Multiply_<float, 2>(v, m); }
	static vec3 Multiply(vec3 v, mat3 m) { return Multiply_<float, 3>(v, m); }
	static vec4 Multiply(vec4 v, mat4 m) { return Multiply_<float, 4>(v, m); }

	static vec1 Multiply(mat1 m, vec1 v) { return Multiply_<float, 1>(m, v); }
	static vec2 Multiply(mat2 m, vec2 v) { return Multiply_<float, 2>(m, v); }
	static vec3 Multiply(mat3 m, vec3 v) { return Multiply_<float, 3>(m, v); }
	static vec4 Multiply(mat4 m, vec4 v) { return Multiply_<float, 4>(m, v); }
	//
	static vec1x1 Multiply(vec1x1 v, float scalar) { return Multiply_<float, 1>(v, scalar); }
	static vec1x2 Multiply(vec1x2 v, float scalar) { return Multiply_<float, 2>(v, scalar); }
	static vec1x3 Multiply(vec1x3 v, float scalar) { return Multiply_<float, 3>(v, scalar); }
	static vec1x4 Multiply(vec1x4 v, float scalar) { return Multiply_<float, 4>(v, scalar); }

	static vec1x1 Multiply(vec1x1 v, mat1 m) { return Multiply_<float, 1>(v, m); }
	static vec1x2 Multiply(vec1x2 v, mat2 m) { return Multiply_<float, 2>(v, m); }
	static vec1x3 Multiply(vec1x3 v, mat3 m) { return Multiply_<float, 3>(v, m); }
	static vec1x4 Multiply(vec1x4 v, mat4 m) { return Multiply_<float, 4>(v, m); }

	static vec1x1 Multiply(mat1 m, vec1x1 v) { return Multiply_<float, 1>(m, v); }
	static vec1x2 Multiply(mat2 m, vec1x2 v) { return Multiply_<float, 2>(m, v); }
	static vec1x3 Multiply(mat3 m, vec1x3 v) { return Multiply_<float, 3>(m, v); }
	static vec1x4 Multiply(mat4 m, vec1x4 v) { return Multiply_<float, 4>(m, v); }
	//
	static mat1 Multiply(mat1 m1, mat1 m2) { return Multiply_<float, 1>(m1, m2); }
	static mat2 Multiply(mat2 m1, mat2 m2) { return Multiply_<float, 2>(m1, m2); }
	static mat3 Multiply(mat3 m1, mat3 m2) { return Multiply_<float, 3>(m1, m2); }
	static mat4 Multiply(mat4 m1, mat4 m2) { return Multiply_<float, 4>(m1, m2); }

	//Devide
	static vec1 Devide(vec1 v, float scalar) { return Devide_<float, 1>(v, scalar); }
	static vec2 Devide(vec2 v, float scalar) { return Devide_<float, 2>(v, scalar); }
	static vec3 Devide(vec3 v, float scalar) { return Devide_<float, 3>(v, scalar); }
	static vec4 Devide(vec4 v, float scalar) { return Devide_<float, 4>(v, scalar); }

	static vec1x1 Devide(vec1x1 v, float scalar) { return Devide_<float, 1>(v, scalar); }
	static vec1x2 Devide(vec1x2 v, float scalar) { return Devide_<float, 2>(v, scalar); }
	static vec1x3 Devide(vec1x3 v, float scalar) { return Devide_<float, 3>(v, scalar); }
	static vec1x4 Devide(vec1x4 v, float scalar) { return Devide_<float, 4>(v, scalar); }
};

