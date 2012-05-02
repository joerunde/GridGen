#ifndef _VERT_H_
#define _VERT_H_


class Vert
{
	private:
		float x, y, z; //position
		int radius; //radius of influence, used for hills and ridges
	public:
		Vert();
		void setX(float newX);
		void setY(float newY);
		void setZ(float newZ);
		void setRadius(int newR);
		void adjust(Vert adjustor);
		float getX();
		float getY();
		float getZ();
		int getRadius();
};

#endif