#pragma once

#include "Prerequisites.h"
#include "Window.h"
#include "CShape.h"
#include "ECS/Actor.h"
#include "EngineGUI.h"

class BaseApp {
public:
    BaseApp() = default;
    ~BaseApp();

    // Funci�n encargada de ejecutar la aplicaci�n en main
    int run();

    // Funci�n de inicializaci�n
    bool init();

    // Funci�n que se actualiza por frame
    void update();

    // Funci�n de renderizado
    void render();

    void destroy();

private:
    std::vector<EngineUtilities::TSharedPointer<Actor>> m_actors;

    EngineUtilities::TSharedPointer<Window> m_windowPtr;
    EngineUtilities::TSharedPointer<Actor> m_ACirlce;

    EngineGUI m_engineGUI;
};
