#include "stdafx.h"
#include "Meadow.h"
#include "BezierCurve.h"


CMeadow::CMeadow(std::vector<glm::fvec2> pivots)
{
	if (pivots.empty())
	{
		pivots = {
			{ 0, 300 },
			{ 160, 380 },
			{ 320, 380 },
			{ 480, 300 },
			{ 640, 200 },
			{ 800, 300 },
		};
	}
	m_line = GetBezierCurve(pivots, 0.001);
}

void CMeadow::Redraw() const
{
	/*glColor3f(0.f, 0.f, 0.f);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(100, 0);

	glEnd();*/

	glColor3f(0.f, 0.f, 0.f);

	glBegin(GL_LINE_STRIP);

	for (size_t i = 0; i < m_line.size(); ++i)
	{
		glVertex2f(m_line[i].x, m_line[i].y);
	}

	glEnd();
}
