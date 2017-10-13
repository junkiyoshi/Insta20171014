#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp(){
	for (int i = this->particles.size() - 1; i > -1; i--) {
		delete this->particles[i];
		this->particles.erase(this->particles.begin() + i);
	}
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update(){
	ofVec2f mouse_point = 
		ofVec2f(ofGetMouseX() - ofGetWidth() / 2, ofGetHeight() / 2 - ofGetMouseY());
	ofVec2f prev_mouse_point = 
		ofVec2f(ofGetPreviousMouseX() - ofGetWidth() / 2, ofGetHeight() / 2 - ofGetPreviousMouseY());
	ofVec2f velocity = prev_mouse_point - mouse_point;

	if (velocity.length() > 5) {
		this->particles.push_back(new Particle(mouse_point, velocity));
	}

	for (int i = this->particles.size() - 1; i > -1; i--) {
		this->particles[i]->update();

		if (this->particles[i]->isDead()){
			delete this->particles[i];
			this->particles.erase(this->particles.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (Particle* p : this->particles) {
		p->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}

