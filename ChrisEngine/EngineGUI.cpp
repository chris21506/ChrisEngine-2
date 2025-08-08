// EngineGUI.cpp - ChrisEngine

#include "EngineGUI.h"
#include "Window.h"
#include "Actor.h"

void EngineGUI::init(const EngineUtilities::TSharedPointer<Window>& window) {
    // Inicialización de la GUI
}

void EngineGUI::update(const EngineUtilities::TSharedPointer<Window>& window,
    sf::Time deltaTime) {
    // Actualización de la GUI
}

void EngineGUI::render(const EngineUtilities::TSharedPointer<Window>& window) {
    // Renderizado de la GUI
}

void EngineGUI::destroy() {
    // Liberación de recursos de la GUI
}

void EngineGUI::processEvent(const sf::Window& window, const sf::Event& event) {
    // Procesamiento de eventos de la GUI
}

void EngineGUI::setupGreyGUIStyle() {
    // Configuración del estilo gris
}

void EngineGUI::setupDarkGUIStyle() {
    // Configuración del estilo oscuro
}

void EngineGUI::barMenu() {
    // Creación de la barra de menú
}

void EngineGUI::outliner(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
    // Vista jerárquica de actores
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
    // Control de edición de vectores 2D
}
