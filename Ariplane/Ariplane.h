#pragma once

#ifndef ARIPLANE_H
#define ARIPLANE_H

#include "Object.h"
#include "EventState.h"
#include "Asset.h"
#include "Environment.h"

#define MAX_SLIDE 15

class Slide {

public:
	CircleShape shape;
	float rotate;
	
	Slide( float radius =20, int pointcount =3) {
		shape.setPointCount(pointcount);
		shape.setRadius(radius);
	}
	Slide(CircleShape shape , float rotate) {
		this->shape = shape;
		this->rotate = rotate;
	}
	inline void render(sf::RenderWindow & window) {
		Transform trans;
		trans.rotate(Convert::convertToDegree(rotate)+ 90 , 
			(shape.getPosition()+ sf::Vector2f(shape.getRadius() , shape.getRadius())));
		window.draw(shape, trans);
	}
	inline Slide & operator=(const Slide & slide) {
		this->shape = slide.shape;
		this->rotate = slide.rotate;
		return *this;
	}
};


class SlideSkill {
protected:
	Slide ele_slide[MAX_SLIDE];
	int countshape = 0; 
	int time_limit_slide = 100;
	Clock clock;
	bool check = true;

public:
	SlideSkill();
	SlideSkill(int timelimit);
	~SlideSkill();
	void init(int time_limit);
	void addSlide(Slide img);
	void transStatus();
	void transStatusStop();
	void render(sf::RenderWindow & window);
	void run(Slide img);
	void stop(Slide img);

};

class Ariplane : public Object
{
public:
	Ariplane(PVector pos);
	Ariplane(float x , float y);
	~Ariplane();
	void update();
	void process();
	void render(sf::RenderWindow& window);
	void applyForce(const PVector& force);
	void checkEdges(int width , int height);
private:
	CircleShape Ari;
	float agl =0;
	SlideSkill slideskill;
};

#endif // !ARIPLANE_H




