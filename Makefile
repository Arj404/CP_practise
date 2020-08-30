all:
	g++ -Wall -std=c++14 graph.cpp -o out
	./out < input.txt