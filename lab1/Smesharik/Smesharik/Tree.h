#pragma once
#include "Drawable.h"
#include "Circle.h"
class CTree :
	public Drawable
{
public:
	CTree();
	void Draw() const override;
	void SetPosition(const glm::vec2 &position) override;
	void SetColor();

private:
	void Redraw() const override;
	glm::vec3 m_color = { 0.f, 0.3f, 0.f };
	glm::vec3 m_outColor = { 0.f, 0.33f, 0.f };
	std::vector<std::unique_ptr<CCircle>> m_foliage;
};

