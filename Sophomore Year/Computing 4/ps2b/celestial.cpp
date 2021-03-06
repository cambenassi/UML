#include <iostream>
#include "celestial.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iomanip>

using namespace std;

CelestialBody::CelestialBody(double radius, double xU, double yU, double xVelU, double yVelU, double massU, string nameU){
    x = xU;
    y = yU;
    xVel = xVelU;
    yVel = yVelU;
    mass = massU;
    name = nameU;

    texture.loadFromFile(name);
    sprite.setTexture(texture);
    sprite.move(x, y);

}

CelestialBody::CelestialBody(){
    name = "default";
}

istream& operator>>(istream& os, CelestialBody& input){
    double xU, yU, xVelU, yVelU, massU;
    string nameU;

    cin >> xU >> yU >> xVelU >> yVelU >> massU >> nameU;

    input.x = xU;
    input.y = yU;
    input.xVel = xVelU;
    input.yVel = yVelU;
    input.mass = massU; 
    input.name = nameU;

    input.texture.loadFromFile(input.name);
    input.sprite.setTexture(input.texture);
    input.sprite.move(input.x, input.y);

    return os;
}

void CelestialBody::setRadius(double radiusU){
    radius = radiusU;
}

void CelestialBody::draw(sf::RenderTarget& SolarSystem, sf::RenderStates states) const{
    SolarSystem.draw(sprite);
}

void CelestialBody::setXVel(double velocity){
    xVel = velocity;
}


void CelestialBody::setYVel(double velocity){
    yVel = velocity;
}

void CelestialBody::scaleCoords(){
    x = (x / radius) * 300 + 300;
    y = (y / radius) * 300 + 300;
}

void CelestialBody::unscaleCoords(){
    x = (x - 300) / 300 * radius;
    y = (y - 300) / 300 * radius;
}

ostream& operator<<(ostream& os, const CelestialBody& input){
    cout << scientific << right << setw(15) << input.x << right << setw(15) << input.y << right << setw(15) << input.xVel;
    cout << scientific << right << setw(15) << input.yVel << right << setw(15) << input.mass << right << setw(15) << input.name << endl;

    return os;
}