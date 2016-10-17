#pragma once
#include "Drawable.h"
class CDragonFly :
	public Drawable
{
public:
	CDragonFly() = default;

private:
	void Redraw() const override;
};

