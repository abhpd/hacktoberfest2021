//C++ implementation of BogoSort by Gunjan

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

bool isSorted(const vector<int> &v){
    int i = v.size();
    while(--i){
        if(v[i] < v[i-1])
            return false;
    }
    return true;
}

void shuffle(vector<int> &v){
    for (size_t i = 0; i < v.size(); i++){
        swap(v[i], v[rand() % v.size()]);
    }
}

void bogoSort(vector<int> &v){
    while(!isSorted(v)){
        shuffle(v);
    }    
}

int main(){
    srand(time(NULL));

    vector<int> v = {1,3,4,6,7,9,10,2,5,8};
    bogoSort(v);

    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}