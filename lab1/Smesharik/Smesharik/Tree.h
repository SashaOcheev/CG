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
	void SetColor(const glm::vec3 &color);

private:
	void Redraw() const override;
	glm::vec3 m_color = { 0.f, 0.3f, 0.f };
	std::vector<std::unique_ptr<CCircle>> m_foliage;
};

