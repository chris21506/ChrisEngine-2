// Window.cpp - ChrisEngine

#include "Window.h"
#include "EngineGUI.h"

Window::Window(int width, int height, const std::string& title) {
    // Crear la ventana SFML
    m_windowPtr = EngineUtilities::MakeUnique<sf::RenderWindow>(
        sf::VideoMode(width, height), title
    );
    m_view = m_windowPtr->getDefaultView();
}

Window::~Window() {
    destroy();
}

void Window::handleEvents(EngineGUI& engineGUI) {
    sf::Event event;
    while (m_windowPtr->pollEvent(event)) {
        // Pasar eventos a la GUI
        engineGUI.processEvent(*m_windowPtr, event);

        if (event.type == sf::Event::Closed) {
            m_windowPtr->close();
        }
    }
}

bool Window::isOpen() const {
    return m_windowPtr && m_windowPtr->isOpen();
}

void Window::clear(const sf::Color& color) {
    if (m_windowPtr) {
        m_windowPtr->clear(color);
    }
}

void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states) {
    if (m_windowPtr) {
        m_windowPtr->draw(drawable, states);
    }
}

void Window::display() {
    if (m_windowPtr) {
        m_windowPtr->display();
    }
}

void Window::update() {
    deltaTime = clock.restart();
}

void Window::render() {
    // Aquí puedes poner la lógica de renderizado si es necesario
}

void Window::destroy() {
    if (m_windowPtr) {
        m_windowPtr->close();
        m_windowPtr.reset();
    }
}
