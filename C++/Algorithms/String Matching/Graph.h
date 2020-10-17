#include <iostream>
#include <cstdlib>
#include <string>
#include<list>
#include<utility>
#include "InvertedIndex.h"
using namespace std;


class Graph {

public:
	list<pair<InvertedIndex,list<pair<int, InvertedIndex>>>> adjList;
	int Vertices;
	bool insertInto( InvertedIndex src, InvertedIndex dest, int weight){
		list<pair<InvertedIndex,list<pair<int, InvertedIndex>>>> :: iterator it;
		for(it = adjList.begin(); it != adjList.end(); it++){
			if(it->first== src){
				it->second.push_back(make_pair(weight, dest));
				return true;
			}
		}
		return false;
	}

	Graph(){
		Vertices=0;
	}

	Graph(int maxVertices){
		Vertices = maxVertices;
		adjList.resize(maxVertices);
	}
	int graphsize(){
		return adjList.size();
	}
	
	bool insertEdge(InvertedIndex src, InvertedIndex dest, int weight){

		if(	!insertInto(src, dest, weight)		){
			list<pair<int, InvertedIndex>> temp;
			temp.push_back(make_pair(weight, dest));
			adjList.push_back(make_pair(src, temp));
		}
	}
	
	list<pair<int, InvertedIndex>> getdestinations(InvertedIndex src){
		list<pair<InvertedIndex,list<pair<int, InvertedIndex>>>> :: iterator it;
		for(it = adjList.begin(); it != adjList.end(); it++){
			if(it->first== src){
				return it->second;
			}
		}
		list<pair<int, InvertedIndex>> empty;
		return empty;	
	
	}
		
};
