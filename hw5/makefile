output: main.o AbstractBoard.o BoardArray1D.o BoardArray2D.o BoardVector.o
	g++  main.o AbstractBoard.o BoardArray1D.o BoardArray2D.o BoardVector.o -o output
main.o: main.cpp
	g++ -c main.cpp
AbstractBoard.o: AbstractBoard.cpp AbstractBoard.h
	g++ -c AbstractBoard.cpp
BoardArray1D.o: BoardArray1D.cpp BoardArray1D.h
	g++ -c BoardArray1D.cpp
BoardArray2D.o: BoardArray2D.cpp BoardArray2D.h
	g++ -c BoardArray2D.cpp
BoardVector.o: BoardVector.cpp BoardVector.h
		g++ -c BoardVector.cpp
clean:
	rm *.o output
