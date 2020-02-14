CC=g++
CFLAGS= -Wall -Ofast -std=c++11  -flto -pipe -funit-at-a-time -fopenmp -lz -Isparsepp -flto
LDFLAGS=-flto -lpthread -fopenmp -lz  -Isparsepp  -flto
EXEC=Proti



all: $(EXEC)


Proti: Proti.o utils.o
	$(CC) -o $@ $^ $(LDFLAGS)

Proti.o: proti.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

utils.o: utils.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)


rebuild: clean $(EXEC)
