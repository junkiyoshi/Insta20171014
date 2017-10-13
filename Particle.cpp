#include "Particle.h"

Particle::Particle() : Particle(ofVec2f(0, 0), ofVec2f(0, 0)){ }

Particle::Particle(ofVec2f location, ofVec2f velocity)
{
	this->location = location;
	this->velocity = velocity;
	this->alpha = 255;
	this->body_size = velocity.length() * 3;
	this->body_color.setHsb(ofRandom(255), 255, 255);
}

Particle::~Particle(){ }

void Particle::update()
{
	this->location += this->velocity;
	this->alpha -= 5;
}

void Particle::draw()
{
	ofSetColor(this->body_color, this->alpha);
	ofEllipse(this->location, this->body_size, this->body_size);
}

bool Particle::isDead()
{
	return this->alpha < 0;
}