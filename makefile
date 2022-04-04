all: Pach.cpp
	g++ -o -std=c++1y main_test.exe Pach.cpp 
clean:
	rm *.o
