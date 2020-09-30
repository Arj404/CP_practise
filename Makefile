all:
	g++ -Wall -std=c++14 pythagorus.cpp -o out
	./out < input.txt