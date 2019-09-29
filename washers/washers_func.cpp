/*
* @Author: Charlie Gallentine
* @Date:   2019-09-28 17:42:04
* @Last Modified by:   Charlie Gallentine
* @Last Modified time: 2019-09-29 16:37:48
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <queue>

#include "../main.h"
#include "washers.h"

// GENERIC (breadth-first search, outward from curnode)
void search(
	state source_node, 
	map<state, state>& pred, 
	map<state, int>& dist, 
	map<state, bool>& visited,
	map<state, vector<state> >& nbrs)
{
	queue<state> to_visit;
	to_visit.push(source_node);
	visited[source_node] = true;
	dist[source_node] = 0;

	while (!to_visit.empty()) {
	    state curnode = to_visit.front();
	    to_visit.pop();
	    for (state n : nbrs[curnode])
	    {
			if (!visited[n]) {
				pred[n] = curnode;
				dist[n] = 1 + dist[curnode];
				visited[n] = true;
				to_visit.push(n);
			}
	    }
	}
}

// GENERIC
void print_path(state s, state t, map<state, state>& pred)
{
	if (s != t) 
	{
		print_path(s, pred[t], pred);
	}
	cout << t << "\n";
}

void get_path(state s, state t, map<state, state>& pred, vector<state>& path)
{
	if (s != t) 
	{
		get_path(s, pred[t], pred, path);
	}
	path.push_back(t);
}

bool are_neighbors(string a, string b)
{
	int a_blank = a.find('_');
	int b_blank = b.find('_');

	if (a_blank == b_blank)
	{
		return false;
	}

	if (b[a_blank] != a[b_blank]) 
	{
		return false;
	}

	for (int i = 0; i < a.length(); i++)
	{
		if (i != a_blank && i != b_blank)
		{
			if (b[i] != a[i]) {return false;}
		}
	}

	return true;
}


void build_graph(
	string available,
	map<state, vector<state> >&nbrs)
{
  vector<state> words;
  gen_unique_words(words, available);

  string s, t;

	for (string s : words)
	{
		for (string t : words)
		{
			if (are_neighbors(s,t)) 
			{
				nbrs[s].push_back(t);
				nbrs[t].push_back(s);
			}  
		}
	}
}


void gen_unique_words(vector<string>& words, string available)
{
	sort(available.begin(), available.end());

    do {
    	words.push_back(available);
    } while (next_permutation(available.begin(), available.end()));
}
