#include "stdafx.h"
#include "Tree.h"
#include "Circle.h"

const float RADIUS = 40.f;

CTree::CTree()
{
	std::vector<glm::fvec2> positions = {
		{ 0.f, 0.f },
		{ -40.f, 30.f },
		{ -10.f, 50.f },
		{ 30.f, 40.f },
		{ 30.f, 70.f },
		{ -45.f, 70.f },
		{ 0.f, 70.f },
		{ 0.f, 100.f },
		{ -30.f, 100.f },
		{ 20.f, 110.f },
		{ -10.f, 120.f },
	};

	for (auto &currentPosistion : positions)
	{
		auto circle = std::make_unique<CCircle>(RADIUS);
		circle.get()->SetPosition(currentPosistion);
		m_foliage.push_back(std::move(circle));
	}

	SetColor(m_color);
}

void CTree::Draw() const
{
	Drawable::Draw();
	for (auto &circle : m_foliage)
	{
		circle.get()->Draw();
	}
}

void CTree::SetPosition(const glm::vec2 & position)
{
	Drawable::SetPosition(position);
	for (auto &circle : m_foliage)
	{
		circle.get()->SetPosition(circle.get()->GetPosition() + Drawable::GetPosition());
	}
}

void CTree::SetColor(const glm::vec3 & color)
{
	m_color = color;
	for (auto &circle : m_foliage)
	{
		circle.get()->SetColor(color);
	}
}

void CTree::Redraw() const
{
	glColor3f(0.5f, 0.25f, 0.f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-15.f, 210.f);
	glVertex2f(15.f, 210.f);
	glVertex2f(-0.f, 0.f);
	glEnd();
}

