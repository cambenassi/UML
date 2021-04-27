# Comp IV: Project Portfolio

### Cameron Benassi - Spring 2021



## Contents

PS0 - Hello World with SFML ................................................................................ 3
	Synopsis ............................................................................................................ 3
	Implementation .................................................................................................. 3
	Key Algorithms, Data Structures, O.O. Design .................................................. 3 
	What was learned? ............................................................................................ 4
	Source Code ...................................................................................................... 4

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS1 - Linear Feedback Shift Register and Image Encoding ................................. 7
	Synopsis ............................................................................................................ 7
	Implementation .................................................................................................. 8
	Key Algorithms, Data Structures, O.O. Design .................................................. 8 
	What was learned? ............................................................................................ 8
	Source Code ...................................................................................................... 9

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS2 - N-Body Simulation ..................................................................................... 18
	Synopsis ........................................................................................................... 18
	Implementation ................................................................................................. 18
	Key Algorithms, Data Structures, O.O. Design ................................................. 19
	What was learned? ........................................................................................... 19
	Source Code ..................................................................................................... 20

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS3 - DNA Sequence Alignment .......................................................................... 30
	Synopsis ........................................................................................................... 30
	Implementation ................................................................................................. 30
	Key Algorithms, Data Structures, O.O. Design ................................................. 31 
	What was learned? ........................................................................................... 31
	Source Code ..................................................................................................... 31

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS4 - Synthesizing a Plucked String Sound ........................................................ 39
	Synopsis ........................................................................................................... 39
	Implementation ................................................................................................. 40
	Key Algorithms, Data Structures, O.O. Design ................................................. 40
	What was learned? ........................................................................................... 41
	Source Code ..................................................................................................... 41

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS5 - Recursive Graphics ..................................................................................... 51
	Synopsis ............................................................................................................ 51
	Implementation .................................................................................................. 51
	Key Algorithms, Data Structures, O.O. Design .................................................. 52 
	What was learned? ............................................................................................ 52
	Source Code ...................................................................................................... 52

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

PS6 - Kronos Time Clock ...................................................................................... 60
	Synopsis ............................................................................................................ 60
	Implementation .................................................................................................. 60
	Key Algorithms, Data Structures, O.O. Design .................................................. 61
	What was learned? ............................................................................................ 61
	Source Code ...................................................................................................... 61

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Time to Complete: 5 hours

<div style="page-break-after: always"></div>

# PS0 - Hello World with SFML

## Synopsis

As an introduction to the curriculum in Computing IV, PS 0 was an entry level project focusing on setting up a Linux programming environment (either online via SSH or local via a virtual machine), along with installing a key library needed for the course, SFML. 

Once both objectives were complete, the second half of the assignment was focused on running SFML's given "Hello World" code, and expanding on it. The "Hello World" code in question displayed a green circle on a window, just to ensure that everything in the SFML library was running properly. It was the student's job to then make the sprite move, make it respond to keystrokes, and to come up with one unique idea to add to the project. 

## Implementation

A while loop was used to open a window for the duration of the program's life. Inside that loop, if statements were used to determine what keys were pressed, and depending on which key, what action to apply to the sprite. An additional if statement was also used to close the window if the user clicked the X in the top left.

## Key Algorithms, Data Structures or O.O. Designs

While this was a relatively simple assignemnt compared to some of the later ones, there were many examples of key data structures in the SFML library that show up many times throughout the semester. For example, this assignment taught the basics of some very key SFML objects, such as sf::RenderWindow, sf::Event, sf::Keyboard, and sf::Sprite. Each of these play a massive role in assignments down the line, with them being the very building blocks that the SFML is based on. Each of these objects all have unique member functions, which were given a breif introduction during this assignment. 

## What was learned?

As previously mentioned, this assignment taught various key aspects of the SFML library, including key member variables and member functions that would be used in essentially every other assignment in the future. Overall, this assignment ensured that students had the proper programming setup, along with an essential library installed properly in order to ensure success throughout the rest of the semester.

## Source Code

```c++
// main.cpp
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "ps0");
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    int x = 0, y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                x = 0;
                y = -10;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                x = -10;
                y = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                x = 0;
                y = 10;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                x = 10;
                y = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                sprite.rotate(45.f);
            }

            sprite.move(x, y);
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
```

![screenshot](/Users/cambenassi/Documents/Code/UML/Sophomore Year/Computing 4/ps0/screenshot.png)

*Screenshot of output*

<div style="page-break-after: always"></div>

# PS1 - LFSR and Image Encoding

PS1 is split into PS1a and PS1b. The reflection for this assignment will also be split to showcase aspects from each part.

## Synopsis (PS1a)

Similar to PS0, PS1 as a whole was used as an introduction to a different library which was also used all throghout the semester, Boost. The task for this assignment, specifically for PS1a, was to create a class object of a Linear Feedback Shift Register, and to test it using Boost. A Linear Feedback Shift Register is a system of generating pseudorandom numbers by XORing bits in a set seed. After bits are XOR'd, the new bit is then placed at the end of the seed, along with moving each number up a position, removing the first element. The result is a pseudorandom number. For this assignment, we were tasked with programming a class which would perform the operation, along with testing it with given tests and some we had to write ourselves.

## Synopsis (PS1b)

In part b, the code (minus test.cpp) was taken and used as a way of encoding an image. The program was to run a LFSR step on each pixel of an image, and then setting the result to the color of said pixel. This also had to be reversable, since the number provided by the LFSR is pseudorandom. This means that if the user inputted an encrypted photo into the program, they would get the original photo as an output. The program would take the name of a file input, output, and LFSR seed as command line arguments.

## Implementation (PS1a)

For part A, the class FibLFSR was written. This class takes a starting seed, and stores it into a string variable. From there, the user can use the step() function, which iterates one step of the simulation, or use the generate(int k) function, which performs the step() function k times. The class has the << operator overloaded as well. Test.cpp was then created, and using Boost/their propriatry .cpp file setup, the output of step() and generate() were tested against expected results. Tests were also written to test seeds that were too long and too short, along with illegal letters in the seed.

## Implementation (PS1b)

In PhotoMagic.cpp, an SFML image variable was created and assigned to the image the user wished to encrypt. After properly assigned, it was passed to a newly written function, generate(), along with a seed for the LFSR. This generate function took both an sf::Image variable and one of our custom LFSR objects. It then ran our generate(8) function, and OR'd it with the current color of every pixel for the image, via a nested for loop. The function returns nothing, but instead edits the original sf::Image object. The rest of the program sets up a SFML window and displays both the original and encoded images side by side, along with saving them to the user's local directory.

## Key Algorithms, Data Structures or O.O. Designs

In this assignment, classes were essential in creating a solution. Because of our custom class, we were able to create an object that stores a unique string, which is useful when trying to perform a different number of step() calls on different variables.

## What was learned?

In this assignment, I learned about the process of LFSR, which was a new concept to me at the time. It also taught me how I could encode an image by changing the colors of each pixel, along with introducing Boost libraries. Specifically for PS1a, it was an entry point into writing custom boost tests, along with setting up a proper .cpp to run them, a skill which would prove very useful in later assignments. 

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = PhotoMagic.o FibLFSR.o
DEPS = FibLFSR.cpp FibLFSR.h PhotoMagic.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PhotoMagic

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
```

```c++
// PhotoMagic.cpp
#include <iostream>
#include "FibLFSR.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
 
using namespace std;

void transform(sf::Image& image, FibLFSR* seed);

int main(int argc, char* argv[]){
    //get file names & seed, call transform, then save
    sf::Image image;
    if(!image.loadFromFile(argv[1]))
        return -1;
    FibLFSR seed = {argv[3]};

    transform(image, &seed);
    
    if(!image.saveToFile(argv[2]))
        return -1;

    //creating windows
    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");
    
    sf::Texture originalText;
    originalText.loadFromFile(argv[1]);
    sf::Texture encryptedText;
	encryptedText.loadFromImage(image);
    
    sf::Sprite originalSprite;
    originalSprite.setTexture(originalText);
	sf::Sprite encryptedSprite;
	encryptedSprite.setTexture(encryptedText);
    
    while (window1.isOpen() && window2.isOpen()) { 
        sf::Event event;
        while (window1.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(originalSprite);
        window1.display();
        window2.clear();
        window2.draw(encryptedSprite);
        window2.display();
    }

    return 0;
}

void transform(sf::Image& image, FibLFSR* seed){
    sf::Color p;
    sf::Vector2u size = image.getSize();

    for(unsigned int y = 0; y < size.y; y++){
        for (unsigned int x = 0; x < size.x; x++){
            p = image.getPixel(x, y);
            p.r ^= seed->generate(8);;
            p.b ^= seed->generate(8);;
            p.g ^= seed->generate(8);;
            image.setPixel(x, y, p);
        }
    }

}
```

```c++
// FibLFSR.h
#ifndef FibLFSR_h
#define FibLFSR_h
using namespace std;

class FibLFSR {
    private:
        string bits;
    public:
        FibLFSR(string seed);
        int step();
        int generate(int k);
        friend ostream& operator<<(ostream& os, const FibLFSR& number);

};

#endif
```

``` c++
// FibLFSR.cpp
#include <iostream>
#include "FibLFSR.h"
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

FibLFSR::FibLFSR(string seed){
    //is the seed to short? pad with 0's
    if(seed.length() < 16){
        int pad = 16 - seed.length();
        string temp;
        while (pad > 0){
            temp += '0';
            pad--;
        }
        temp += seed;
        seed = temp;
    }
    //is the seed to long? trim it to 16 MSB
    if(seed.length() > 16){
        string::iterator it = seed.end();
        string temp;
        while (temp.length() <= 16){
            temp += *it;
            it--;
        }
        reverse(temp.begin(), temp.end());
        seed.clear();
        seed = temp;
        seed.pop_back();
    }
    //are there any letters? replace with 0's
    int i = 0;
    while(seed[i]){
        if(isalpha(seed[i]))
            seed[i] = '0';
        i++;
    }

    bits = seed;
}

int FibLFSR::step(){
    int length = bits.length();
    int temp = bits.at(0) ^ bits.at(2);
    temp ^= bits.at(3);
    temp ^= bits.at(5);

    for (int i = 0; i != length - 1; i++)
        bits.at(i) = bits.at(i + 1);

    string conv = to_string(temp);
    bits.at(bits.length() - 1) = conv.at(0);

    return temp;
}

int FibLFSR::generate(int k){
    int result = 0;

    for (int i = 0; i < k; i++){
        result = result * 2 + step();
    }

    return result;
}

ostream& operator<<(ostream& os, const FibLFSR& number){
    cout << number.bits;

    return os;
}
```

``` c++
// test.cpp
// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

//tests to see if seed is too short is handled correctly
//successful if seed is padded with 0's
BOOST_AUTO_TEST_CASE(short_bit_test){
  FibLFSR l("10");
  
  BOOST_REQUIRE(l.generate(9) == 0);
  BOOST_REQUIRE(l.step() == 1);
}

//tests to see if seed that is too long is handled correctly
//successful if seed is trimmed to the 16 MSB
BOOST_AUTO_TEST_CASE(long_bit_test){
  FibLFSR l("100101011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
}

//tests to see if seed that contains letters is handled correctly
//successful if letters are replaced with 0's
BOOST_AUTO_TEST_CASE(letters){
  FibLFSR l("1d11011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
}
```

![encode](/Users/cambenassi/Documents/Code/UML/Sophomore Year/Computing 4/ps1b/encode.png)

*Screenshot of output*

<div style="page-break-after: always"></div>

# PS2 - N-Body Simulaton

PS2 is split into PS2a and PS2b. The reflection for this assignment will also be split to showcase aspects from each part.

## Synopsis (PS2a)

For this assignment, we were tasked with implementing a graphical interface for a universe simulation. Given a text file with information about each planet, along with images for each, we had to create an SFML window which displayed each planet at its proper X/Y coordinate which was given to us in the text file planets.txt. Ontop of X/Y coordinates, X/Y velocity, mass, and name also had to be stored. The name of the text file was to be read through command line arguments.

## Synopsis (PS2b)

In part b, we were tasked with adding a step() function to the Universe class, which takes a time parameter and calculates the new values for the X/Y Velocity of a CelestialBody object. The command line arguments were also altered, with total runtime of the simulation and time increments being added. Finally, we were tasked with making each of our objects move, based on the movements of other objects. Essentially, we were to take what we made in part a, and implement the physics for it.

## Implementation (PS2a)

For this assignment, there were 2 classes that had to be created. Universe, and CelestialBody. In Universe, a vector of shared pointers of CelestialBody objects were stored. The size of this vector would be determined by a variable passed to the constructor, numParticles, which corresponds to the amount of bodies in the solar system. Then, in a for loop, a new CelestialBody object was created, loaded with information from planets.txt, and stored in the vector. The constructor of CelestialBody handled gathering all of the information from the document specified in the command line arguments. CelestialBody also contained an overloaded draw() function, whcih draws the body onto the sf::RenderWindow object which is passed into it. The main file, NBody.cpp, consists of scanning the command line arguments for the number of solar bodies, creating a Universe object with said amount, then using the overloaded draw() function to display them onto an SFML window.

## Implementation (PS2b)

As stated above, we had to add a function called step() which calculated new velocity values. In this new function, a double variable *seconds* was taken and calculations were made based on said variable. Various calculations were done to find Pairwise force, Net force, and finally acceleration. This was then applied to the velocity, which gives us our new value. These equations were inside a nested for loop, iterating through all of the objects in the Universe class. At the end of the function, a final for loop iterated through all of the objects, updating the X/Y positions based on their new velocity values and the *seconds* variable, along with setting the updated position for the sprite in the CelestialBody class. The NBody.cpp file was then updated to accomodate for the new functions, the new command line arguments, and also now plays a song when the simulation is running.

## Key Algorithms, Data Structures or O.O. Designs

For this assignment, classes were used heavily. They were the basic building blocks for which the Universe object and each CelestialBody object were based on. With them, we were able to have independent planets, which each had their own physics data, along with one big parent object, which stored them all in a clean place.

## What was learned?

For this assignment, this was the first time that I personally have used smart pointers in any form. It showed me how they can be useful with memory management and also with improving the readability of my code. It also gave me more practice with SFML, as this was the first real assignment which required a constant updating of sprites and their positions, so I had to find a way to update the position of each object's sprite after each new calculation.

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = NBody.o universe.o celestial.o
DEPS = NBody.cpp celestial.h celestial.cpp universe.h universe.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = NBody

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
```

```c++
// NBody.cpp
#include <iostream>
#include "celestial.h"
#include "universe.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]){
    int numParticles;
    double radius, endTime, deltaTime, currentTime = 0;

    endTime = atof(argv[1]);
    deltaTime = atof(argv[2]);

    cin >> numParticles >> radius;
    Universe test(numParticles, radius);

    sf::RenderWindow SolarSystem(sf::VideoMode(600, 600), "Solar System");
    SolarSystem.setFramerateLimit(60);

    sf::SoundBuffer buffer;
    sf::Sound sound;
    if(!buffer.loadFromFile("halo.wav"))
        return -1;
    sound.setBuffer(buffer);
    sound.play();

    while(SolarSystem.isOpen()){
        sf::Event event;
        while(SolarSystem.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                SolarSystem.close();
            }
        if(currentTime < endTime){
            test.step(deltaTime);
            SolarSystem.clear();
            for(auto body : test.objects)
                SolarSystem.draw(*body);
            SolarSystem.display();


            currentTime += deltaTime;
        }
        else
            SolarSystem.close();
    }
    
    for(auto body : test.objects)
        cout << *body;
    

    return 0;
}
```

```c++
// universe.h
#ifndef universe_h
#define universe_h

#include <vector>
#include <memory>
#include "celestial.h"

using namespace std;

class Universe{
    public:
        Universe(int numParticles, double radius);
        vector<shared_ptr<CelestialBody>> objects;

        void step(double seconds);
    private:
        

};

#endif
```

```c++
// celestial.h
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
        friend ostream& operator<<(ostream& os, const CelestialBody& input);
        void setRadius(double radiusU);
        void setXVel(double velocity);
        void setYVel(double velocity);
        void scaleCoords();
        void unscaleCoords();

        double x, y, xVel, yVel, mass, radius;
        string name;
        sf::Sprite sprite;
        sf::Texture texture;

    private:        
        virtual void draw(sf::RenderTarget& SolarSystem, sf::RenderStates states) const;
};
#endif
```

```c++
// universe.cpp
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
```

```c++
// celestial.cpp
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
```

![screenshot.png](/Users/cambenassi/Documents/Code/UML/Sophomore Year/Computing 4/ps2a/screenshot.png)

*Output of program*

<div style="page-break-after: always"></div>

# PS3 - DNA Sequence Alignment

## Synopsis

For this assignment, we were tasked with creating a program that would calculate the lowest cost for aligning two DNA strands. We would be provided with two strands of DNA (Ex. "AACG" & "AAG"), and depending on how different they were based on certain criteria, the program would calculate the cost of aligning the two, along with providing the best match. The cost breakdown is as follows - inserting a gap = 2, allign two characters that mismatch = 1, allign two characters that match = 0. A clock must also be run in order to print the total elapsed time at the end of the program.

## Implementation

We first start by starting a sf::Clock object, to track the total time of the calculations. An ED class was written to hold both strings, and to perform all the math. After scanning in the strings through a file named in the command line arguments, a new ED object is made. To implement the calculations, I went down the route of populating an NxM sized matrix, where N is the size of the first string, and M is the size of the second. This matrix was stored in a class, ED, which held the previously mentioned matrix, along with both DNA strings, and the proper member functions needed for the rest of the program. The matrix starts off as an int ** data member, but in the constructor, an array is created where each element also hosts an array, creating a 2d matrix of NxM elements. After the array is created, it must be populated, which is done by optDistance(), another member function. The function starts at matrix[n] [m], populating it with 0. As it goes down the array, the function performs calculations to calculate the edit distance between the two strings at that moment, continuing until the entire array is full. StringAllignment() then finds the path of lowest cost, starting at matrix [n] [m], comparing the current value with values around until it finds the minimum, until matrix[0] [0] is reached. The function then returns a new DNA string based on the path it took throughout the matrix, which is the least expensive way to allign the two strings. At the end of these calculations, we return to the main.cpp file where the clock is stopped, and everything is printed out.

## Key Algorithms, Data Structures or O.O. Designs

The key concpet that this assignment revolves around are arrays, more specifically 2 dimensional arrays. The main calculations run off of the strings that are stored inside of a two dimensional array, which I believed was the best way to make sense of what needed to be done to get the correct result. Although vectors would have worked as well, I believed that my array setup was simpler, and since it is an array of int **, it may also take less memory than vectors.

## What was learned?

Although I have used 2d matrices before, I have not used them with advanced calculations as I did with this assignment. This assignment helped me have a better understanding with how arrays, one and two dimensional, are stored in memory, and how to work with them and their elements.

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Werror -pedantic
OBJ = main.o edClass.o
DEPS = main.cpp edClass.cpp edClass.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = ED


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
```

```c++
// main.cpp
#include <iostream>
#include "edClass.h"

#include <SFML/System.hpp>

int main(int argc, char* argv[]){
    ED test;
    sf::Clock clock;
    sf::Time t;

    std::cin >> test;
    test.~ED();

    t = clock.getElapsedTime();
    std::cout << "\nExecution time is " << t.asSeconds() << " seconds\n";

    return 0;
}
```

```c++
// edClass.h
#ifndef edClass_h
#define edClass_h

class ED {
    public:
        //constructors & destructor
        ED(std::string a, std::string b);
        ED();
        //~ED();
        //overloaded << operator
        friend std::istream& operator>>(std::istream& os, ED& dest);
        //member functions
        static int penalty(char a, char b);
        static int min(int a, int b, int c);
        int optDistance();
        std::string stringAllignment();
        //data members
        std::string dnaA, dnaB;
        int **matrix;
};

#endif
```

```c++
// edClass.cpp
#include <iostream>
#include <iomanip>
#include "edClass.h"


//constructors & destructor
ED::ED(std::string a, std::string b){
    dnaA = a;
    dnaB = b;

    int m = a.length() + 1, n = b.length() + 1;
    
    matrix = new int *[m];
    for(int i = 0; i < m; i++)
        matrix[i] = new int [n];

    optDistance();
    
}

ED::ED(){
    dnaA = "blank";
    dnaB = "blank";
}

//ED::~ED() {delete[] matrix;};
//overloaded operators
std::istream& operator>>(std::istream& os, ED& dest){
    std::string tempA, tempB;
    std::cin >> tempA >> tempB;
    ED tempED(tempA, tempB);
    
    dest = tempED;
    
    return os;
}
//member functions
int ED::penalty(char a, char b){
    if(a == b)
        return 0;
    else   
        return 1;
}

int ED::min(int a, int b, int c){
    return std::min({a, b, c});
}

int ED::optDistance(){
    int m = dnaA.length() + 1;  //m - 1 = go up 1
    int n = dnaB.length() + 1;  //n - 1 = go left 1
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    //populating y axis
    for(int i = m - 1; i >= 0; i--){
        if(i != m - 1)
            matrix[i][n - 1] = matrix[i + 1][n - 1] + 2;
        else   
            matrix[i][n - 1] = 0;
    }
    //populating x axis
    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1)
            matrix[m - 1][i] = matrix[m - 1][i + 1] + 2;
        else   
            matrix[m - 1][i] = 0;
    }
    //populating middleß
    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            matrix[i][j] = min(matrix[i + 1][j] + 2, matrix[i][j + 1] + 2, penalty(dnaA.at(i), dnaB.at(j)) + matrix[i + 1][j + 1] );
        }
    }
    //printing

    std::cout << stringAllignment();

    return 1;
}

std::string ED::stringAllignment(){
    int m = dnaA.length(), i = 0;  //m - 1 = go up 1
    int n = dnaB.length(), j = 0, temp, offset = 0, totalCost = 0;  //n - 1 = go left 1
    std::string costs, final;

    while(i != m && j != n){
        if(penalty(dnaA.at(i), dnaB.at(j + offset)) == 0){
            i++;
            j++;
            costs += '0';
        }
        else{
            temp = min(matrix[i + 1][j], matrix[i][j + 1], matrix[i + 1][j + 1]);
            if(temp == matrix[i + 1][j] && (matrix[i][j] - temp == 2)){
                dnaB.insert(j + offset, "-");
                costs += "2";
                totalCost += 2;
                offset++;
                i++;
            }
            else{
                i++;
                j++;
                costs += '1';
                totalCost += 1;
            }

        }
    }
    final += "\nEdit distance = ";
    final += std::to_string(totalCost);
    final += "\nx  y  cost\n----------\n";
    for(i = 0; i < dnaA.length(); i++){
        final += dnaA.at(i);
        final += "  ";
        final += dnaB.at(i);
        final += "    ";
        final += costs.at(i);
        final += '\n';
    }

    return final;
}
```



![output](/Users/cambenassi/Documents/Code/UML/Sophomore Year/Computing 4/ps3/output.png)

*Output of program*

<div style="page-break-after: always"></div>

# PS4 - Synthesize a Plucked Sound

PS4 is split into PS4a and PS4b. The reflection for this assignment will also be split to showcase aspects from each part.

## Synopsis (PS4a)

While short, the goal of this assignment was essential in setting up for part b. In part a, we were tasked with creating a CircularBuffer class, which would later be essential in a simulation for a guitar. A circular buffer is a data structure where the end wraps around to the front. This class had to be able to have the standard fuctions that all data structures in C++ have (size(), isEmpty(), isFull(), enqueue(), dequeue(), peek() ). There were also certain C++ exceptions that had to be incorperated in order to ensure that our program would not break. Then, test.cpp had to be written in order to ensure that our code was throwing the right exceptions at the right time, which was tested with Boost. The code also had to pass cpplint, a style guide script.

## Synopsis (PS4b)

Taking our code from part a, we were tasked with tying it together into making a working simulation that outputs sound, depending on the key pressed. A class StringSound had to be created, which would contain a CircularBuffer object, along with other member functions needed perform the proper calculations needed to output the correct note. In the main file, KSGuitarSim.cpp, a std::vector of sf::Sound objects had to be filled by my calculations, then assigned to a key. 

## Implementation (PS4a)

For this task, I decided to implement this by creating a vector of int16_t objects in a CircularBuffer class. After the vector was created, I then added all of the functions listed above by calling the std::vector equivilant and returning the value. I then added the required C++ exceptions to the constructor, enqueue, dequeue, and peek. I then wrote test.cpp which creates various CircularBuffer objects and either checks that there is an exception thrown or no exception thrown. 

## Implementation (PS4 b)

As stated above, we had to implement a class called StringSound, which has various new functions (pluck(), tic(), sample(), time() ), and has a CircularBuffer object as a member object. The process of getting a value ready to push to a key in the main file starts by calling pluck(), which fills the CircularBuffer with random numbers, whcih I implemented with std::uniform_int_distribution. After the CircularBuffer is full, tic() is called repeatedly in order to generate the correct pitch of the note, depending on which key the note is going to end up being assigned to. Finally, the sound is ready to be pushed to a key. The CircularBuffer is then copied into a vector of sf::Buffer objects, whcih is then set to a vector of sf::Sound objects. Each sf::Sound object is then assigned to a keyboard. While loop for SFML is then implemented with key pressing detection for the proper keys, along with playing the right note that corresponds to which key has been pressed.

## Key Algorithms, Data Structures or O.O. Designs

For this assignment, std::vectors, queues, and classes were used the most. Inside of the CircularBuffer class, the actual buffer was made out of std::vectors, which were then formatted to mimic the results of a queue. This is because we needed the actions of a queue, but for it to loop around the front into the back, hence the name CircularBuffer. This was obviously built inside a class, which was also what the final StringSound class was made out of. 

## What was learned?

From this assignment, I learned about the Karplus-Strong string simulation in depth, which also showed me how some synthesizers worked. I was able to change various aspects of the sound just by changing various numbers around, which is how things like electric keyboards and other electronic instruments change what type of sound they can output. I also see now how a string of random numbers can turn into a predictable pitch, based on a few formulas.

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++17 -c -g -Og -Wall -Werror -pedantic
OBJ =  KSGuitarSim.o CircularBuffer.o StringSound.o
DEPS =  KSGuitarSim.cpp CircularBuffer.cpp CircularBuffer.h StringSound.cpp StringSound.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = KSGuitarSim


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)
```

```c++
// KSGuitarSim.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <math.h>

#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "CircularBuffer.h"
#include "StringSound.h"

#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound* gs);

int main(int argc, char* argv[]) {
    double CONCERT = 440.0;
    if (argv[1])
      if (!strcmp(argv[1], "harp"))
        CONCERT = 140.0;

    sf::RenderWindow window(sf::VideoMode(300, 200),
    "SFML Plucked String Sound Lite");
    sf::Event event;
    sf::SoundBuffer tempBuf;
    std::vector<sf::Int16> samples;
    std::vector<sf::Sound> sounds(37);
    std::vector<sf::SoundBuffer> buffs(37);
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    double freq;

    for (int16_t i = 0; i < keys.size(); i++) {
        int avoidLongInt = i;
        freq = CONCERT * pow(2, (avoidLongInt - 24) / 12.0);
        StringSound tempStringSound(freq);

        samples = makeSamples(&tempStringSound);
        buffs[i].loadFromSamples(&samples[i],
        samples.size(), 2, SAMPLES_PER_SEC);
        sounds[i].setBuffer(buffs[i]);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
          } else if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
              char key = static_cast<char>(event.text.unicode);
              for (int x = 0; x < (signed)keys.size(); x++) {
                  if (keys[x] == key) {
                    sounds[x].play();
                    break;
                    }
                  }
              }
            }
          }
      window.clear();
      window.display();
    }

    return 0;
}

std::vector<sf::Int16> makeSamples(StringSound* gs) {
  std::vector<sf::Int16> samples;

  gs->pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs->tic();
    samples.push_back(gs->sample());
  }

  return samples;
}
```

```c++
// CircularBuffer.h
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef SOPHOMORE_YEAR_COMPUTING_4_PS4B_CIRCULARBUFFER_H_
#define SOPHOMORE_YEAR_COMPUTING_4_PS4B_CIRCULARBUFFER_H_

#include <stdint.h>
#include <vector>

class CircularBuffer{
 public:
        explicit CircularBuffer(int capacity);
        int size();
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();

        // Data member
        std::vector<int16_t> ringBuffer;
};


#endif  // SOPHOMORE_YEAR_COMPUTING_4_PS4B_CIRCULARBUFFER_H_
```

```c++
// StringSound.h
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_
#define SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_

#include <vector>

#include <SFML/System.hpp>

#include "CircularBuffer.h"

class StringSound {
 public:
    // constructors & destructor
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound(const StringSound& obj) {}
    ~StringSound();
    // Member functions
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
// data members
 private:
    CircularBuffer* _cb;
    int _time;
};

#endif  // SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_
```

```c++
// CircularBuffer.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include "CircularBuffer.h"

#include <stdint.h>

#include <iostream>

// Constructors
CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1)
        throw std::invalid_argument(
            "CircularBuffer constructor: capacity must be greater than zero.");

    ringBuffer.resize(capacity);
    ringBuffer.clear();
}

// Member functions
int CircularBuffer::size() {
    return ringBuffer.size();
}

bool CircularBuffer::isEmpty() {
    if (ringBuffer.empty())
        return true;
    else
        return false;
}

bool CircularBuffer::isFull() {
    if (ringBuffer.size() == ringBuffer.capacity())
        return true;
    else
        return false;
}

void CircularBuffer::enqueue(int16_t x) {
    if (isFull() == true)
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    ringBuffer.push_back(x);
}

int16_t CircularBuffer::dequeue() {
    if (isEmpty() == true)
        throw std::runtime_error("dequeue: can't dequeue to an empty ring");

    int16_t temp = ringBuffer.front();
    ringBuffer.erase(ringBuffer.begin());

    return temp;
}

int16_t CircularBuffer::peek() {
    if (isEmpty())
        throw std::runtime_error("peek: can't peek to an empty ring");

    return ringBuffer.front();
}
```

```c++
// StringSound.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include "StringSound.h"

#include <math.h>
#include <stdlib.h>
#include <random>

#include <iostream>

// Constructors
StringSound::StringSound(double frequency) {
    _cb = new CircularBuffer(ceil(frequency));

    for (int i = 0; i < ceil(frequency); i++) {
        _cb->enqueue(0);
    }

    _time = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    if (init.empty())
        throw std::bad_alloc();

    _cb = new CircularBuffer(init.size());

    std::for_each(init.begin(), init.end(),
        [this, init](unsigned int i){_cb->enqueue(init[i]);});

    _time = 0;
}

StringSound::~StringSound() {
    delete _cb;
}

// Member functions
void StringSound::pluck() {
    while (!_cb->isEmpty())
        _cb->dequeue();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-32768, 32767);
    while (!_cb->isFull()) {
        int random = distribution(generator);
        _cb->enqueue(random);
    }
}

void StringSound::tic() {
    int16_t first, second;

    first = _cb->dequeue();
    second = _cb->peek();

    _cb->enqueue(.996 * .5 * (first + second));
}

sf::Int16 StringSound::sample() {
    return _cb->peek();
}

int StringSound::time() {
    return _time;
}

```

![Screen Shot 2021-04-26 at 7.28.07 PM](/Users/cambenassi/Library/Application Support/typora-user-images/Screen Shot 2021-04-26 at 7.28.07 PM.png)

*Output of program - black screen because output is entirely audio* 

<div style="page-break-after: always"></div>

# PS5 - Recursive Graphics

## Synopsis

For this assignment, we were tasked with creating a recursive triangle drawing with the SFML library. The triangle that we had to replicate is a variation of the Sierpinski triangle, which is an equalateral triangle which draws more (smaller) equalateral triangles at the tip of each of the sides. The program is to take in two command line agruments, L, and N, which stand for the length of the sides of the triangle, along with the depth of recursion. 

## Implementation

As stated above and in the directions, recursion has to be implemented. I wrote a Triangle class that stores each vertex, the side length from the command line arguments, the X/Y coordinate of the center, and whether the triangle has children or not. Also in this class was an overloaded draw() function from the SFML library. The constructor for this triangle class contains the math involving new vertexes, but the recursion happens in the main file, TFractal.cpp. Here, in a function fTree() that is called before the SFML window loop, all of the math for the centers of each new triangle is done. fTree() is passed a std::vector of Triangle objects, the SFML window, and the two command line arguments, depth and width. From here, the function will determine where in the recursion it is, and based on that, adjust the loop accordingly. Besides the first loop through, where the function just adds one triangle, fTree() adds 3 smaller triangles at the tip of the triangle before it by first calculating the new center points, and passing those center points to a Triangle constructor. These new triangles are then pushed into the std::vector of Triangles, which is later printed onto the SFML window.

## Key Algorithms, Data Structures or O.O. Designs

This program's implementation would not be possible without classes yes, but mainly recursion. The triangle vertex calculation is done inside of the Triangle constructor, which makes it easy to not only repeadily access previous triangle's coordinates, but also to have all of the math in one place. The recursion also allows for the triangles to be adaptive to however many the user wants to print, along with being sure that each triangle is accessed and is given the correct amount of children while not using an excessive amount of for() loops.

## What was learned?

This was the first project where recursion was required, which means that I had to understand not only recursion, but its impact on the code inside of the loop. This meant that I had to take a different approach to the problem than I normally would have, which ultimately made me even more comfortable with recursion. 

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ =  TFractal.o Triangle.o
DEPS =  TFractal.cpp Triangle.cpp Triangle.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = TFractal


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)
```

```c++
// TFractal.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <math.h>

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Triangle.h"

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double &length);  // NOLINT

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;
    double length = atof(argv[1]);
    int depth = atof(argv[2]);

    std::vector<Triangle> triangleVec;
    sf::RenderWindow window(sf::VideoMode(1400, 1400), "TFractal");

    fTree(triangleVec, window, depth, length);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        int vecSize = triangleVec.size();
        for (int i = 0; i < vecSize; i++)
            window.draw(triangleVec[i].triangle);
        window.display();
    }

    return 0;
}

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double &length) {  // NOLINT
    std::vector<Triangle> tempVec;

    if (triangleVec.empty()) {
        Triangle tree(length, 700.0, 700.0);
        triangleVec.push_back(tree);
    } else if (depth == 0) {
        return;
    } else if (triangleVec.size() == 1) {
        double centerLeftX, centerLeftY,
            centerRightX, centerRightY,
            centerDownX, centerDownY;

            centerLeftX = (triangleVec[0].centerX - length / 2.0);
            centerLeftY = (triangleVec[0].centerY - ((sqrt(3.0) / 2.0) * length) * 2 / 3);  //NOLINT

            centerRightX = (triangleVec[0].centerX + length * 3.0 / 4.0);
            centerRightY = (triangleVec[0].centerY - ((sqrt(3.0) / 2.0) * length) * 1 / 6);  //NOLINT

            centerDownX = (triangleVec[0].centerX - length * 1.0 / 4.0);
            centerDownY = (triangleVec[0].centerY + ((sqrt(3.0) / 2.0) * length) * 5 / 6);  //NOLINT

            length = length / 2;
            Triangle tempTriangleLeft(length, centerLeftX, centerLeftY);
            Triangle tempTriangleRight(length, centerRightX, centerRightY);
            Triangle tempTriangleDown(length, centerDownX, centerDownY);
            triangleVec.push_back(tempTriangleLeft);
            triangleVec.push_back(tempTriangleRight);
            triangleVec.push_back(tempTriangleDown);

            triangleVec[0].hasChildren = true;
    } else {
        for (auto &iter : triangleVec) {
            if (!iter.hasChildren) {  // will not skip middle past 3
                double centerLeftX, centerLeftY,
                centerRightX, centerRightY,
                centerDownX, centerDownY;

                centerLeftX = (iter.centerX - length / 2.0);
                centerLeftY = (iter.centerY - ((sqrt(3.0) / 2.0) * length) * 2 / 3);  //NOLINT

                centerRightX = (iter.centerX + length * 3.0 / 4.0);
                centerRightY = (iter.centerY - ((sqrt(3.0) / 2.0) * length) * 1 / 6);  //NOLINT

                centerDownX = (iter.centerX - length * 1.0 / 4.0);
                centerDownY = (iter.centerY + ((sqrt(3.0) / 2.0) * length) * 5 / 6);  //NOLINT

                Triangle tempTriangleLeft(length / 2, centerLeftX, centerLeftY);
                Triangle tempTriangleRight(length / 2, centerRightX, centerRightY);  //NOLINT
                Triangle tempTriangleDown(length / 2, centerDownX, centerDownY);

                tempVec.push_back(tempTriangleLeft);
                tempVec.push_back(tempTriangleRight);
                tempVec.push_back(tempTriangleDown);

                Triangle temp = iter;
                temp.hasChildren = true;
                iter = temp;
            }
        }
        length = length / 2;
        triangleVec.insert(triangleVec.end(), tempVec.begin(), tempVec.end());
        tempVec.clear();
    }
    depth -= 1;
    fTree(triangleVec, window, depth, length);
}
```

```c++
// Triangle.h
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef  SOPHOMORE_YEAR_COMPUTING_4_PS5_TRIANGLE_H_
#define  SOPHOMORE_YEAR_COMPUTING_4_PS5_TRIANGLE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable{
 public:
    explicit Triangle(double sideLength, double x, double y);
    sf::VertexArray triangle;
    double length, centerX, centerY;
    bool hasChildren = false;
 private:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;  // NOLINT
};


#endif  // SOPHOMORE_YEAR_COMPUTING_4_PS5_TRIANGLE_H_
```

```c++
// Triangle.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <math.h>

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Triangle.h"

// Constructor
Triangle::Triangle(double sideLength, double x, double y) {
    length = sideLength;
    centerX = x;
    centerY = y;
    double height = (sqrt(3) / 2) * sideLength;

    sf::VertexArray temp(sf::LineStrip, 4);
    temp[0].position = sf::Vector2f(x - sideLength / 2.0, y - height / 3.0);
    temp[1].position = sf::Vector2f(x + sideLength / 2.0, y - height / 3.0);
    temp[2].position = sf::Vector2f(x, y + height * (2.0 / 3.0));
    temp[3].position = temp[0].position;
    for (int i = 0; i <= 3; i++)
        temp[i].color = sf::Color::Red;
    triangle = temp;
}

// Member Functions
void Triangle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // window.draw(triangle_texture);
}
```

![Screen Shot 2021-04-26 at 7.50.13 PM](/Users/cambenassi/Library/Application Support/typora-user-images/Screen Shot 2021-04-26 at 7.50.13 PM.png)

*Output of program*

<div style="page-break-after: always"></div>

# PS6 - Kronos Time Clock

## Synopsis

With the final assignment, PS6, students were assigned with analyzing output files from the popular time clock-management company: Kronos. Using Boost regex expressions, certain lines of text had to be matched in order to find out when the server was started, if it started successfully, and if so, how long it took. These results were then printed to a seperate file, created by the program, which also output the total amount of lines scanned. The name of the file was taken in as a command line argument.

## Implementation

The first step to solving this problem was to load the file the user wanted to scan into a std::ifstream object, along with creating an output file. From there, a while() loop was entered, scanning the document line by line into a temporary std::string object. Each line, temporarily stored into said std::string object, was then used by the boost::regex_search functions to find certain lines of text, more specificaly to find a startup message, a success message, and times for when all of these occur. If a startup message is found, it is then printed onto the output file, along with the time, and then starts searching for either a success message or another startup message. If a success message is found before another startup message, we know the startup is a success, and can mark it as such in the output file, along with the total duration of time since the startup. If however, we find no success message and instead another startup message, we know the startup never finished, mark it as failure, and then begin the same process with this new startup message. This search process is driven by Boost time object, and boost::regex_search, along with different templates to search throughout the file.

## Key Algorithms, Data Structures or O.O. Designs

As stated above, regex_search is a key element in this assignment. This search tool allows us to quickly search for an exact phrase, a format of a string, or anything in between. In this assignment, exact phrases were used to find the predetermined startup messages, along with the format search to find dates and times which can obviously vary depending on when the server was started up. 

## What was learned?

From this assignment, I gained confidence with using regex_search, and now know how powerful of a tool it can be with searching. I gaurentee that this will be used in the future by me, because of how useful and versitile it is with searching. With other search functions, it may have taken much longer to search through the entire file, with accuracy not gaurenteed, however with regex_search, it only takes under a second on my personal machine.

## Source Code

```makefile
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ =  main.o
DEPS =  main.cpp
LIBS = -lboost_regex -lboost_date_time
EXE = ps6


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)
```

```c++
// main.cpp
// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>
#include <fstream>

#include <regex> //NOLINT

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char* argv[]) {
    std::string log = argv[1], outLog = log + ".rpt", temp, timeStart, timeEnd;
    std::ifstream input(log);
    boost::smatch smatches;
    boost::regex startup("server started"),
    success("oejs.AbstractConnector:Started SelectChannelConnector"),
    date("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    boost::posix_time::ptime t1, t2;
    FILE *output = fopen(outLog.c_str(), "w");
    int numScanned = 1;
    bool start = false;

    fprintf(output, "Device Boot Report\n\nInTouch log file: %s\n-------------------------------------\n", log.c_str()); //NOLINT

    while (std::getline(input, temp)) {
        if (start && boost::regex_search(temp, smatches, startup)) {
            fprintf(output, "Status - Failure\n");
        }
        if (boost::regex_search(temp, smatches, startup)) {
            fprintf(output, "Startup on line: %d | ", numScanned); //NOLINT
            if (boost::regex_search(temp, smatches, date)) {
                timeStart = "2000-10-24 " + smatches.str();
                t1 = boost::posix_time::time_from_string(timeStart);
            }
            start = true;
        }
        if (start && boost::regex_search(temp, smatches, success)) {
            timeEnd = "2000-10-24 ";
            for (int i = 11; i < 19; i++)
                timeEnd += temp[i];

            t2 = boost::posix_time::time_from_string(timeEnd);
            boost::posix_time::time_duration td = t2 - t1;
            fprintf(output, "Status - Success, finished on line %d | Duration: %ld minutes & %ld seconds\n", numScanned, td.minutes(), td.seconds()); //NOLINT
            start = false;
        }
        numScanned++;
    }
    fprintf(output, "\nLines scanned: %d", numScanned);

    input.close();
    fclose(output);
    return 0;
}
```



![screenshot](/Users/cambenassi/Documents/Code/UML/Sophomore Year/Computing 4/ps6/screenshot.png)

*Program output, skipped to show failure and success*

