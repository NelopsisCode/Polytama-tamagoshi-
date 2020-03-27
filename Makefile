

FLAGS= -g -Wall 
CC = g++

all: bin/testPolytama

bin/testPolytama: obj/testPolytama.o obj/Polytama.o obj/Bar.o  obj/InventoryClothes.o obj/InventoryConsommable.o obj/Clothes.o obj/Consommable.o obj/Item.o 
	$(CC) -g obj/testPolytama.o obj/Polytama.o obj/Bar.o  obj/InventoryClothes.o obj/InventoryConsommable.o obj/Clothes.o obj/Consommable.o obj/Item.o  -o bin/testPolytama

obj/testPolytama.o: src/Core/testPolytama.cpp
	$(CC) $(FLAGS) -c src/Core/testPolytama.cpp -o obj/testPolytama.o

obj/Polytama.o:	src/Core/Polytama.cpp src/Core/Polytama.h src/Core/Clothes.h src/Core/Consommable.h src/Core/InventoryClothes.h src/Core/InventoryConsommable.h
	$(CC) $(FLAGS) -c src/Core/Polytama.cpp -o obj/Polytama.o

obj/Bar.o: src/Core/Bar.cpp src/Core/Bar.h
	$(CC) $(FLAGS) -c src/Core/Bar.cpp -o obj/Bar.o
	
obj/InventoryClothes.o : src/Core/InventoryClothes.cpp src/Core/InventoryClothes.h src/Core/Item.h src/Core/Clothes.h 
	$(CC) $(FLAGS) -c src/Core/InventoryClothes.cpp -o obj/InventoryClothes.o
	
obj/InventoryConsommable.o : src/Core/InventoryConsommable.cpp src/Core/InventoryConsommable.h  src/Core/Item.h src/Core/Consommable.h
	$(CC) $(FLAGS) -c src/Core/InventoryConsommable.cpp -o obj/InventoryConsommable.o
	
obj/Clothes.o: src/Core/Clothes.cpp src/Core/Clothes.h 
	$(CC) $(FLAGS) -c src/Core/Clothes.cpp -o obj/Clothes.o

obj/Consommable.o: src/Core/Consommable.cpp src/Core/Consommable.h
	$(CC) $(FLAGS) -c src/Core/Consommable.cpp -o obj/Consommable.o

obj/Item.o: src/Core/Item.cpp src/Core/Item.h
	$(CC) $(FLAGS) -c src/Core/Item.cpp -o obj/Item.o

	

clean:
	rm obj/*.o
	rm bin/*
				
veryclean: clean

