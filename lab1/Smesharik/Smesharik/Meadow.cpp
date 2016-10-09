#include "stdafx.h"
#include "Meadow.h"


void CMeadow::Redraw() const
{
	glColor3f(0.f, 0.f, 0.f);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(100, 0);

	glEnd();
}
