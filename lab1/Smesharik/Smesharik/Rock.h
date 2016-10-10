#pragma once
#include "Drawable.h"

class CRock : public Drawable
{
public:
	CRock(float angle);

private:
	void Redraw() const override;

	std::vector<glm::fvec2> m_line;
	glm::fvec2 m_basis;
};

