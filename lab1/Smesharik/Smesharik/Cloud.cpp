#include "stdafx.h"
#include <cmath>
#include "Circle.h"
#include "Cloud.h"
#include <utility>

const float RADIUS = 30.f;

CCloud::CCloud()
{
	std::vector<glm::fvec2> positions = {
		{ 0.f, 0.f },
		{ 50.f, 0.f },
		{ 80.f, 40.f },
		{ 35.f, 50.f },
		{ 0.f, 30.f },
		{ -20.f, 40.f },
	};

	for (auto &currentPosistion : positions)
	{
		auto circle = std::make_unique<CCircle>(RADIUS);
		circle.get()->SetPosition(currentPosistion);
		m_cloud.push_back(std::move(circle));
	}

	SetColor(m_color);
}

void CCloud::SetColor(const glm::vec3 &color)
{
	m_color = color;
	for (auto &circle : m_cloud)
	{
		circle.get()->SetColor(color);
	}
}

void CCloud::Draw() const
{
	for (auto &circle : m_cloud)
	{
		circle.get()->Draw();
	}
}

void CCloud::SetPosition(const glm::vec2 & position)
{
	Drawable::SetPosition(position);
	for (auto &circle : m_cloud)
	{
		circle.get()->SetPosition(circle.get()->GetPosition() + Drawable::GetPosition());
	}
}

void CCloud::Redraw() const
{
}

