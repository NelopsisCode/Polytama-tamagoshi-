OBJ= obj/Polytama.o obj/Bar.o obj/InventoryClothes.o obj/InventoryConsommable.o obj/Clothes.o obj/Consommable.o obj/Item.o obj/MiniGame.o obj/Tictactoe.o

FLAGS= -g -Wall 
CC = g++

SDL= -lSDL2 -lSDL2_ttf -lSDL2_image

all: bin/testPolytama bin/mainTxt bin/mainSDL

bin/mainSDL: obj/mainSDL.o obj/GameSDL.o $(OBJ) 
	$(CC) -g obj/mainSDL.o obj/GameSDL.o $(OBJ) -o bin/mainSDL $(SDL)

bin/mainTxt: obj/MainTxt.o obj/GameTxt.o $(OBJ) obj/TictactoeTxt.o
	$(CC) -g obj/MainTxt.o obj/GameTxt.o $(OBJ) obj/TictactoeTxt.o -o bin/mainTxt -lncurses

bin/testPolytama: obj/testPolytama.o $(OBJ)
	$(CC) -g obj/testPolytama.o $(OBJ) -o bin/testPolytama

obj/mainSDL.o: src/Sdl/mainSDL.cpp
	$(CC) $(FlAGS) -c src/Sdl/mainSDL.cpp -o obj/mainSDL.o 

obj/GameSDL.o: src/Sdl/GameSDL.cpp src/Sdl/GameSDL.h src/Core/Polytama.h src/Txt/TictactoeTxt.h src/Core/Mini_Game.h src/Core/Clothes.h src/Core/Consommable.h src/Core/InventoryClothes.h src/Core/InventoryConsommable.h
	$(CC) $(FLAGS) -c src/Sdl/GameSDL.cpp -o obj/GameSDL.o

obj/MainTxt.o: src/Txt/MainTxt.cpp
	$(CC) $(FlAGS) -c src/Txt/MainTxt.cpp -o obj/MainTxt.o -lncurses
	
obj/GameTxt.o: src/Txt/GameTxt.cpp src/Txt/GameTxt.h src/Core/Polytama.h src/Txt/TictactoeTxt.h src/Core/Mini_Game.h src/Core/Clothes.h src/Core/Consommable.h src/Core/InventoryClothes.h src/Core/InventoryConsommable.h
	$(CC) $(FLAGS) -c src/Txt/GameTxt.cpp -o obj/GameTxt.o -lncurses
	
obj/TictactoeTxt.o: src/Txt/TictactoeTxt.cpp src/Txt/TictactoeTxt.h src/Core/Tictactoe.h
	$(CC) $(FLAGS) -c src/Txt/TictactoeTxt.cpp -o obj/TictactoeTxt.o -lncurses
	
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

obj/MiniGame.o: src/Core/Mini_Game.cpp src/Core/Mini_Game.h
	$(CC) $(FLAGS) -c src/Core/Mini_Game.cpp -o obj/MiniGame.o

obj/Tictactoe.o: src/Core/Tictactoe.cpp src/Core/Tictactoe.h
	$(CC) $(FLAGS) -c src/Core/Tictactoe.cpp -o obj/Tictactoe.o

	

clean:
	rm obj/*.o
	rm bin/*
				
veryclean: clean

