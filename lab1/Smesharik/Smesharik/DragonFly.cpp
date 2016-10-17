#include "stdafx.h"
#include "DragonFly.h"


void CDragonFly::Redraw() const
{	
	const float step = float(2 * M_PI) / 40.f;

	auto createWing = [&](float deltaAngle, float maxRadius, float minRadius, float centerX, float centerY) {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(centerX, centerY);

		for (float angle = 0; angle <= float(2 * M_PI) + 0.5f * step; angle += step)
		{
			float fixedAngle = (fabsf(angle - float(2 * M_PI)) < 1e-4f) ? 0 : angle;

			float x = maxRadius * cosf(fixedAngle);
			float y = minRadius * sinf(fixedAngle);

			float px = x * cosf(deltaAngle) + y * sinf(deltaAngle);
			float py = y * cosf(deltaAngle) - x * sinf(deltaAngle);
			glVertex2f(px + centerX, py + centerY);
		}
		glEnd();
	};

	glColor3f(0.25f, 0.f, 0.5f);
	createWing((float)M_PI / 3.f, 15.f, 2.f, 5.f, -13.f);
	createWing((float)M_PI * 1.7f / 3.f, 15.f, 2.f, -9.f, -13.f);

	glColor3f(0.f, 0.f, 0.f);
	createWing(0.f, 30.f, 2.f, 0.f, 0.f);

	glColor3f(0.f, 0.795f, 0.54f);
	createWing(0.f, 3.f, 3.f, -17.f, -2.f);

}

