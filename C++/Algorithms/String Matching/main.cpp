#include"Graph.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include <bits/stdc++.h> 
#include<string>
#include<algorithm>
#include<list>
#include"InvertedIndex.h" 
#include<utility>
#define BOLDRED     "\033[1m\033[31m"   
#define RESET   "\033[0m"
#define BOLDYELLOW  "\033[1m\033[33m"  
using namespace std;



//the edit distance of string1 and string2
int editDistance(string string1, string string2)
{
    
    int m = (int)string1.length();
    int n = (int)string2.length();
    int i,j;
    int edit[m+1][n+1];
    for (i=0; i<=m;i++)
        edit[i][0]=i;
        
    for (j=0; j<=n; j++)
        edit[0][j]=j;
        
    for (i=1;i<m+1;i++)
        for (j=1;j<n+1;j++)
            edit[i][j]=min(min(edit[i-1][j]+1,edit[i][j-1]+1),edit[i-1][j-1]+(int)(!(string1[i-1]==string2[j-1])));
    return edit[m][n];
}

// To find the normalized edit distance that stays between 1 and 2
double NormalizedEditDistance(string str1, string str2)
{
	double simED= 1 - (editDistance(str1, str2)*1.0/ (max(str1.length(), str2.length())));
	return simED;
}

// inputs the string pairs from the file D and initializes Inverted Index for each string 
list<InvertedIndex> GenInvIndex(string D)
{
	fstream input;
	input.open(D, ios::in);
	list<InvertedIndex> Sa;
	list<InvertedIndex>:: iterator it;
	string x;
	while(input>>x){
		
		InvertedIndex temp(x);
		for(it= Sa.begin(); it!= Sa.end(); ++it){
			if(it->identifier == x){
				it->frequency++;
				goto contin;
				break;
			}
		}
		
		Sa.push_back(temp);
		contin:
			continue;
	}
	return Sa;
	
}

// it generates a 2D lists each list in the 2 Dimension has same length of strings
list<pair<int, list<InvertedIndex>>> GenLengthIndex(list<InvertedIndex> Sa){
	
	 list<InvertedIndex> :: iterator Sa_it;
	 list<pair<int, list<InvertedIndex>>> :: iterator La_it;
	 list<pair<int, list<InvertedIndex>>> La;
	 
	 for(Sa_it= Sa.begin(); Sa_it != Sa.end(); ++ Sa_it){
	 	list<InvertedIndex> tempList;
	 	InvertedIndex temp(Sa_it->identifier, Sa_it->frequency);
	 	for(La_it= La.begin(); La_it != La.end(); ++ La_it){
	 		
	 		if(La_it->first== temp.identifier.length()){
	 			La_it->second.push_back(temp);
	 			goto contin;
	 		
	 		}
	 		
	 	}
	 	
	 	tempList.push_back(temp);
	 	La.push_back(make_pair(temp.identifier.length(),tempList));
	 	
	 	contin:
	 		continue;
	 	
	 }
	 return La;
	

}

//used to sort the list
bool compare(pair<string, double> & _first, pair<string, double> & _second){
	return _first.second > _second.second;
	
}

int main()
{

	time_t start, end;
	
		// to calculate execution time;
	int m=2;	// maximum edits allowed
	cout<<"Maximum edit allowed in the string are: "<<m<<endl<<"Initializing Database..."<<endl;
	string D= "input.txt";	// file to input the strings from
	list<InvertedIndex> Sa;	
	list<pair<int, list<InvertedIndex>>> La;
	Graph Pa;
	Sa= GenInvIndex(D);
	La = GenLengthIndex(Sa);
	
	Sa.clear();
	cout<<"Enter the Query String"<<endl;
	string Sq;
	cin>>Sq;
	
	
	//start time
	auto started = std::chrono::high_resolution_clock::now();


	
	//Filtering of lengths
	for(list<pair<int, list<InvertedIndex>>> :: iterator it= La.begin(); it!= La.end(); it++){
		
		if(it->first < Sq.length() -1 || it->first > Sq.length() +1)
			continue;
		else{
			
			for(list<InvertedIndex> :: iterator jt= it->second.begin(); jt != it->second.end(); jt++){
				if( editDistance(Sq, jt->identifier)<=m)
					Sa.push_back(*jt);
			
			}
		}
	}
	
	
	
	//Graph initialization
	for(list<InvertedIndex>:: iterator it= Sa.begin(); it!= Sa.end(); it++){
		for(list<InvertedIndex>:: iterator jt= Sa.begin(); jt != Sa.end(); jt++){
			int tempEd= editDistance(it->identifier, jt-> identifier);
			if(it->identifier != jt -> identifier && tempEd<= m)
				Pa.insertEdge(*it, * jt, tempEd);
		}
	}
	
	
	list<pair<string, double>> finale;
	list<pair<InvertedIndex,list<pair<int, InvertedIndex>>>>:: iterator gIt;
	for(gIt = Pa.adjList.begin(); gIt != Pa.adjList.end(); gIt++){
			double temp;
			temp= NormalizedEditDistance(Sq, gIt->first.identifier);
			list<pair<int, InvertedIndex>>:: iterator gJt;
			// below loop is to count neigbouring strings that have the same edit distance
			for(gJt= gIt->second.begin(); gJt!= gIt->second.end(); gJt++){
				int count=0;
				if( editDistance(Sq, gIt->first.identifier) == editDistance(Sq, gJt->second.identifier))
					count++;
				if(count>0)
					temp = temp* (1/count);	// for neighbouring frequencies
			}
			if(gIt->first.frequency >0)
				temp = temp * gIt->first.frequency;
				
			if(NormalizedEditDistance(Sq, gIt->first.identifier)==1){
				cout<<BOLDYELLOW<<"An exact match found"<<endl<<endl<<RESET;
				
			}
			else
				finale.push_back(make_pair(gIt->first.identifier, temp));
			
	}
	list<pair<string, double>>:: iterator it= finale.begin();
	if(finale.size()==0){
		cout<<BOLDRED<<"There is no nearest match"<<endl<<RESET;
		goto end;
	}
	finale.sort(compare);
	cout<<"Most approximate maching string is"<<endl;
	cout<<it++->first<<endl;
	cout<<"Other nearest matches are"<<endl;
	for(it; it != finale.end(); it++){
			cout<<it->first<<endl;
	}
	
	
	end:
	auto done = std::chrono::high_resolution_clock::now();

	cout <<"Time taken by the program is "<< std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count()<<" ms"<<endl;
	

	
	



}
