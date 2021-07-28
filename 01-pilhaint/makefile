all: clean main

main: main.cc pilhaint.cc pilhaint.h
	g++ -std=c++11 -o main.out main.cc

clean:
	if [ -e main.out ]; then rm main.out; fi

# all: clean pilhaint main

# main: main.cc pilhaint.h pilhaint.o
# 	g++ -std=c++11 -o main.out main.cc pilhaint.o

# pilhaint: pilhaint.cc pilhaint.h
# 	g++ -std=c++11 -o pilhaint.o -c pilhaint.cc

# clean:
# 	rm pilhaint.o main.out 2> /dev/null;