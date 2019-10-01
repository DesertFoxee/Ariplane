#include "PVector.h"


PVector::PVector()
{
	vector.x = 0;
	vector.y = 0;
}

PVector::PVector(float x, float y)
{
	vector.x = x;
	vector.y = y;
}


PVector::PVector(const PVector & v)
{
	vector = v.vector;
}

PVector::PVector(const Vector2f & v)
{
	vector = v;
}


PVector::~PVector()
{
}

PVector & PVector::operator+=(const PVector & v)
{
	vector += v.vector;
	return *this;
}

PVector & PVector::operator-=(const PVector & v)
{
	vector -= v.vector;
	return *this;
}

PVector & PVector::operator*=(const float factor)
{
	vector *= factor;
	return *this;
}

PVector & PVector::operator/=(const float factor)
{
	if (factor != 0)
		vector /= factor;
	return *this;
}

PVector PVector::operator+(const PVector & v) const
{
	return PVector(vector + v.vector);
}

PVector PVector::operator-(const PVector & v) const
{
	return PVector(vector - v.vector);
}

PVector PVector::operator*(const float factor) const
{
	return PVector(vector*factor);
}

PVector PVector::operator/(const float factor) const
{
	if (factor != 0) {
		return PVector(vector/ factor);
	}
	return *this;
}


bool PVector::operator==(const PVector & v)
{
	return (vector == v.vector) ? true : false;
}

bool PVector::operator!=(const PVector & v)
{
	return (vector != v.vector) ? true : false;
}

bool PVector::checkReverseSign(const PVector & v)
{
	return (v.vector.x * vector.x < 0 && v.vector.y * vector.y <0);
}


Vector2f & PVector::Vector()
{
	return vector;
}

float PVector::mag()
{
	return sqrtf(vector.x * vector.x + vector.y *vector.y);
}

PVector PVector::normalize()
{
	float Mag = mag();
	return (Mag != 0) ? PVector(vector / Mag) : PVector(0,0);
}


// rotate around the origin 
/*
	Formula 

	x1 = cos(a)*x1 - sin(a)*x2;
	x2 = sin(a)*x1 + cos(a)*x2;
*/

void PVector::rotate(float degree)
{
	vector.x = cos(degree)*vector.x - sin(degree)*vector.y;
	vector.y = sin(degree)*vector.x + cos(degree)*vector.y;
}

float PVector::angle()
{
	return atan2f(vector.y , vector.x);
}

PVector PVector::randomPVector()
{
#ifdef HELPER_H
	return PVector(Random::randomFloatUniform(0 , 200 ) , Random::randomFloatUniform(0 ,200)); 
#else
	return PVector(0, 0);

#endif // HEPLER_H
}




