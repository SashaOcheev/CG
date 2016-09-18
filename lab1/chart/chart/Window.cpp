#include "Window.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace
{

// Рисуем систему координат
void CoordianteSystem(float xCenter, float yCenter)
{
	// Начинаем новую группу примитивов (замкнутая ломаная линия)
	glBegin(GL_LINES);

	const glm::ivec2 size = { 800, 600 };

	const std::vector<glm::ivec2> STEP = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	for (size_t i = 0; i < STEP.size(); ++i)
	{
		auto currentStep = STEP[i];
		float x = xCenter + currentStep.x * size.x / 2;
		float y = yCenter + currentStep.y * size.y / 2;
		// функция glVertex2f добавляет в текущую группу примитивов
		// точку, лежащую на плоскости z = 0
		// суффикс 2f в названии функции обозначает, что задаются 2 координаты
		// x и y типа GLfloat
		glVertex2f(xCenter, yCenter);
		glVertex2f(x, y);
	}
	// Заканчиваем группу примитивов
	glEnd();
}


// Рисуем пятиконечную звезду
void Stroke5PointStar(float xCenter, float yCenter, float radius)
{
    const float STEP = float(M_PI * 4 / 5);

    // Начинаем новую группу примитивов (замкнутая ломаная линия)
    glBegin(GL_LINE_LOOP);

    float angle = float(-0.5 * M_PI);

    // Соединяем отрезками прямой линии точки, расположенные на окружности
    // в точках, с углами: -90, 54, 198, 342, 486 (126) градусов
    for (int i = 0; i < 5; ++i, angle += STEP)
    {
        float x = xCenter + radius * cosf(angle);
        float y = yCenter + radius * sinf(angle);
        // функция glVertex2f добавляет в текущую группу примитивов
        // точку, лежащую на плоскости z = 0
        // суффикс 2f в названии функции обозначает, что задаются 2 координаты
        // x и y типа GLfloat
        glVertex2f(x, y);
    }

    // Заканчиваем группу примитивов
    glEnd();
}

// Рисуем контур эллипса
void StrokeEllipse(float xCenter, float yCenter, float rx, float ry, int pointCount = 360)
{
    const float step = float(2 * M_PI / pointCount);

    // Эллипс представлен в виде незамкнутой ломаной линии, соединяющей
    // pointCount точек на его границе с шагом 2*PI/pointCount
    glBegin(GL_LINE_STRIP);
    for (float angle = 0; angle < float(2 * M_PI); angle += step)
    {
        const float dx = rx * cosf(angle);
        const float dy = ry * sinf(angle);
        glVertex2f(dx + xCenter, dy + yCenter);
    }
    glEnd();
}

// Рисуем закрашенный эллипс
void FillEllipse(float xCenter, float yCenter, float rx, float ry, int pointCount = 360)
{
    const float step = float(2 * M_PI) / pointCount;

    // Эллипс представлет в виде "веера" из треугольников
    glBegin(GL_TRIANGLE_FAN);
    // Начальная точка веера располагается в центре эллипса
    glVertex2f(xCenter, yCenter);
    // Остальные точки - равномерно по его границе
    for (float angle = 0; angle <= float(2 * M_PI); angle += step)
    {
        float a = (fabsf(angle - float(2 * M_PI)) < 0.00001f) ? 0.f : angle;
        const float dx = rx * cosf(a);
        const float dy = ry * sinf(a);
        glVertex2f(dx + xCenter, dy + yCenter);
    }
    glEnd();
}
}

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
	CoordianteSystem(400, 300);
	/*
    // Эллипс будет иметь красный цвет.
    // суффикс 3f означает, что
    // функция принимает 3 параметра типа float.
    // компоненты цвета во float задаются на отрезке [0..1].
	glColor3f(1, 0, 0);
    // Рисуем эллипс (как ломаную линию)
    StrokeEllipse(200, 340, 20, 120);

    // Рисуем закрашенный эллипс
    glColor3f(0, 1, 1);
    FillEllipse(150, 120, 100, 90);

    // Рисуем пятиконечную звезду (как ломаную линию)
    glColor3f(1, 1, 1);
    Stroke5PointStar(350, 210, 100);*/


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
