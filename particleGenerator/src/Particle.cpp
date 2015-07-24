//
//  Particle.cpp
//  testTrigo
//
//  Created by Martial on 24/04/2015.
//
//

#include "Particle.h"

void Particle::setup(float x, float y, float direction, float speed, float frict) {
    radius = 2;
    lifeSpan = 255;
    position.set(x, y, 0);
    velocity.set(cos(direction) * speed, sin(direction) * speed, 0);
    friction.set(velocity);
    friction.setLength(frict);
}

void Particle::update(float speed, float frict, float grav) {
    if (isDead()) {
        this->setup(ofGetWidth()/2, ofGetHeight()/2, ofRandomf() * PI * 2, ofRandomf() * speed + 1, frict);
    }
    if (position.x > ofGetWidth() || position.x < 0 || position.y > ofGetHeight() || position.y < 0) {
        this->setup(ofGetWidth()/2, ofGetHeight()/2, ofRandomf() * PI * 2, ofRandomf() * speed + 1, frict);
    }
    if (velocity.length() > friction.length()) {
        velocity -= friction;
    }
    else {
        velocity.setLength(0);
    }
    gravity.set(0, grav, 0);
    position = position + velocity + gravity;
    lifeSpan -= 0.5;
}

void Particle::draw() {
    ofSetColor(0, 0, 0, lifeSpan);
    ofCircle(position, radius);
}

bool Particle::isDead() {
    return (lifeSpan <= 0) ? true : false;
}