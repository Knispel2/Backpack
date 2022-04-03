all: main.cpp head.hpp
	g++ -o main_test.exe Pach.cpp 
clean:
	rm *.o
