#include <iostream>
#include <vector>

using namespace std;

#ifndef PLAY_GAME_H
#define PLAY_GAME_H

	typedef struct header {
		string magicNum;
		int rows, cols, pixVal;

		header(string, int, int, int);
	} hdr_t;

	typedef struct board {
		hdr_t *hdr;
		vector<unsigned int> pix;
	} brd_t;

	brd_t *read_board(ifstream &f);
	void print_board(brd_t *brd, ofstream& outFile);
	string read_starting_position(brd_t *board);

#endif