CC = g++
CFLAGS = -Wall -O3 --std=c++11 -O1 -larmadillo

commesso.exe : commesso.o random.o
	$(CC) random.o commesso.o -o commesso.exe

commesso.o : commesso.cpp
	$(CC) -c commesso.cpp -o commesso.o $(CFLAGS)

random.o : random.cpp random.h
	$(CC) -c random.cpp -o random.o $(CFLAGS)

clean : 
	rm *.o commesso.exe
