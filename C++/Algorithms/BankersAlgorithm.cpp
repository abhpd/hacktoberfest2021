#include<bits/stdc++.h>
using namespace std;
struct RES{
    // lets assume that we have total of 3 resources: a,b,c
   int a, b, c;
};

int total;
void display();
vector<bool> completed;
vector<int> SafeSequence;
vector<RES> allocation, maxNeed, available, remNeed;

bool allComplete(){
    for(int i=0 ; i<total; i++)
        if (!completed[i]) return false; 
    return true;
}

void deadlock(int c1,int c2,int c3){
    cout << "\n";
    while(!allComplete()){
        bool deadlock = true;
        for(int i=0 ; i<total; i++){
            if (!completed[i]){
                if (remNeed[i].a<=c1 && remNeed[i].b<=c2 && remNeed[i].c<=c3){
                    cout << "P" << i+1 << " is executing.\n";
                    completed[i] = true;
                    c1 += allocation[i].a;
                    c2 += allocation[i].b;
                    c3 += allocation[i].c;
                    cout << "P" << i+1 << " terminated with no deadlock.\n";
                    SafeSequence.push_back(i+1);
                    deadlock = false;
                    cout << "Available resources : [" << c1 << " , " << c2 << " , " << c3 << "]\n\n";
                }
            }
        }
        if (deadlock) {
            cout << "Deadlock detected. Processes can't be executed. \n\n";
            exit(0);
        }
    }
    cout << "\nSafe Sequence : [  ";
    for (auto i: SafeSequence) cout << "P" << i << "  "; 
    cout << "]"; 
}

int main(){
    int A,B,C;
    cout << "Total number of processes : ";
    cin >> total;
    cout << "Total availability of resources : ";
    cin >> A >> B >> C;
    cout << "\nEnter allocation and maximum need of Processes.\n";
    int sumA=0, sumB=0,sumC=0;
    for(int i=0; i<total; i++){
        int x1,y1,z1,x2,y2,z2;
        cout << "P" << i+1 << " Allocation   : ";
        cin >> x1 >> y1 >> z1;
        cout << "P" << i+1 << " Maximum need : ";
        cin >> x2 >> y2 >> z2;
        sumA+=x1,sumB+=y1,sumC+=z1;
        maxNeed.push_back({x2,y2,z2});
        allocation.push_back({x1,y1,z1});
        remNeed.push_back({x2-x1,y2-y1,z2-z1});
    }
    display();
    for(int i=0;i<total;i++) completed.push_back(false);
    deadlock(A-sumA,B-sumB,C-sumC);
}

void display(){
    cout << "\n   < - - Table for Banker's Algorithm - - >\n\n";
    cout << "   Process   Allocation   MaxNeed   RemNeed\n               A B C       A B C     A B C\n";
    for(int i=0; i<total; i++){
        cout << "     P" << i+1 << "        " << allocation[i].a << " " << allocation[i].b << " " << allocation[i].c 
        << "       " << maxNeed[i].a << " " << maxNeed[i].b << " " << maxNeed[i].c
        << "     " << remNeed[i].a << " " << remNeed[i].b << " " << remNeed[i].c << "\n";
    }
}


/*
Sample input : (copy-paste this to understand the working)
5
10 5 7
0 1 0
7 5 3
2 0 0
3 2 2
3 0 2
9 0 2
2 1 1
4 2 2
0 0 2
5 3 3
*/
