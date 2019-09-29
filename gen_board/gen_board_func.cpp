/*
* @Author: Charlie Gallentine
* @Date:   2019-09-28 17:39:10
* @Last Modified by:   Charlie Gallentine
* @Last Modified time: 2019-09-29 16:26:27
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <map>

#include "../main.h"
#include "gen_board.h"

void print_board(string state, ofstream& outFile)
{
	map<pair<int,int>,char> locations;
	locations[make_pair(0,0)] = state[0];
	locations[make_pair(0,2)] = state[1];
	locations[make_pair(0,4)] = state[2];
	locations[make_pair(1,5)] = state[3];
	locations[make_pair(2,0)] = state[9];
	locations[make_pair(3,5)] = state[4];
	locations[make_pair(4,0)] = state[8];
	locations[make_pair(5,1)] = state[7];
	locations[make_pair(5,3)] = state[6];
	locations[make_pair(5,5)] = state[5];


	outFile << "P6 " << ROWS << " " << COLS << " " << 255 << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (locations.find(make_pair(i,j)) != locations.end())
			{
				if (locations[make_pair(i,j)] == 'r')
				{
					outFile << (unsigned char) 255 << (unsigned char) 0 << (unsigned char) 0;
				}
				else if (locations[make_pair(i,j)] == 'g')
				{
					outFile << (unsigned char) 0 << (unsigned char) 255 << (unsigned char) 0;
				}
				else if (locations[make_pair(i,j)] == 'b')
				{
					outFile << (unsigned char) 0 << (unsigned char) 0 << (unsigned char) 255;
				}
				else
				{
					outFile << (unsigned char) 0 << (unsigned char) 0 << (unsigned char) 0;
				}
			}
			else
			{
				outFile << (unsigned char) 255 << (unsigned char) 255 << (unsigned char) 255;
			}	
		}
	}
}









