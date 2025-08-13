#include "BaseApp.h"
#include "ECS/Transform.h"
#include "CShape.h"

#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <filesystem>

BaseApp::~BaseApp() {
}

int BaseApp::run() {
    if (!init()) {
        ERROR("ChrisEngine", "run", "Initialization failed");
    }

    while (m_windowPtr->isOpen()) {
        m_windowPtr->handleEvents(m_engineGUI);
        update();
        render();
    }

    destroy();
    return 0;
}

bool BaseApp::init() {
    ResourceManager& resourceMan = ResourceManager::getInstance();

    m_windowPtr = EngineUtilities::MakeShared<Window>(1920, 1080, "ChrisEngine");
    if (!m_windowPtr) {
        ERROR("ChrisEngine", "init", "Failed to create window");
        return false;
    }

    // Inicializar GUI
    m_engineGUI.init(m_windowPtr);

    // Lista de texturas y nombres de corredores
    struct RacerInfo {
        std::string name;
        std::string texturePath;
    } racersData[] = {
        {"Sonic",    "Sprites/sonic.png"},
        {"Wario",    "Sprites/wario.png"},
        {"Birdo",    "Sprites/virdo.png"},
        {"Princesa", "Sprites/princesa.png"}
    };

    // Crear actores corredores
    int playerId = 1;
    for (auto& info : racersData) {
        auto racer = EngineUtilities::MakeShared<A_Racer>(info.name, playerId++);
        if (racer) {
            // Cargar textura
            if (!resourceMan.loadTexture(info.texturePath, "")) {
                MESSAGE("ChrisEngine", "init", "Can't load texture: " + info.texturePath);
            }
            racer->setTexture(resourceMan.getTexture(info.texturePath));
            racer->getComponent<Transform>()->setPosition(sf::Vector2f(100.f * playerId, 200.f));
            racer->setMaxSpeed(200.0f);
            m_actors.push_back(racer);
        }
    }

    // Crear pista de carreras
    auto pista = EngineUtilities::MakeShared<Actor>("Pista");
    if (pista) {
        if (!resourceMan.loadTexture("Sprites/pista_de_carreras.png", "")) {
            MESSAGE("ChrisEngine", "init", "Can't load pista texture");
        }
        pista->setTexture(resourceMan.getTexture("Sprites/pista_de_carreras.png"));
        pista->getComponent<Transform>()->setPosition(sf::Vector2f(960.f, 540.f));
        m_actors.push_back(pista);
    }

    return true;
}

void BaseApp::update() {
    if (!m_windowPtr.isNull()) {
        m_windowPtr->update();
    }

    // Actualizar GUI
    m_engineGUI.update(m_windowPtr, m_windowPtr->deltaTime);
    m_engineGUI.outliner(m_actors);
    m_engineGUI.inspector(m_actors);

    // Actualizar actores
    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->update(m_windowPtr->deltaTime.asSeconds());
        }
    }
}

void BaseApp::render() {
    if (!m_windowPtr) return;

    m_windowPtr->clear();

    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->render(m_windowPtr);
        }
    }

    m_engineGUI.render(m_windowPtr);
    m_windowPtr->display();
}

void BaseApp::destroy() {
    m_engineGUI.destroy();
}
