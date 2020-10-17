#ifndef INV_H
#define INV_H
using namespace std;



class InvertedIndex{
public:
	string identifier;
	int frequency;
	InvertedIndex(string id = "", int freq=1){
		identifier= id;
		frequency = freq;
	}
	InvertedIndex operator = (const InvertedIndex & node)
	{
		identifier= node.identifier;
		frequency = node.frequency;
		return * this;	
	}
	bool operator == (const InvertedIndex & node)
	{
		if(identifier== node.identifier && frequency == node.frequency)
			return true;
		return false;
	}
};
#endif
