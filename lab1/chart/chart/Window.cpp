#include "Window.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "CoordinateSystem.h"


CWindow::CWindow()
{
    SetBackgroundColor({1.f, 1.f, 1.f, 1.f});
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
    m_time += deltaSeconds;
}

void CWindow::OnDrawWindow(const glm::ivec2 &size)
{
    SetupView(size);

	glColor3f(0, 0, 0);
	auto coor = CoordinateSystem({ 30, 30 }, { 20, 20 }, { 400, 300 }, { 10, 10 });
	coor.Draw();


}

void CWindow::SetupView(const glm::ivec2 &size)
{
    // Матрица ортографического проецирования изображения в трёхмерном пространстве
    // из параллелипипеда с размером, равным (size.X x size.Y x 2).
    const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(matrix));
    glMatrixMode(GL_MODELVIEW);
}
