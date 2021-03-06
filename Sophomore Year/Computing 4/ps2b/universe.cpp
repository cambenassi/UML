#include <iostream>
#include "universe.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <math.h>

using namespace std;

Universe::Universe(int numParticles, double radius){
    //pass numParticles, for loop, call new CelestialBody shared ptr, cin data and push to vector
    for(int i = 0; i < numParticles; i++){
        shared_ptr<CelestialBody> ptr (new CelestialBody);
        ptr->setRadius(radius);
        cin >> *ptr; 
        objects.push_back(ptr);
    }
        
}

void Universe::step(double seconds){
    
    double G = 6.67e-11, netForceX, netForceY, Fx, Fy, accelX = 0, accelY = 0;

    for(auto body : objects){
        for (auto p = objects.begin(); p != objects.end(); p++){
            if(body == *p)continue;

            double deltaX = (*p)->x - body->x;
            double deltaY =  body->y - (*p)->y;

            double r = sqrt((deltaX * deltaX) + (deltaY * deltaY));
            double F = (G * body->mass * (*p)->mass) / (r * r);

            Fx = F * deltaX / r;
            Fy = F * deltaY / r;

            netForceX = netForceX + Fx;
            netForceY = netForceY + Fy;
        }
        accelX = netForceX / body->mass;
        accelY = netForceY / body->mass;

        body->xVel = body->xVel + (accelX * seconds);
        body->yVel = (body->yVel + (accelY * seconds));

        netForceX = 0;
        netForceY = 0;
    }

    for(auto body : objects){
        body->x = body->x + (seconds * body->xVel);
        body->y = (body->y - (seconds * body->yVel));
        body->scaleCoords();
        body->sprite.setPosition(body->x, body->y);
        body->unscaleCoords();
    }
}
