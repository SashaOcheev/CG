#include "stdafx.h"
#include "MyFlower.h"



CMyFlower::CMyFlower(float minRadius, float maxRadius, int petalCount)
{
	m_minRadius = minRadius;
	m_maxRadius = maxRadius;
	m_petalCount = petalCount;
}

void CMyFlower::SetCenterColor(const glm::vec3 & centerColor)
{
	m_centerColor = centerColor;
}

void CMyFlower::SetPetalColor(const glm::vec3 & petalColor)
{
	m_petalColor = petalColor;
}

void CMyFlower::Redraw() const
{
	// угловой шаг (для рисования каждого лепестка
	// нам понадобится как минимум 20 вершин)
	const float step = float(2 * M_PI) / float(m_petalCount * 20);

	glBegin(GL_TRIANGLE_FAN);

	// центральная вершина будет иметь цвет m_centerColor
	glColor3f(m_centerColor.x, m_centerColor.y, m_centerColor.z);
	glVertex2f(0, 0);

	// вершины лепестка будут иметь цвет m_petalColor
	glColor3f(m_petalColor.x, m_petalColor.y, m_petalColor.z);
	for (float angle = 0; angle <= float(2 * M_PI) + 0.5f * step; angle += step)
	{
		// в дискретном мире компьютеров sin(2 * PI) может отличаться
		// от sin(0). Поэтому если angle подошел близко к 2*PI,
		// считаем его равным 0
		// это нужно для того, чтобы начало и конец веера
		// сошлись в одной точке
		float fixedAngle = (fabsf(angle - float(2 * M_PI)) < 1e-4f) ? 0 : angle;

		// вычисляем радиус искривленной окружности для данного угла
		float radius = GetRadiusByAngle(fixedAngle);
		float x = radius * cosf(fixedAngle);
		float y = radius * sinf(fixedAngle);

		// создаем новую вершину
		glVertex2f(x, y);
	}

	glEnd();
}

float CMyFlower::GetRadiusByAngle(float angle) const
{
	// вычисляем радиус искривленной окружности для данного угла.
	return 0.5f * (m_maxRadius - m_minRadius)
		* cosf(angle * m_petalCount) + m_minRadius;
}
