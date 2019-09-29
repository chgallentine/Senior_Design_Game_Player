#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <queue>

#ifndef MAIN_H
#define MAIN_H

#define COLS 6
#define ROWS 6

using namespace std;

// Change this to reflect what each node represents...
typedef string state;

struct hdr_t {
	string magicNum;
	int rows, cols, pixVal;

	hdr_t(string, int, int, int);
};

struct brd_t {
	hdr_t *hdr;
	vector<unsigned int> pix;
};

#endif