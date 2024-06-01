#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float x, float y)
        : defaultSize({ x, y }), enlargedSize({ x * 2, y * 2 }),
        currentSize(defaultSize), colorTransitionTime(3.0f),
        elapsedTime(0.0f) {
        m_rectangle.setSize(defaultSize);
        m_rectangle.setOrigin({ x / 2, y / 2 });
        m_rectangle.setFillColor(sf::Color::Green);
        m_rectangle.setOutlineThickness(x / 100);
        m_rectangle.setOutlineColor(sf::Color::Yellow);
    }

    void update(sf::Vector2u limits, float deltaTime) {
        if (isHovered) {
            elapsedTime += deltaTime;
            if (elapsedTime > colorTransitionTime) {
                elapsedTime = colorTransitionTime;
            }

            float progress = elapsedTime / colorTransitionTime;
            sf::Uint8 redValue = static_cast<sf::Uint8>(255 * progress);
            sf::Uint8 greenValue = static_cast<sf::Uint8>(255 * (1.0f - progress));

            m_rectangle.setFillColor(sf::Color(redValue, greenValue, 0));

            currentSize.x = defaultSize.x + (enlargedSize.x - defaultSize.x) * progress;
            currentSize.y = defaultSize.y + (enlargedSize.y - defaultSize.y) * progress;
            m_rectangle.setSize(currentSize);

            if (progress >= 1.0f) {
                jump(limits);
                reset();
            }
        }
        else {
            reset();
        }
    }

    void draw_into(sf::RenderWindow& window) {
        window.draw(m_rectangle);
    }

    bool is_position_in(sf::Vector2f position) {
        isHovered = m_rectangle.getGlobalBounds().contains(position);
        return isHovered;
    }

    void jump(sf::Vector2u limits) {
        m_rectangle.setPosition(rand() % limits.x, rand() % limits.y);
    }

private:
    void reset() {
        elapsedTime = 0.0f;
        m_rectangle.setFillColor(sf::Color::Green);
        m_rectangle.setSize(defaultSize);
        isHovered = false;
    }

    sf::RectangleShape m_rectangle;
    sf::Vector2f defaultSize;
    sf::Vector2f enlargedSize;
    sf::Vector2f currentSize;
    float colorTransitionTime;
    float elapsedTime;
    bool isHovered = false;
};