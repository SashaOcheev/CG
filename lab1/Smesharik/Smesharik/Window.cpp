#include "stdafx.h"
#include "Window.h"
#include <boost/range/algorithm/find_if.hpp>
#include <boost/range/adaptor/reversed.hpp>

namespace
{
const glm::vec3 LIGHT_YELLOW = { 1.f, 1.f, 0.5f};
const glm::vec3 RED = {1, 0, 0};
const glm::vec3 ORANGE = {1.f, 0.5f, 0.f};
const glm::vec3 YELLOW = {1.f, 1.f, 0.f};
const glm::vec3 WHITE = { 1.f, 1.f, 1.f };
const glm::vec3 BLACK = { 0.f, 0.f, 0.f };
const glm::vec4 QUIET_WHITE = { 1.f, 1.f, 1.f, 1.f };
const glm::vec4 QUIET_GREEN = { 0.f, 0.5f, 0.2f, 1.f };
}

CWindow::CWindow()
{
	/*
   {
        auto pFlower = std::make_unique<CMovableFlower>();
        pFlower->SetupShape(40, 150, 6);
        pFlower->SetCenterColor(LIGHT_YELLOW);
        pFlower->SetPetalColor(RED);
        pFlower->SetPosition({ 150, 220 });
        m_flowers.push_back(std::move(pFlower));
    }
    {
        auto pFlower = std::make_unique<CMovableFlower>();
        pFlower->SetupShape(20, 60, 5);
        pFlower->SetCenterColor(LIGHT_YELLOW);
        pFlower->SetPetalColor(ORANGE);
        pFlower->SetPosition({ 350, 140 });
        m_flowers.push_back(std::move(pFlower));
    }
    {
        auto pFlower = std::make_unique<CMovableFlower>();
        pFlower->SetupShape(25, 70, 7);
        pFlower->SetCenterColor(RED);
        pFlower->SetPetalColor(YELLOW);
        pFlower->SetPosition({ 270, 360 });
        m_flowers.push_back(std::move(pFlower));
    }
	*/
	auto meadow = std::make_unique<CMeadow>();
	meadow->SetPosition({ 400, 300 });
	m_shapes.push_back(std::move(meadow));

    SetBackgroundColor(QUIET_WHITE);
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
    (void)deltaSeconds;
}

void CWindow::OnDrawWindow(const glm::ivec2 &size)
{
    SetupView(size);

    for (const auto &pShape : m_shapes)
    {
        pShape->Draw();
    }
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
