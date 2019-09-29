#include <map>
#include <vector>

#ifndef WASHERS_H
#define WASHERS_H

using namespace std;

// Change this to reflect what each node represents...
typedef string state;

void gen_unique_words(vector<string>& words, string available);
void search(
	state source_node, 
	map<state, state>& pred, 
	map<state, int>& dist, 
	map<state, bool>& visited,
	map<state, vector<state> >& nbrs);
void print_path(state s, state t, map<state, state>& pred);
void get_path(state s, state t, map<state, state>& pred, vector<state>& path);
bool are_neighbors(string a, string b);
void build_graph(string available, map<state, vector<state> >&nbrs);

#endif