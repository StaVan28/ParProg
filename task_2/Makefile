export OMP_NUM_THREADS=4
export N=8

.PHONE: all build clean

all: build
	./a.out $(N)

build:
	gcc -fopenmp main.c

clean:
	rm a.out

