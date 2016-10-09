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

// number - ����� �������, count - ���������� ������, position - ��������� ������ (�� 0 �� 1)
size_t GetBezierBasis(const size_t number, const size_t count, const float position)
{
	// ������� i-� ������� �������� ���������
	return GetCombinationsCount(count, number) * pow(position, number) * pow(1 - position, count - number);
}


// arr - ������ ������� �����
// step - ��� ��� ������� ������ (0 < step < 1), �� ��������� 0.01
std::vector<glm::fvec2> GetBezierCurve(const std::vector<glm::fvec2> &arr, float step = 0.01)
{
	std::vector<glm::fvec2> res;

	for (float t = 0; t < 1 + step; t += step)
	{
		if (t > 1)
		{
			t = 1;
		}

		for (size_t i = 0; i < arr.size(); ++i)
		{
			auto b = GetBezierBasis(i, arr.size() - 1, t);
			res.push_back({ arr[i].x * b, arr[i].y * b });
		}
	}

	return res;
}