#pragma once
#include "Drawable.h"

class CCircle :
	public Drawable
{
public:
	CCircle(float radius);
	void SetColor(glm::vec3 color);

private:
	void Redraw() const override;

	glm::vec3 m_color = { 0.f, 0.f, 0.f };
	std::vector<glm::fvec2> m_line;
};

