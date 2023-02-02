//============================================================================
// Name        : SDL.cpp
// Author      : Dayat
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false){
		cout << "Error initialising SDL" << endl;
	}

	Swarm swarm;

	while (true ){
		//update particles
		//Draw particles

		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);

		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		//Program to change the color of the particles
		for (int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//program to change the color of screen (background)
		/*for (int i = 0; i < Screen::SCREEN_WIDTH; i++){
			for (int j = 0; j < Screen::SCREEN_HEIGHT; j++){
				screen.setPixel(i, y, red, green, blue);
			}
		}*/

		//Draw the screen
		screen.update();

		//Check for message/events
		if (screen.processEvents() == false){
			break;
		}
	}

	screen.close();

	return 0;
}
