#pragma once
#include "Drawable.h"
#include <memory>


class CCloud :
	public Drawable
{
public:
	CCloud();
	void SetColor(const glm::vec3 &color);
	void Draw() const override;
	void SetPosition(const glm::vec2 &position) override;

private:
	void Redraw() const override;
	glm::vec3 m_color = { 1.f, 1.f, 1.f };
	std::vector<std::unique_ptr<CCircle>> m_cloud;
};

