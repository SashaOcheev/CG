#include "stdafx.h"
#include "Meadow.h"
#include "BezierCurve.h"


CMeadow::CMeadow(std::vector<glm::fvec2> pivots)
{
	if (pivots.empty())
	{
		pivots = {
			{ 0, 280 },
			{ 160, 340 },
			{ 320, 340 },
			{ 480, 280 },
			{ 640, 180 },
			{ 800, 280 },
		};
	}
	m_line = GetBezierCurve(pivots, 0.001);
}

void CMeadow::Redraw() const
{
	glColor3f(0.f, 0.5f, 0.f);
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(300, 600);
	glVertex2f(0, 600);
	for (size_t i = 0; i < m_line.size(); ++i)
	{
		glVertex2f(m_line[i].x, m_line[i].y);
	}
	glVertex2f(800, 600);
	glEnd();
}
