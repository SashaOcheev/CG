#pragma once
#include "Drawable.h"

class CCircle :
	public Drawable
{
public:
	CCircle(float radius);

private:
	void Redraw() const override;

	std::vector<glm::fvec2> m_line;
};

