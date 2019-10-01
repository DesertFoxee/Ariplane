#pragma once
#ifndef PVECTOR_H
#define PVECTOR_H

#include "Helper.h"

using namespace sf;

class PVector
{
public:
	PVector();
	PVector(float x, float y);
	PVector(const PVector & v);
	PVector(const Vector2f& v);
	virtual ~PVector();

	PVector& operator +=(const PVector& v);
	PVector& operator -=(const PVector& v);
	PVector& operator *=(const float factor);
	PVector& operator /=(const float factor);


	PVector operator +(const PVector& v) const ;
	PVector operator -(const PVector& v) const;
	PVector operator *(const float factor) const ;
	PVector operator /(const float factor) const ;
	//PVector operator /(float factor) const;

	
	bool operator ==(const PVector& v);
	bool operator !=(const PVector& v);
	bool checkReverseSign(const PVector& v);


	Vector2f& Vector();
	
	float mag();
	PVector normalize();
	void rotate(float degree);
	float angle();

	
	static PVector randomPVector();

protected:
	sf::Vector2f vector;
};


#endif // !PVECTOR_H




