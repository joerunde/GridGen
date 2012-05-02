#include "systems.h"
#include "hills.h"
#include "Vert.h"

//Hills::Hills()
//{
//	cout << "Enter Side Length: "; //length of the grid
//	cin >> length;
//
//	cout << "Enter Size: "; //number of vertices in one row
//	cin >> sideCount;
//
//	cout << "Enter Number of Hills: ";
//	cin >> hillCount;
//
//	cout << "Enter Max Hill Height: ";
//	cin >> maxRise;
//
//	cout << "Enter Number of Ridges: ";
//	cin >> ridgeCount;
//
//	cout << "Enter max noise (or 0): ";
//	cin >> noise;
//
//	Hills(length, sideCount, hillCount, maxRise, ridgeCount, noise);
//
//}

Hills::Hills(int newLength, int newSideCount, int newHillCount, int newMaxRise, int newRidgeCount, int newNoise)
{
	length = newLength;
	sideCount = newSideCount;
	hillCount = newHillCount;
	maxRise = newMaxRise;
	ridgeCount = newRidgeCount;
	noise = newNoise;

	grid = new Vert[sideCount * sideCount];
	hills = new Vert[hillCount];
	ridges = new Vert[ridgeCount * ridgeLength];
	space = length / ( (float)sideCount - 1.f);

	_placeGrid();
	_placeHills();
	_placeRidges();
}

void Hills::_placeGrid()
{
	int c, i, current;
	for(c = 0; c < sideCount; c++)
	{
		for(i = 0; i < sideCount; i++)
		{
			current = c * sideCount + i;
			grid[current].setY(0);
			grid[current].setZ(c * space);
			grid[current].setX(i * space);
		}
	}
}

void Hills::_placeHills()
{
	int c;
	for(c = 0; c < hillCount; c++)
	{
		hills[c].setX((float)(rand() % length));
		hills[c].setZ((float)(rand() % length));
		hills[c].setY((float)(rand() % maxRise));
		hills[c].setRadius(rand() % 10000 + 5000);
	}
}

void Hills::_placeRidges()
{
	float direction;
	int c, i;
	for(c = 0; c < ridgeCount; c++)
	{
		ridges[c * ridgeLength].setX((float)(rand() % length));
		ridges[c * ridgeLength].setZ((float)(rand() % length));
		ridges[c * ridgeLength].setY((float)(rand() % (int)maxRise / 1.3));
		ridges[c * ridgeLength].setRadius(rand() % 2000 + 1000);
		direction = rand() % 628 / 100.f;
		for(i = 1; i < ridgeLength; i++)
		{
			ridges[c * ridgeLength + i].setX(ridges[c * 10 + i-1].getX() + cos(direction) * 50);
			ridges[c * ridgeLength + i].setZ(ridges[c * 10 + i-1].getZ() + sin(direction) * 50);
			ridges[c * ridgeLength + i].setY(ridges[c * 10].getY());
			direction += rand() % 60 / 100.f - .1f;
			ridges[c * 10 + i].setRadius(rand() % 2000 + 1000);
		}
	}
}

void Hills::adjustGridHeight()
{
	int c, i;
	for(c = 0; c < sideCount*sideCount; c++)
	{
		for(i = 0; i < hillCount; i++)
			grid[c].adjust(hills[i]);
		for(i = 0; i < ridgeCount; i++)
			grid[c].adjust(ridges[i]);
		if(c == 0)
			lowY = grid[c].getY();
		else
			if(grid[c].getY() < lowY)
				lowY = grid[c].getY();
	}

}

/*
	This function prints the contents of Hills in .obj file format to the file path provided
*/
void Hills::output(string path){
	ofstream hGrid;
	hGrid.open(path);
	int i, c, current;
	for(c = 0; c < sideCount; c++)
		for(i = 0; i < sideCount; i++)
		{
			current = c * sideCount + i;
			grid[current].setY(grid[current].getY() - lowY);
			hGrid << "v " << grid[current].getX() << " " << grid[current].getY() << " " << grid[current].getZ() << endl;
		}

	for(c = 0; c < sideCount - 1; c++)
	{
		for(i = 0; i < sideCount - 1; i++)
		{
			current = c * sideCount + i;
			if( (c % 2 == 0 && i % 2 == 1) || (c % 2 == 1 && i % 2 == 0) )
			{
				hGrid << "f " << (current + 1) << " " << (current + 1) + sideCount << " " << (current + 2) << endl;
				hGrid << "f " << (current + 2) << " " << (current + 1) + sideCount << " " << (current + 2) + sideCount << endl;
			}
			else
			{
				hGrid << "f " << (current + 1) << " " << (current + 1) + sideCount << " " << (current + 2) + sideCount << endl;
				hGrid << "f " << (current + 2) << " " << (current + 1) << " " << (current + 2) + sideCount << endl;
			}
		}
	}

}
