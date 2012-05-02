grid: Vert.h Vert.cpp hills.h hills.cpp common.h main.cpp 
	c++ -c Vert.cpp -o Vert.o
	c++ -c hills.cpp -o hills.o
	c++ -c main.cpp -o main.o
	c++ Vert.o hills.o main.o