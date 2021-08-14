all: clean main

main: main.cc pair.cc leak.cc
	g++ -std=c++17 -o main.out main.cc

clean:
	if [ -e main.out ]; then rm main.out; fi
