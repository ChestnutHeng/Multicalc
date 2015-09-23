make: exec

main.o: main.cpp main.h
	g++ -c -o  main.o main.cpp
linar.o: linar.cpp
	g++ -c -o linar.o linar.cpp
fours.o: fours.cpp
	g++ -c -o fours.o fours.cpp
numsys.o: numsys.cpp
	g++ -c -o numsys.o numsys.cpp
	
MathCalc.exe: main.o linar.o fours.o numsys.o
	g++ -o MathCalc.exe main.o linar.o fours.o numsys.o

exec: MathCalc.exe
	./MathCalc.exe
