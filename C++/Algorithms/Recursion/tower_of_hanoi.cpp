// PROBLEM STATEMENT-
// Tower of Hanoi is a mathematical puzzle where we have three rods and some disks. 
//The objective of the puzzle is to move the entire stack of disks from one rod to another rod, 
// intitally all the disks are present in one rod (named from_rod here)
//obeying the following simple rules: 
// 1. Only one disk can be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e.
//       a disk can only be moved if it is the uppermost disk on a stack.
// 3. No disk may be placed on top of a smaller disk.

#include<bits/stdc++.h>
using namespace std;

int total_moves=0;//a variable which will keep count of the number of moves made

//function to describe the movements of rod such that all the rules are followed
void min_moves_to_move_disks(int disks,string from_rod, string to_rod,string helping_rod)
{
    if(disks==1)// when only one disk is presnt in to_rod
    {
        total_moves++;// number of moves is incremented by 1
        cout<<"move number "<<total_moves<<": \n";// simply printing the move count
        cout<<"Moving disk 1 from "<<from_rod<<" to "<< to_rod <<"\n"; // printing how the disk is moved
        return;
    }
    else
    {
        // we first move the top disks from from_rod to helping_rod, leaving only one disk which is largest
        min_moves_to_move_disks(disks - 1, from_rod, helping_rod, to_rod);

        total_moves++;// number of moves is incremented by 1

        cout<<"move number "<<total_moves<<": \n";// simply printing the move count

        cout << "Moving disk " << disks << " from " << from_rod << " to " << to_rod << endl;// printing how the disk is moved

        // now moving the remaing disks from helping rod to destination rod
        min_moves_to_move_disks(disks - 1, helping_rod, to_rod, from_rod);
    }
    return;
}// this function has time complexity of O(2^disks), which is exponential !!

void towerOfHanoi(int disks)
{
    // calling the function described above, which contains all the deatils how rods are moved
    min_moves_to_move_disks(disks,"fron_rod","to_rod","helping_rod");
    return;
}
int main()
{
    int disks;
    cout<<"enter number of disks: ";// taking input for number of disks
    cin>>disks;
    towerOfHanoi(disks);// calling the function towerOfHanoi which is described above
    cout<<"No of moved required is : "<<total_moves<<"\n";// printing the total number of moves required.
    //note that total moves required will always be 2^disks-1 !
    return 0;
}