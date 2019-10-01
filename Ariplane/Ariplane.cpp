#include "Ariplane.h"
#include <iostream>

Ariplane::Ariplane(PVector pos) : Object() {
	location = pos;
	mass = 10;
	vectory = PVector(0.02f, 0.03f);
	Ari.setPointCount(3);
	Ari.setRadius(20);
	Ari.setFillColor(Color(200, 100, 200));
	slideskill.init(200);
}

Ariplane::Ariplane(float x, float y) {
	location = PVector(x, y);
	Ari.setPointCount(3);
	Ari.setRadius(20);
	Ari.setFillColor(Color(200, 100, 200));
	slideskill.init(200);
}


Ariplane::~Ariplane() {
}

void Ariplane::update() {
	process();

	// Apply external force 

	fric = vectory.normalize();
	fric *= -1;
	applyForce(fric* C_FRIC);



	// kiem tra nguoc dau => khong cho quay dau 
	if(vectory.checkReverseSign(vectory + acceleration)) {
		acceleration = PVector(0, 0);
	}


	location += vectory;
	vectory += acceleration;
	Ari.setPosition(location.Vector());


	acceleration *= 0;


#ifdef ASSET_H
	checkEdges(DEFAULT_SCREEN_W, DEFAULT_SCREEN_H);
#endif // ASSET_H

}



void Ariplane::process() {
	if(KEYBOARD[K::KState::Up] == true) {
		acceleration += vectory.normalize()*0.01f;
		agl = vectory.angle();
	}
	else if(KEYBOARD[K::KState::Left] == true) {
		vectory.rotate(-0.008f);
		agl = vectory.angle();
	}
	else if(KEYBOARD[K::KState::Right] == true) {
		vectory.rotate(0.008f);
		agl = vectory.angle();
	}
	else if(KEYBOARD[K::KState::Down] == true) {

		acceleration += vectory.normalize()*(-0.001f);
	}
	else if(KEYBOARD[K::KState::Skill1] == true) {
		slideskill.run(Slide(Ari, agl));
	}
	else if(KEYBOARD[K::KState::Skill2] == true) {

	}
	else if(KEYBOARD[K::KState::Skill1] == false) {
		slideskill.stop(Slide(Ari, agl));
	}
}



/************
	why +90 ?

	B :
		angle = atan2(y/x);
			x
		----------|			|*	*
		  * 	  | y		|		*
			 *	  |			|	 *
				* |			| *
		Triangel :  /.\
*/

void Ariplane::render(sf::RenderWindow& window) {
	slideskill.render(window);
	Transform trans;
	trans.rotate(Convert::convertToDegree(agl) + 90, location.Vector().x + Ari.getRadius(), location.Vector().y + Ari.getRadius());
	window.draw(Ari, trans);
}

void Ariplane::applyForce(const PVector & force) {
	acceleration += (mass == 0) ? PVector(0, 0) : (force / mass);
}

void Ariplane::checkEdges(int width, int height) {
	if(location.Vector().x > width) {
		vectory.Vector().x *= -1;
		agl = vectory.angle();
	}
	else if(location.Vector().x < 0) {
		vectory.Vector().x *= -1;
		agl = vectory.angle();
	}
	else if(location.Vector().y > height) {
		vectory.Vector().y *= -1;
		agl = vectory.angle();
	}
}

//======== Skill Slide=======


SlideSkill::SlideSkill() {
	countshape = 0;
	this->time_limit_slide = 10;
}

SlideSkill::SlideSkill(int timelimit) {
	countshape = 0;
	this->time_limit_slide = timelimit;
}

SlideSkill::~SlideSkill() {
	countshape = 0;
}

void SlideSkill::init(int time_limit) {
	countshape = 0;
	clock.restart();
	time_limit_slide = time_limit;

}

void SlideSkill::addSlide(Slide img) {
	ele_slide[countshape] = img;
	countshape = (countshape + 1) == (MAX_SLIDE) ? countshape : countshape + 1;
}



void SlideSkill::transStatus() {
	for(int i = 1; i < this->countshape; i++) {
		ele_slide[i-1] = ele_slide[i];
	}
}
void SlideSkill::transStatusStop() {
	for(int i = 1; i < this->countshape+1; i++) {
		ele_slide[i -1 ] = ele_slide[i];
	}
}

void SlideSkill::render(sf::RenderWindow & window) {

	for(int index = 0; index < countshape; index++) {
		this->ele_slide[index].render(window);
	}
}


void SlideSkill::run(Slide img) {
	sf::Time elapsed = clock.getElapsedTime();

	// time elapsed two shadow
	if(elapsed.asMilliseconds() > this->time_limit_slide) {
		clock.restart();
		if(countshape >= MAX_SLIDE) {
			this->transStatus();
		}
		this->addSlide(img);
	}

}

void SlideSkill::stop(Slide img) {
	if(countshape > 0) {
		sf::Time elapsed = clock.getElapsedTime();
			
		if(elapsed.asMilliseconds() > time_limit_slide/2 && check == false) {
			this->transStatus();
			countshape -= 1;
			check = true;
		}
		else if(elapsed.asMilliseconds() > time_limit_slide) {
			this->transStatus();
			ele_slide[countshape-1] = img;
			clock.restart();
			check = false;
		}
	}
}
