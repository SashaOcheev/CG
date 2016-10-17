#include "stdafx.h"
#include <cmath>
#include "Circle.h"


CCircle::CCircle(float radius)
{
	const float step = 0.01f;
	for (float i = 0; i < 2 * M_PI; i += step)
	{
		m_line.push_back({ radius * cosf(i), radius * sinf(i) });
	}
}

void CCircle::SetColor(glm::vec3 color, glm::vec3 outColor)
{
	m_color = color;
	if (outColor.x < 0.f)
	{
		m_outColor = color;
		return;
	}
	m_outColor = outColor;
}

void CCircle::Redraw() const
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(m_color.x, m_color.y, m_color.z);
	glVertex2f(0, 0);
	for (size_t i = 0; i < m_line.size(); ++i)
	{
		glColor3f(m_outColor.x, m_outColor.y, m_outColor.z);
		glVertex2f(m_line[i].x, m_line[i].y);
	}
	glEnd();
}

