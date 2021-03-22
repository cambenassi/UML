#ifndef celestial_h
#define celestial_h

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class CelestialBody : public sf::Drawable{
    public:
        CelestialBody(double radius, double xU, double yU, double xVelU, double yVelU, double massU, string nameU);
        CelestialBody();
        friend istream& operator>>(istream& os, CelestialBody& input);
        void setRadius(double radiusU);

        double x, y, xVel, yVel, mass, radius;
        string name;
        sf::Sprite sprite;
        sf::Texture texture;

    private:        
        virtual void draw(sf::RenderTarget& SolarSystem, sf::RenderStates states) const;
};
#endif