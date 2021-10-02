#include <iostream>
///////////////////////
//#include "my_sin_cos.h"
///////////////////////
#pragma once
#include <optional>

#define _USE_MATH_DEFINES
#include <math.h>

#include <concepts> // uses cpp20

constexpr uint64_t trignometry_resolution = 6; // no. of terms
template<typename Typ> requires std::floating_point<Typ>
Typ software_sin (Typ radians)
{
	if (trignometry_resolution > 10) {
		throw std::runtime_error ("we can only calculate factorial up-to 20, please set trignometry_resolution <= 10");
	}
	{ // resolve angle
		Typ m_2_pi = (2*M_PI);
		Typ ratio = radians/m_2_pi;
		Typ integral;
		Typ fraction = modf (ratio, &integral);
		fraction += fraction < 0 ? 1.0 : 0.0;

		bool flip_sign = fraction > 0.5; // {pi, 2pi}
		fraction -= flip_sign ? 0.5 : 0.0;
		bool flip_axis = fraction > 0.25; // {pi/2, pi}
		fraction = flip_axis ? 0.5 - fraction : fraction;

		radians = fraction*m_2_pi;
		radians = flip_sign ? -radians : radians;
	}
	Typ data = 0.0;
	Typ radians_sqr = radians*radians;
	for (uint64_t i = 0; i < trignometry_resolution; i++) {
		float sign = i % 2 ? -1 : 1;
		Typ _x = radians;
		uint64_t _factorial = 1;
		for (uint64_t j = 1; j < (i+1); j++)
		{
			_x *= radians_sqr;

			auto j_2 = j << 1; // j * 2
			_factorial *= j_2*(j_2+1);
		}
		data += sign*(_x/_factorial);
	}
	return data;
}
template<typename Typ> requires std::floating_point<Typ>
Typ software_cos (Typ radians)
{
	if (trignometry_resolution > 10) {
		throw std::runtime_error ("we can only calculate factorial up-to 20, please set trignometry_resolution <= 10");
	}
	bool flip_sign = false;
	{ // resolve angle
		Typ m_2_pi = (2*M_PI);
		Typ ratio = radians/m_2_pi;
		Typ integral;
		Typ fraction = modf (ratio, &integral);
		fraction += fraction < 0 ? 1.0 : 0.0;

		fraction = fraction > 0.5 ? 1.0 - fraction : fraction;

		bool flip_axis_and_sign = flip_sign = fraction > 0.25; // {pi/2, pi}
		fraction = flip_axis_and_sign ? 0.5 - fraction : fraction;

		radians = fraction*m_2_pi;
	}
	Typ data = 0.0;
	Typ radians_sqr = radians*radians;
	for (uint64_t i = 0; i < trignometry_resolution; i++) {
		float sign = i % 2 ? -1 : 1;
		Typ _x = 1;
		uint64_t _factorial = 1;
		for (uint64_t j = 1; j < i + 1; j++)
		{
			_x *= radians_sqr;

			auto j_2 = j << 1; // j * 2
			_factorial *= j_2*(j_2 - 1);
		}
		data += sign*(_x/_factorial);
	}
	return flip_sign ? -data : data;
}
///////////////////
/// source.cpp
///////////////////
int main ()
{
	using namespace std;
	{
		constexpr double test = 4.5;

		cout <<"test for: "<<  test << '\n';
		cout <<" cos: "<<  cos(test) << '\n';
		cout <<"scos: "<< software_cos(test) << '\n';

		cout <<" sin: "<<  cos(test) << '\n';
		cout <<"ssin: "<< software_cos(test) << '\n';
	}
	return 0;
};
