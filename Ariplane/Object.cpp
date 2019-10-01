#include "Object.h"


Object::Object()
{
}

Object::Object(ParaObject para)
{
	location = para.Location();
	vectory = para.Vectory();
	acceleration = para.Acceleration();
}


Object::~Object()
{
	location = PVector(0, 0);
	vectory = PVector(0, 0);
	acceleration = PVector(0, 0);
}

PVector & Object::Location()
{
	return location;
}

PVector & Object::Vectory()
{
	return vectory;
}

PVector & Object::Acceleration()
{
	return acceleration;
}
