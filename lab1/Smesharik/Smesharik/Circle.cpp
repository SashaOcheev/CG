#include "stdafx.h"
#include <cmath>
#include "Circle.h"
#include "BezierCurve.h"


CCircle::CCircle(float radius)
{
	const float step = 0.01;
	for (float i = 0; i < 2 * M_PI; i += step)
	{
		m_line.push_back({ radius * cosf(i), radius * sinf(i) });
	}
}

void CCircle::Redraw() const
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.f, 1.f, 0.f);
	glVertex2f(0, 0);
	for (size_t i = 0; i < m_line.size(); ++i)
	{
		glVertex2f(m_line[i].x, m_line[i].y);
	}
	glEnd();
}

