#ifndef _HILLS_H_
#define _HILLS_H_
#include"Vert.h"

class Hills{
	private:
		Vert* grid, *hills, *ridges;
		int length, sideCount, maxRise, hillCount, ridgeCount, noise;
		static const int ridgeLength = 10;
		float space, lowY;
		void _placeGrid();
		void _placeHills();
		void _placeRidges();
	public:
		//Hills(); //constructor with command line prompts
		Hills(int newLength, int newSideCount, int newHillCount, int newMaxRise, int newRidgeCount, int newNoise);
		void adjustGridHeight();
		void output(char* path);
};

#endif