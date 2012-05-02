#include "common.h"
#include "hills.h"

void input(float &length, int &size, int &hillcount, int &maxrise, int &ridgecount, int &noise);

int main () 
{
	srand((unsigned int)time(NULL));
	int length, sideCount, hillCount, maxRise, ridgeCount, noise;
	cout << "Enter Side Length: "; //length of the grid
	cin >> length;

	cout << "Enter Size: "; //number of vertices in one row
	cin >> sideCount;

	cout << "Enter Number of Hills: ";
	cin >> hillCount;

	cout << "Enter Max Hill Height: ";
	cin >> maxRise;

	cout << "Enter Number of Ridges: ";
	cin >> ridgeCount;

	cout << "Enter max noise (or 0): ";
	cin >> noise;

	Hills *testHills = new Hills(length, sideCount, hillCount, maxRise, ridgeCount, noise);
	testHills->adjustGridHeight();
	testHills->output("Heightgrid.obj");

	return 0;
}

