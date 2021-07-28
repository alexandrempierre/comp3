all: clean main

main: main.cc pilhaint.cc pilhaint.h
	g++ -std=c++11 -o main.out main.cc

clean:
	if [ -e main.out ]; then rm main.out; fi