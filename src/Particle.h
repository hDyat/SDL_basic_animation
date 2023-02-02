/*
 * Particle.h
 *
 *  Created on: Feb 2, 2023
 *      Author: ASUS
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
public:
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();
public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

#endif /* PARTICLE_H_ */
