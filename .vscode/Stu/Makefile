main:main.o student.o
	g++  main.o student.o -o main
main.o:main.cpp student.cpp
	g++ -c main.cpp -o main.o
student.o:student.h student.cpp
	g++ -c student.cpp -o student.o
