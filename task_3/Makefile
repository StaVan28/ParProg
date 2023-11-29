export OMP_NUM_THREADS=4

.PHONE: all build clean

all: build
	./a.out

build:
	gcc -fopenmp main.c

clean:
	rm a.out

