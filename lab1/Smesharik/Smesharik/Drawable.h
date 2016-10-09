#pragma once

#include <boost/noncopyable.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class Drawable : private boost::noncopyable
{
public:
	Drawable() = default;
	virtual ~Drawable();

	virtual void Draw() const;

	virtual const glm::vec2 &GetPosition() const;
	virtual void SetPosition(const glm::vec2 &position);

protected:
	virtual void Redraw() const = 0;

private:
	virtual void DeleteList();

	mutable unsigned m_displayList = 0;

	glm::vec2 m_position = { 0, 0 };
};

