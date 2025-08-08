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

    // Función encargada de ejecutar la aplicación en main
    int run();

    // Función de inicialización
    bool init();

    // Función que se actualiza por frame
    void update();

    // Función de renderizado
    void render();

    void destroy();

private:
    std::vector<EngineUtilities::TSharedPointer<Actor>> m_actors;

    EngineUtilities::TSharedPointer<Window> m_windowPtr;
    EngineUtilities::TSharedPointer<Actor> m_ACirlce;

    EngineGUI m_engineGUI;
};
