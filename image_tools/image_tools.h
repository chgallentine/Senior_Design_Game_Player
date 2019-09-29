#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <queue>

#ifndef IMAGE_TOOLS_H
#define IMAGE_TOOLS_H

using namespace std;

// extern brd_t;

brd_t *read_board(ifstream &f);
void print_board(brd_t *brd, ofstream& outFile);
string read_starting_position(brd_t *board);
void print_change(string a, string b);

#endif