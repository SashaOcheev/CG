#include "stdafx.h"
#include "Drawable.h"


Drawable::~Drawable()
{
	DeleteList();
}

void Drawable::Draw() const
{
	// ������������ Model-View �������,
	// ������ ��� ����� ����������� �� ������ (x, y, 0)
	glm::vec3 offset = { m_position.x, m_position.y, 0.f };
	glm::mat4 transform = glm::translate(glm::mat4(), offset);
	// ��������� ������ ������� � ���� ������ ��������
	glPushMatrix();
	glLoadMatrixf(glm::value_ptr(transform));

	// ���� ���������� ������ ��� �� ��� ������, �� ��� ������ ������� ���
	if (!m_displayList)
	{
		// ���������� ����� ���������� ������
		m_displayList = glGenLists(1);
		glNewList(m_displayList, GL_COMPILE);
		// ��� ���������� ������ �������� redraw.
		Redraw();
		// ��������� ���������� ������
		glEndList();
	}
	// �������� ����� ��������� ���������� ������
	glCallList(m_displayList);

	// ��������� ������ ������� �� ����� ������ ��������
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
