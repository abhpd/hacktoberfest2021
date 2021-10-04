#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void game(char ps,char cs,int &playerscore,int &computerscore )
{
    if(cs==ps)
    {
        cout<<"TIE"<<endl;
        return;
    }
    if(ps=='R' || ps=='r')
    {
        if(cs=='s' || cs=='S')
        {
            cout<<"Computer_Choice :"<<cs<<endl;
            cout<<"This time Player Wins"<<endl;
            playerscore++;
            return;

        }
        if(cs=='p'||cs=='P')
        {
            cout<<"Computer_Choice :"<<cs<<endl;
            cout<<"This time Computer Wins"<<endl;
            computerscore++;
            return;
        }
    }

    if(ps=='S' || ps=='s')
    {
        if(cs=='p' || cs=='P')
        {
            cout<<"Computer_Choice :"<<cs<<endl;
            cout<<"This time Player Wins"<<endl;
            playerscore++;
            return;

        }
        if(cs=='r'||cs=='R')
        {
            cout<<"Computer_Choice :"<<cs<<endl;
            cout<<"This time Computer Wins"<<endl;
            computerscore++;
            return;
        }
    }

    if(ps=='p' || ps=='P')
    {
        if(cs=='r' || cs=='R')
        {
            cout<<"This time Player Wins"<<endl;
            playerscore++;
            return;

        }
        if(cs=='s'||cs=='S')
        {
            cout<<"This time Computer Wins"<<endl;
            computerscore++;
            return;
        }
    }

}
int main(){

string playername;
cout<<"Enter Your Name : "<<endl;
getline(cin,playername);
system("cls");
int round;
cout<<playername <<"  How many times you want to play ? "<<endl;
cin>>round;
int playerscore=0,computerscore=0;
for(int i=1;i<=round;i++)
{
    system("cls");
    char player_choice,computer_choice;
    cout<<"Round Number : "<<i<<"/"<<round<<"\n";
    cout<<playername <<"'s Score = "<<playerscore<<"\n";
    cout<<"Computer Score   "<<computerscore<<endl;
    cout<<"Use R for Rock / Use P for Paper / Use S for Stone"<<endl;
    cout<<"Select your Choice : ";
    cin>>player_choice;
    srand(time(0));
    if( rand()%3== 0)
    computer_choice='R';
    if( rand()%3== 1)
    computer_choice='P';
    if( rand()%3== 2)
    computer_choice='R';
    
    game(player_choice, computer_choice, playerscore, computerscore);
    cout<<"PlayerScore = "<<playerscore<<endl;
    cout<<"ComputerScore = "<<computerscore<<endl;

}

cout<<"Who's the Winner?Who's the Warrior of this battle :  ";
if(playerscore>computerscore) cout<<playername<<endl;
else {
    cout<<"Computer Wins the battle"<<endl;
    cout<<playername<<" Better Luck Next Time "<<endl;
}




return 0;
}
