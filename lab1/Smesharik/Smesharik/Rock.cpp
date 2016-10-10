#include "stdafx.h"
#include <cmath>
#include "Rock.h"
#include "BezierCurve.h"

const float HEIGHT = 600.f;
const float ICE_PEAK_HEIGHT = 80.f;
const float DELTA = 30.f;

CRock::CRock(float angle)
{
	angle /= 2;
	angle *= M_PI / 180.f;
	m_basis = { tanf(angle) * HEIGHT, HEIGHT };
	
	//Снежная вершина
	std::vector<glm::fvec2> vectorForBezier;
	float step = 0.2f;
	for (float i = -angle; i < angle; i += step)
	{
		i = (i > angle - step) ? angle : i;
		vectorForBezier.push_back({ tanf(i) * ICE_PEAK_HEIGHT, ICE_PEAK_HEIGHT });
	}

	float delta = DELTA;
	for (size_t i = 1; i < vectorForBezier.size() - 1; ++i)
	{
		vectorForBezier[i].y += delta;
		delta = -delta;
	}

	m_line = GetBezierCurve(vectorForBezier, 0.01f);
}

void CRock::Redraw() const
{
	//гора
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	glVertex2f(-m_basis.x, m_basis.y);
	glVertex2f(m_basis.x, m_basis.y);
	glEnd();

	//вершина
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(0, 0);
	glColor3f(0.32f, 0.32f, 0.32f);
	for (size_t i = 0; i < m_line.size(); ++i)
	{
		glVertex2f(m_line[i].x, m_line[i].y);
	}
	glEnd();

	//контур
	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0);
	glVertex2f(-m_basis.x, m_basis.y);
	glVertex2f(m_basis.x, m_basis.y);
	glEnd();
}
