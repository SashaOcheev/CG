#pragma once
#include "DispatchEvent.h"
#include "MovableFlower.h"
#include "Meadow.h"
#include "Circle.h"
#include "Rock.h"
#include "Cloud.h"
#include "MyFlower.h"
#include "DragonFly.h"
#include <vector>

class CWindow : public CAbstractInputControlWindow
{
public:
    CWindow();

protected:
    // CAbstractWindow interface
    void OnUpdateWindow(float deltaSeconds) override;
    void OnDrawWindow(const glm::ivec2 &size) override;

private:
    void SetupView(const glm::ivec2 &size);

    std::vector<std::unique_ptr<Drawable>> m_shapes;
};
