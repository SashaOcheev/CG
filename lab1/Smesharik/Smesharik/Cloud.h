#pragma once
#include "Drawable.h"
#include <memory>


class CCloud :
	public Drawable
{
public:
	CCloud();
	void SetColor();
	void Draw() const override;
	void SetPosition(const glm::vec2 &position) override;

private:
	void Redraw() const override;
	glm::vec3 m_color = { 1.f, 1.f, 1.f };
	glm::vec3 m_outColor = { 0.96f, 0.96f, 0.96f };
	std::vector<std::unique_ptr<CCircle>> m_cloud;
};

