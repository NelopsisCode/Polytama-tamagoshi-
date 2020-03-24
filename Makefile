

FLAGS= -g -Wall 
CC = g++

all: bin/testPolytama

bin/testPolytama: obj/testPolytama.o obj/Polytama.o obj/Bar.o obj/Clothes.o obj/Consommable.o obj/Item.o
	$(CC) -g obj/testPolytama.o obj/Polytama.o obj/Bar.o obj/Clothes.o obj/Consommable.o obj/Item.o -o bin/testPolytama

obj/testPolytama.o: src/testPolytama.cpp
	$(CC) $(FLAGS) -c src/testPolytama.cpp -o obj/testPolytama.o

obj/Polytama.o:	src/Polytama.cpp src/Polytama.h src/Clothes.h src/Consommable.h
	$(CC) $(FLAGS) -c src/Polytama.cpp -o obj/Polytama.o

obj/Bar.o: src/Bar.cpp src/Bar.h
	$(CC) $(FLAGS) -c src/Bar.cpp -o obj/Bar.o

obj/Clothes.o: src/Clothes.cpp src/Clothes.h 
	$(CC) $(FLAGS) -c src/Clothes.cpp -o obj/Clothes.o

obj/Consommable.o: src/Consommable.cpp src/Consommable.h
	$(CC) $(FLAGS) -c src/Consommable.cpp -o obj/Consommable.o

obj/Item.o: src/Item.cpp src/Item.h
	$(CC) $(FLAGS) -c src/Item.cpp -o obj/Item.o

	

clean:
	rm obj/*.o
	rm bin/*
				
veryclean: clean

