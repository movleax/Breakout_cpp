#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

bool intersects(sf::Shape* A, sf::Shape* B);
bool intersects(sf::CircleShape* c, sf::RectangleShape* r);
bool intersects(sf::RectangleShape* A, sf::RectangleShape* B);
bool intersects(sf::CircleShape* A, sf::CircleShape* B);

bool contains(const sf::CircleShape& c, const sf::Vector2f& p) 
{
    sf::Vector2f center = c.getPosition();
    float a = (p.x - center.x);
    float b = (p.y - center.y);
    a *= a;
    b *= b;
    float r = c.getRadius() * c.getRadius();

    return ((a + b) < r);
}

bool intersects(sf::Shape* A, sf::Shape* B)
{
    RectangleShape* shape_A_Rect = dynamic_cast<RectangleShape*> (A);
    RectangleShape* shape_B_Rect = dynamic_cast<RectangleShape*> (B);
    CircleShape* shape_A_Circle = dynamic_cast<CircleShape*> (A);
    CircleShape* shape_B_Circle = dynamic_cast<CircleShape*> (B);

    // A    B
    // Rect Rect
    if (shape_A_Rect != NULL && shape_B_Rect != NULL)
    {
        return intersects(shape_A_Rect, shape_B_Rect);
    }
    // Rect Circle
    else if (shape_A_Rect != NULL && shape_B_Circle != NULL)
    {
        return intersects(shape_B_Circle, shape_A_Rect);
    }
    // Circle Circle
    else if (shape_A_Circle != NULL && shape_B_Circle != NULL)
    {
        return intersects(shape_A_Circle, shape_B_Circle);
    }
    // Circle Rect
    else if (shape_A_Circle != NULL && shape_B_Rect != NULL)
    {
        return intersects(shape_A_Circle, shape_B_Rect);
    }

}

bool intersects(sf::CircleShape* circle, sf::RectangleShape* rect)
{
    Vector2f circleDistance(0, 0) = circle->getPosition() - rect->getPosition();
    circleDistance.x = abs(circleDistance.x);
    circleDistance.y = abs(circleDistance.y);

    if (circleDistance.x > (rect.width / 2 + circle.r)) { return false; }
    if (circleDistance.y > (rect.height / 2 + circle.r)) { return false; }

    if (circleDistance.x <= (rect.width / 2)) { return true; }
    if (circleDistance.y <= (rect.height / 2)) { return true; }

    cornerDistance_sq = (circleDistance.x - rect.width / 2) ^ 2 +
        (circleDistance.y - rect.height / 2) ^ 2;

    return (cornerDistance_sq <= (circle.r ^ 2));
}

// circle and rectangle collision
bool intersects(sf::CircleShape* c, sf::RectangleShape* r) 
{
    sf::FloatRect fr = r->getGlobalBounds();
    sf::Vector2f topLeft(fr.left, fr.top);
    sf::Vector2f topRight(fr.left + fr.width, fr.top);
    sf::Vector2f botLeft(fr.left, fr.top + fr.height);
    sf::Vector2f botRight(fr.left + fr.width, fr.top + fr.height);

    return contains(*c, topLeft) ||
        contains(*c, topRight) ||
        contains(*c, botLeft) ||
        contains(*c, botRight);
}

// rectangle on rectangle collision
bool intersects(sf::RectangleShape* A, sf::RectangleShape* B) 
{
    // can use this for rectangle on rectangle collision
    return A->getGlobalBounds().intersects(B->getGlobalBounds());
}

// circle on circle collision
bool intersects(sf::CircleShape* A, sf::CircleShape* B)
{
    Vector2f diff = B->getPosition() - A->getPosition();

    float magnitude = sqrtf(powf(diff.x,2) + powf(diff.y,2));
    float totalRadius = A->getRadius() + B->getRadius();

    return magnitude < totalRadius;
}