/*
 * Particle.cpp
 *
 *  Created on: Feb 2, 2023
 *      Author: ASUS
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

Particle::Particle(): m_x(0), m_y(0) {


	//initialize list constructor for m_x and m_y make particle start
	//from the center instead of the code below make particle start from anywhere in the screen
//	m_x = ((2.0 * rand())/RAND_MAX) - 1;
//	m_y = ((2.0 * rand())/RAND_MAX) - 1;
	init();

}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.04 * rand()) / RAND_MAX;

	m_speed *= m_speed;

}

Particle::~Particle() {

}

void Particle::update(int interval){

	m_direction += interval*0.0002;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
		init();
	}

	if (rand() < RAND_MAX/100){
		init();
	}
}
