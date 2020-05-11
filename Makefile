CORE = Core/Polytama.cpp Core/Bar.cpp Core/InventoryClothes.cpp Core/InventoryConsommable.cpp Core/Item.cpp Core/Clothes.cpp Core/Consommable.cpp Core/Mini_Game.cpp Core/Tictactoe.cpp Core/Hanged.cpp Core/Memory.cpp

SRCS_TXT = $(CORE) Txt/TictactoeTxt.cpp Txt/GameTxt.cpp Txt/MainTxt.cpp
FINAL_TARGET_TXT = polytama_txt
#DEFINE_TXT = -DJEU_TXT

SRCS_SDL = $(CORE) Sdl/GameSDL.cpp Sdl/MemorySDL.cpp Sdl/HangedSDL.cpp Sdl/TictactoeSDL.cpp Sdl/mainSDL.cpp 
FINAL_TARGET_SDL = polytama_sdl
#DEFINE_SDL = -DJEU_SDL

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 \
						-Iextern\SDL2_mingw\SDL2_image-2.0.0\x86_64-w64-mingw32\include\SDL2 \
						-Iextern/SDL2_mingw/SDL2_mixer-2.0.1/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw/SDL2-2.0.3/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_image-2.0.0/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_mixer-2.0.1/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

			
	INCLUDE_DIR_NC = -Iextern/ncurses_mingw/include
						

	LIBS_NC = -Lextern \
			-Lextern/ncurses_mingw/lib \
			-lmingw32 -lncursesw
			
else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

	INCLUDE_DIR_NC = -I/usr/include/
	LIBS_NC = -lncurses 
	
endif

ifeq ($(OS),Windows_NT)
	RES = obj/ressource.o
else
	RES =
endif

CC					= g++
LD 					= g++
LDFLAGS  			= 
CPPFLAGS 			= -Wall -ggdb 
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc -Isrc/Core -Isrc/Sdl -Itxt

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\Txt $(OBJ_DIR)\Sdl $(OBJ_DIR)\Core
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/Txt $(OBJ_DIR)/Sdl $(OBJ_DIR)/Core
endif

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_NC)

$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o) $(RES)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)
	

obj/ressource.o: src/ressource.rc
		windres -i src/ressource.rc -o obj/ressource.o	
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR_NC) $(INCLUDE_DIR) $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\Txt\*.o $(OBJ_DIR)\Sdl\*.o $(OBJ_DIR)\Core\*.o $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_SDL).exe
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)
endif

