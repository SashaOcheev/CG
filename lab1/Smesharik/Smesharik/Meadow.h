#pragma once
#include "Drawable.h"
class CMeadow :
	public Drawable
{
public:
	CMeadow(std::vector<glm::fvec2> pivots = {});

private:
	void Redraw() const override;

	std::vector<glm::fvec2> m_line;
};

