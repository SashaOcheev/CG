#include "stdafx.h"
#include "Window.h"
#include <boost/range/algorithm/find_if.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include "BezierCurve.h"

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

	//Солнце
	auto sun = std::make_unique<CCircle>(70.f);
	sun->SetPosition({ 700, 100 });
	sun->SetColor({ 1.f, 1.f, 0.f });
	m_shapes.push_back(std::move(sun));

	//облака
	auto cloud = std::make_unique<CCloud>();
	cloud->SetPosition({ 180, 60 });
	m_shapes.push_back(std::move(cloud));

	cloud = std::make_unique<CCloud>();
	cloud->SetPosition({ 600, 100 });
	m_shapes.push_back(std::move(cloud));

	//горы
	auto rock = std::make_unique<CRock>(60.f);
	rock->SetPosition({ 75, 90 });
	m_shapes.push_back(std::move(rock));
	
	rock = std::make_unique<CRock>(60.f);
	rock->SetPosition({ 230, 30 });
	m_shapes.push_back(std::move(rock));

	//луг
	auto meadow = std::make_unique<CMeadow>();
	//meadow->SetPosition({ 400, 300 });
	m_shapes.push_back(std::move(meadow));

	//цветы
	std::vector<glm::vec2> positions = {
		{ 700, 320 },
		{ 750, 500 },
		{ 200, 550 },
		{ 550, 450 },
	};
	for (auto &pos : positions)
	{
		auto pFlower = std::make_unique<CMyFlower>(15, 45, 6);
		pFlower->SetCenterColor(LIGHT_YELLOW);
		pFlower->SetPetalColor(RED);
		pFlower->SetPosition(pos);
		m_shapes.push_back(std::move(pFlower));
	}

	//цветы
	positions = {
		{ 60, 360 },
		{ 515, 515 },
		{ 430, 355 },
		{ 200, 400 },
	};
	for (auto &pos : positions)
	{
		auto pFlower = std::make_unique<CMyFlower>(10, 30, 7);
		pFlower->SetCenterColor(LIGHT_YELLOW);
		pFlower->SetPetalColor(ORANGE);
		pFlower->SetPosition(pos);
		m_shapes.push_back(std::move(pFlower));
	}

	//стрекозы
	positions = {
		{ 120, 280 },
		{ 230, 530 },
		{ 730, 390 },
	};
	for (auto &pos : positions)
	{
		auto dragonFly = std::make_unique<CDragonFly>();
		dragonFly->SetPosition(pos);
		m_shapes.push_back(std::move(dragonFly));
	}
	SetBackgroundColor({ 0.4f, 0.7f, 1.f, 1.f });
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
