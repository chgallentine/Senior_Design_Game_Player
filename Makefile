CC=g++
CFLAGS=-Wall -g -std=c++11

all : play_game

play_game : play_game.o washers_func.o gen_board_func.o image_tools_func.o
	$(CC) $(CFLAGS) $^ -o $@

image_tools_func.o : ./image_tools/image_tools_func.cpp ./image_tools/image_tools.h main.h
	$(CC) $(CFLAGS) $< -c

washers_func.o : ./washers/washers_func.cpp ./washers/washers.h main.h
	$(CC) $(CFLAGS) $< -c

gen_board_func.o : ./gen_board/gen_board_func.cpp ./gen_board/gen_board.h main.h
	$(CC) $(CFLAGS) $< -c

play_game.o : play_game.cpp main.h
	$(CC) $(CFLAGS) $< -c 

run : 
	./play_game

clean :
	rm -rf *.o