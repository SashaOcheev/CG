#pragma once
#include "DispatchEvent.h"
#include "MovableFlower.h"
#include "Meadow.h"
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