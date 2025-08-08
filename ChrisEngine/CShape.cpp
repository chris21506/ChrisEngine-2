// CShape.cpp - ChrisEngine

#include "CShape.h"
#include "Window.h"

void CShape::createShape(ShapeType shapeType) {
    // Crear la forma basada en shapeType
}

void CShape::start() {
    // Lógica de inicio
}

void CShape::update(float deltaTime) {
    // Actualización por frame
}

void CShape::render(const EngineUtilities::TSharedPointer<Window>& window) {
    // Renderizar la forma
}

void CShape::destroy() {
    // Liberar recursos
}

void CShape::setPosition(float x, float y) {
    if (m_shapePtr) {
        m_shapePtr->setPosition(x, y);
    }
}

void CShape::setPosition(const sf::Vector2f& position) {
    if (m_shapePtr) {
        m_shapePtr->setPosition(position);
    }
}

void CShape::setFillColor(const sf::Color& color) {
    if (m_shapePtr) {
        m_shapePtr->setFillColor(color);
    }
}

void CShape::setRotation(float angle) {
    if (m_shapePtr) {
        m_shapePtr->setRotation(angle);
    }
}

void CShape::setScale(const sf::Vector2f& scl) {
    if (m_shapePtr) {
        m_shapePtr->setScale(scl);
    }
}

void CShape::setTexture(const EngineUtilities::TSharedPointer<Texture>& texture) {
    if (m_shapePtr && texture) {
        m_shapePtr->setTexture(texture.Get());
    }
}
