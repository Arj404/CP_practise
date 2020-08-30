all:
	g++ -Wall -std=c++14 longest_same_even_odd.cpp -o out
	./out < input.txt