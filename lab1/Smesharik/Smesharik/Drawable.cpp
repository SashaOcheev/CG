#include "stdafx.h"
#include "Drawable.h"


Drawable::~Drawable()
{
	DeleteList();
}

void Drawable::Draw() const
{
	// Модифицируем Model-View матрицу,
	// теперь она задаёт перемещение на вектор (x, y, 0)
	glm::vec3 offset = { m_position.x, m_position.y, 0.f };
	glm::mat4 transform = glm::translate(glm::mat4(), offset);
	// Сохраняем старую матрицу в стек матриц драйвера
	glPushMatrix();
	glLoadMatrixf(glm::value_ptr(transform));

	// если дисплейный список еще не был создан, то для начала создаем его
	if (!m_displayList)
	{
		// Генерируем новый дисплейный список
		m_displayList = glGenLists(1);
		glNewList(m_displayList, GL_COMPILE);
		// Для заполнения списка вызываем redraw.
		Redraw();
		// завершаем дисплейный список
		glEndList();
	}
	// вызываем ранее созданный дисплейный список
	glCallList(m_displayList);

	// Извлекаем старую матрицу из стека матриц драйвера
	glPopMatrix();
}

const glm::vec2 & Drawable::GetPosition() const
{
	return m_position;
}

void Drawable::SetPosition(const glm::vec2 & position)
{
	m_position = position;
}

void Drawable::DeleteList()
{
	if (m_displayList)
	{
		glDeleteLists(m_displayList, 1);
		m_displayList = 0;
	}
}
