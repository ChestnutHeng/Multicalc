make: exec

main.o: main.cpp main.h
	g++ -c -o  main.o main.cpp -g
linar.o: linar.cpp
	g++ -c -o linar.o linar.cpp -g
fours.o: fours.cpp
	g++ -c -o fours.o fours.cpp -g
numsys.o: numsys.cpp
	g++ -c -o numsys.o numsys.cpp -g
evaluate.o: evaluate.cpp
	g++ -c -o evaluate.o evaluate.cpp -g
	
MathCalc.exe: main.o linar.o fours.o numsys.o evaluate.o
	g++ -o MathCalc.exe main.o linar.o fours.o numsys.o evaluate.o -g

exec: MathCalc.exe
	./MathCalc.exe
