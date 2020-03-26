

FLAGS= -g -Wall 
CC = g++

all: bin/testPolytama

bin/testPolytama: obj/testPolytama.o obj/Polytama.o obj/Bar.o obj/Inventory.o obj/InventoryClothes.o obj/InventoryConsommable.o obj/Clothes.o obj/Consommable.o obj/Item.o 
	$(CC) -g obj/testPolytama.o obj/Polytama.o obj/Bar.o obj/Inventory.o obj/InventoryClothes.o obj/InventoryConsommable.o obj/Clothes.o obj/Consommable.o obj/Item.o  -o bin/testPolytama

obj/testPolytama.o: src/testPolytama.cpp
	$(CC) $(FLAGS) -c src/testPolytama.cpp -o obj/testPolytama.o

obj/Polytama.o:	src/Polytama.cpp src/Polytama.h src/Clothes.h src/Consommable.h src/Inventory.h
	$(CC) $(FLAGS) -c src/Polytama.cpp -o obj/Polytama.o

obj/Bar.o: src/Bar.cpp src/Bar.h
	$(CC) $(FLAGS) -c src/Bar.cpp -o obj/Bar.o
	
obj/Inventory.o : src/Inventory.cpp src/Inventory.h src/InventoryClothes.h src/InventoryConsommable.h 
	$(CC) $(FLAGS) -c src/Inventory.cpp -o obj/Inventory.o
	
obj/InventoryClothes.o : src/InventoryClothes.cpp src/InventoryClothes.h src/Item.h src/Clothes.h 
	$(CC) $(FLAGS) -c src/InventoryClothes.cpp -o obj/InventoryClothes.o
	
obj/InventoryConsommable.o : src/InventoryConsommable.cpp src/InventoryConsommable.h  src/Item.h src/Consommable.h
	$(CC) $(FLAGS) -c src/InventoryConsommable.cpp -o obj/InventoryConsommable.o
	
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

