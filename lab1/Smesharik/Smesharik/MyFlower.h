#pragma once
#include "Drawable.h"
class CMyFlower :
	public Drawable
{
public:
	CMyFlower(float minRadius, float maxRadius, int petalCount);

	void SetCenterColor(const glm::vec3 &centerColor);
	void SetPetalColor(const glm::vec3 &petalColor);

private:
	void Redraw() const override;
	float GetRadiusByAngle(float angle) const;

	float m_minRadius = 0;
	float m_maxRadius = 0;
	int m_petalCount = 0;
	glm::vec3 m_centerColor;
	glm::vec3 m_petalColor;
};

