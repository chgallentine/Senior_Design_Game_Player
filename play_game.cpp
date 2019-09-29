/*
* @Author: Charlie Gallentine
* @Date:   2019-09-27 14:51:51
* @Last Modified by:   Charlie Gallentine
* @Last Modified time: 2019-09-29 17:15:46
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <queue>

#include "main.h"
#include "washers/washers.h"
#include "gen_board/gen_board.h"
#include "image_tools/image_tools.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2) 
	{ 
		cout << "Usage: ./play_game <end_pos>\n"; exit(0); 
	}

	ifstream inFile("./images/board.ppm");
	if (!inFile.good())
	{
		exit(0);
	}
	string strt = read_starting_position(read_board(inFile));

	map<state, bool> visited;         // have we queued up this state for visitation?
	map<state, state> pred;           // predecessor state we came from
	map<state, int> dist;             // distance (# of hops) from source node
	map<state, vector<state>> nbrs;   // vector of neighboring states
	vector<state> path;

	cout << "Starting from: " << strt << endl;

	build_graph(strt, nbrs);
	search(strt, pred, dist, visited, nbrs);


	get_path(strt, argv[1], pred, path);


	string i = "a_";
	for (auto it = path.begin(); it != path.end(); it++)
	{
		// MOVE WASHER IN REAL LIFE THEN VERIFY MOVE
		if (it != path.begin())
		{
			print_change(*(it-1), *it);
			cout << *it << endl;
		}


		string out = "./images/";
		out += i;
		out += *it;
		out += ".ppm";
		i[0]++;

		ofstream outFile(out);
		print_board(*it, outFile);
		outFile.close();


		// VERIFY MOVEMENT
		ifstream check_board(out);
		string curr_pos = read_starting_position(read_board(check_board));
		check_board.close();
		if (curr_pos != *it)
		{
			cout << "Board mismatch\n";
			exit(0);
		}
	}


	return 0;
}


