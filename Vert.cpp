#include "Vert.h"
#include "systems.h"

Vert::Vert()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	radius = 0;
}

void Vert::setX(float newX)
{
	x = newX;
}

void Vert::setY(float newY)
{
	y = newY;
}

void Vert::setZ(float newZ)
{
	z = newZ;
}

void Vert::setRadius(int newRadius)
{
	radius = newRadius;
}

int Vert::getRadius(){
	return radius;
}

float Vert::getX(){
	return x;
}

float Vert::getY(){
	return y;
}

float Vert::getZ(){
	return z;
}

void Vert::adjust(Vert adjustor)
{
	float difference, distance;
	//calculates distance of the vertex to the hill or ridge being tested, as well as the difference in height between the two
	distance = sqrt(pow( (float)(x - adjustor.getX()), 2.f) + pow( (float)(z - adjustor.getZ()), 2.f));
	difference = adjustor.getY() - y;
	
	//moves the vertex up or down by a factor directly related to the hill's radius of influence and inversely related to the vertex' distance to the hill squared
	y += difference / (1 + (1.f / adjustor.getRadius()) * distance * distance);
}
