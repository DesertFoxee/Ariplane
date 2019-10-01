#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include "PVector.h"

class ParaObject {

public :
	ParaObject(PVector loc, PVector vec, PVector acc) {
		this->loc = loc;
		this->vec = vec;
		this->acc = acc;
	}
	ParaObject() {
		acc = vec = loc = PVector(0, 0);
	}
	inline PVector Location() {
		return loc;
	}
	inline PVector Vectory() {
		return vec;
	}
	inline PVector Acceleration() {
		return acc;
	}
private:
	PVector loc;
	PVector vec;
	PVector acc;
};


// ===== ~ Interface class Action ========

class Action
{

public:
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void process() = 0;
};

// ===== ~ Abstract class Object ========
//
// ======================================

class Object : public Action
{
public:
	Object();
	Object(ParaObject para);
	virtual ~Object();

	virtual void applyForce(const PVector& force) =0;

	PVector& Location();
	PVector& Vectory();
	PVector& Acceleration();
protected:
	PVector location;
	PVector vectory;
	PVector acceleration;

	float mass;
};






#endif // !OBJECT_H



