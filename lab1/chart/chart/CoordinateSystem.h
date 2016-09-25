#pragma once
#include <boost/noncopyable.hpp>
#include <glm/vec2.hpp>



class CoordinateSystem
{
public:
	CoordinateSystem(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart, glm::ivec2 center);
	CoordinateSystem(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart);
	void Draw();

private:
	void DrawChart();
	void DrawAxes();
	glm::ivec2 ConvertCoorToDraw(glm::dvec2 realCoordinates) const;
	glm::ivec2 ConvertCoorToDraw(double x, double y) const;

	glm::ivec2 m_unit;
	glm::ivec2 m_center;
	glm::ivec2 m_size;
	glm::ivec2 m_displayStart;

	void Init(glm::ivec2 unit, glm::ivec2 size, glm::ivec2 displayStart, glm::ivec2 center);
};

