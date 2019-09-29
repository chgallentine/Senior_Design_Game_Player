/*
* @Author: Charlie Gallentine
* @Date:   2019-09-27 15:02:21
* @Last Modified by:   Charlie Gallentine
* @Last Modified time: 2019-09-28 18:14:54
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <queue>

#include "main.h"

header::header(string mN, int r, int c, int pV)
{
	magicNum = mN;
	rows = r;
	cols = c;
	pixVal = pV;
}

brd_t *read_board(ifstream& inFile)
{
	brd_t *brd = new brd_t;

	string magicNum = "";
	int rows, cols, pixVal;

	inFile >> magicNum >> rows >> cols >> pixVal;
	inFile.get();

	hdr_t *hdr = new hdr_t(magicNum, rows, cols, pixVal);

	brd->hdr = hdr;

	brd->pix.reserve(rows * cols * 3);

	int i = 0;
	while (i < rows * cols * 3)
	{
		brd->pix.push_back(inFile.get());
		i++;
	}

	return brd;

}

void print_board(brd_t *brd, ofstream& outFile)
{
	outFile 
		<< brd->hdr->magicNum << " " 
		<< brd->hdr->rows << " " 
		<< brd->hdr->cols << " " 
		<< brd->hdr->pixVal << endl;

	for (int i : brd->pix)
	{
		outFile << (char)i;
	}
}

string read_starting_position(brd_t *brd)
{
	vector<pair<int,int> > holes;
	string position;

	holes.push_back(make_pair(0,0));
	holes.push_back(make_pair(0,2));
	holes.push_back(make_pair(0,4));
	holes.push_back(make_pair(1,5));
	holes.push_back(make_pair(3,5));
	holes.push_back(make_pair(5,5));
	holes.push_back(make_pair(5,3));
	holes.push_back(make_pair(5,1));
	holes.push_back(make_pair(4,0));
	holes.push_back(make_pair(2,0));

	for (auto it = holes.begin(); it != holes.end(); it++)
	{
		int offset_to_row = (*it).first * brd->hdr->cols * 3;
		int index = offset_to_row + (*it).second*3;

		if (brd->pix[index] == 255 && brd->pix[index + 1] == 0 && brd->pix[index + 2] == 0)
		{
			position += 'r';
		}
		else if (brd->pix[index] == 0 && brd->pix[index + 1] == 255 && brd->pix[index + 2] == 0)
		{
			position += 'g';
		}
		else if (brd->pix[index] == 0 && brd->pix[index + 1] == 0 && brd->pix[index + 2] == 255)
		{
			position += 'b';
		}
		else if (brd->pix[index] == 0 && brd->pix[index + 1] == 0 && brd->pix[index + 2] == 0)
		{
			position += '_';
		}
	}

	return position;
}





