#include "stdafx.h"
#include <cmath>
#include <boost/math/special_functions/factorials.hpp>
#include "BezierCurve.h"

size_t Factorial(size_t number)
{
	if (number <= 1)
	{
		return 1;
	}

	size_t res = 1;
	for (; number > 1; --number)
	{
		res *= number;
	}

	return res;
}

size_t GetCombinationsCount(size_t n, size_t k)
{
	size_t res = 1;
	auto maximum = std::max(k, n - k);
	for (size_t i = maximum + 1; i <= n; ++i)
	{
		res *= i;
	}
	return res / Factorial(n - maximum);
}

// number - номер вершины, count - количество вершин, position - положение кривой (от 0 до 1)
float GetBezierBasis(const size_t number, const size_t count, const float position)
{
	// считаем i-й элемент полинома Берштейна
	return static_cast<float>(GetCombinationsCount(count, number) * pow(position, number) * pow(1 - position, count - number));
}


// arr - массив опорных точек
// step - шаг при расчете кривой (0 < step < 1), по умолчанию 0.01
std::vector<glm::fvec2> GetBezierCurve(const std::vector<glm::fvec2> &arr, float step)
{
	std::vector<glm::fvec2> res;

	for (float t = 0.f; t < 1.f + step; t += step)
	{
		(t > 1.f) ? 1.f : t;

		res.push_back({ 0, 0 });

		for (size_t i = 0; i < arr.size(); ++i)
		{
			auto basis = GetBezierBasis(i, arr.size() - 1, t);
			res.back() += glm::fvec2({ arr[i].x * basis, arr[i].y * basis });
		}
	}

	return res;
}