#pragma once
#include "Drawable.h"
class CMeadow :
	public Drawable
{
public:
	CMeadow() = default;

private:
	void Redraw() const override;
};

