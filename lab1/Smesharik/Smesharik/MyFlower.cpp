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
	// ������� ��� (��� ��������� ������� ��������
	// ��� ����������� ��� ������� 20 ������)
	const float step = float(2 * M_PI) / float(m_petalCount * 20);

	glBegin(GL_TRIANGLE_FAN);

	// ����������� ������� ����� ����� ���� m_centerColor
	glColor3f(m_centerColor.x, m_centerColor.y, m_centerColor.z);
	glVertex2f(0, 0);

	// ������� �������� ����� ����� ���� m_petalColor
	glColor3f(m_petalColor.x, m_petalColor.y, m_petalColor.z);
	for (float angle = 0; angle <= float(2 * M_PI) + 0.5f * step; angle += step)
	{
		// � ���������� ���� ����������� sin(2 * PI) ����� ����������
		// �� sin(0). ������� ���� angle ������� ������ � 2*PI,
		// ������� ��� ������ 0
		// ��� ����� ��� ����, ����� ������ � ����� �����
		// ������� � ����� �����
		float fixedAngle = (fabsf(angle - float(2 * M_PI)) < 1e-4f) ? 0 : angle;

		// ��������� ������ ������������ ���������� ��� ������� ����
		float radius = GetRadiusByAngle(fixedAngle);
		float x = radius * cosf(fixedAngle);
		float y = radius * sinf(fixedAngle);

		// ������� ����� �������
		glVertex2f(x, y);
	}

	glEnd();
}

float CMyFlower::GetRadiusByAngle(float angle) const
{
	// ��������� ������ ������������ ���������� ��� ������� ����.
	return 0.5f * (m_maxRadius - m_minRadius)
		* cosf(angle * m_petalCount) + m_minRadius;
}
