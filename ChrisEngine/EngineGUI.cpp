// EngineGUI.cpp - ChrisEngine

#include "EngineGUI.h"
#include "Window.h"
#include "Actor.h"

void EngineGUI::init(const EngineUtilities::TSharedPointer<Window>& window) {
    // Inicializaci�n de la GUI
}

void EngineGUI::update(const EngineUtilities::TSharedPointer<Window>& window,
    sf::Time deltaTime) {
    // Actualizaci�n de la GUI
}

void EngineGUI::render(const EngineUtilities::TSharedPointer<Window>& window) {
    // Renderizado de la GUI
}

void EngineGUI::destroy() {
    // Liberaci�n de recursos de la GUI
}

void EngineGUI::processEvent(const sf::Window& window, const sf::Event& event) {
    // Procesamiento de eventos de la GUI
}

void EngineGUI::setupGreyGUIStyle() {
    // Configuraci�n del estilo gris
}

void EngineGUI::setupDarkGUIStyle() {
    // Configuraci�n del estilo oscuro
}

void EngineGUI::barMenu() {
    // Creaci�n de la barra de men�
}

void EngineGUI::outliner(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
    // Vista jer�rquica de actores
}

void EngineGUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
    // Consola de mensajes
}

void EngineGUI::inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
    // Inspector de propiedades de actores
}

void EngineGUI::vec2Control(const std::string& label,
    float* values,
    float resetValues,
    float columnWidth) {
    // Control de edici�n de vectores 2D
}
