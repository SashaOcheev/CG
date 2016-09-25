#include "CoordinateSystem.h"
#include <stdexcept>
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES 
#include <math.h>

CoordinateSystem::CoordinateSystem(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart, glm::ivec2 center)
{
	Init(unit, size, displayStart, center);
}

CoordinateSystem::CoordinateSystem(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart)
{
	Init(unit, size, displayStart, { size.x / 2, size.y / 2 });
}

void CoordinateSystem::Draw()
{
	DrawAxes();
	DrawChart();
}

void CoordinateSystem::DrawChart()
{
	glBegin(GL_LINE_STRIP);
	auto lim = 10 * M_PI;
	double r = 0;
	for (double angle = 0; abs(angle) < abs(lim); angle -= 1.0 / 10)
	{
		double x = r * cos(angle);
		double y = r * sin(angle);
		auto curCoor = ConvertCoorToDraw(x, y);
		glVertex2f(curCoor.x, curCoor.y);
		r += 1 / lim;
	}
	glEnd();
}

void CoordinateSystem::DrawAxes()
{
	glBegin(GL_LINES);

	const std::vector<glm::ivec2> STEP = { { m_size.x - m_center.x, 0 }, { -m_center.x, 0 }, { 0, m_size.y - m_center.y }, { 0, -m_center.y } };
	auto center = ConvertCoorToDraw({ 0.f, 0.f });
	auto halfSerifHeight = 5.f;
	for (auto &currentStep : STEP)
	{
		glVertex2f(center.x , center.y);
		auto axisFin = ConvertCoorToDraw({ currentStep.x, currentStep.y });
		glVertex2f(axisFin.x, axisFin.y);

		auto pos = center;
		glm::ivec2 norm = { (currentStep.x == 0) ? 0 : ((currentStep.x < 0) ? -1 : 1), (currentStep.y == 0) ? 0 : ((currentStep.y < 0) ? -1 : 1) };
		int a = 5;
		for (auto i = glm::ivec2(0, 0); abs(i.x + i.y) < abs(currentStep.x + currentStep.y); i.x += norm.x, i.y += norm.y)
		{
			pos = ConvertCoorToDraw(i);
			glVertex2f(pos.x - norm.y * halfSerifHeight, pos.y - norm.x * halfSerifHeight);
			glVertex2f(pos.x + norm.y * halfSerifHeight, pos.y + norm.x * halfSerifHeight);
		}
	}
	glEnd();
}

void CoordinateSystem::Init(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart, glm::ivec2 center)
{
	m_unit = unit;
	m_center = center;
	m_displayStart = displayStart;
	m_size = size;
}

glm::ivec2 CoordinateSystem::ConvertCoorToDraw(glm::dvec2 realCoordinates) const
{
	return { (realCoordinates.x + m_center.x) * m_unit.x + m_displayStart.x - m_unit.x * m_center.x,
		(realCoordinates.y + m_center.y) * m_unit.y + m_displayStart.y - m_unit.y * m_center.y };
}

glm::ivec2 CoordinateSystem::ConvertCoorToDraw(double x, double y) const
{
	return ConvertCoorToDraw({x, y});
}