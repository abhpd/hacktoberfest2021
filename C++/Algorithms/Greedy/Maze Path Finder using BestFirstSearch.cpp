#include <bits/stdc++.h>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;
struct Position{
    int row;
    int col;
    int heuristicVal;
    Position *lastPos;
};

vector<vector<char>> env;

char playerChar = 'P';
char wallChar = 'B';
char goalChar = 'G';

// Compare Heuristic
class CompareHeuristic {
public:
    bool operator()(Position const& p1, Position const& p2)
    {
        return p1.heuristicVal > p2.heuristicVal;
    }
};

Position findPos(vector<vector<char>> board, char m){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==m){
                return Position{i,j,0};
            }
        }
    }
}

// heuristic function for bfs
int calculateManhattan(Position m1, Position m2){
    return abs(m1.row-m2.row) + abs(m1.col-m2.col);
}

// this function backtracks from goal to starting position
void printSolvedEnv(Position lastPos, Position startPos){

    env[lastPos.row][lastPos.col] = goalChar;
    lastPos = *lastPos.lastPos;
    while(lastPos.row!=startPos.row || lastPos.col!=startPos.col){
        env[lastPos.row][lastPos.col] ='o';
        lastPos = *lastPos.lastPos;
    }
    env[startPos.row][startPos.col] = playerChar;

    for(int i=0;i<env.size();i++){
        for(int j=0;j<env[i].size();j++){
            cout<<env[i][j]<<" ";
        }
        cout<<endl;
    }
}

// this function finds the shortest path to goal state using best-first-search
void bfs(vector<vector<char>> board){

    int numRows = board.size(), numCols = board[0].size();

    Position playerPos = findPos(board, playerChar);
    Position goalPos = findPos(board, goalChar);

    playerPos.heuristicVal = calculateManhattan(playerPos, goalPos);

    // maintain a open and closed list
    vector<Position> closedList;
    priority_queue<Position, vector<Position>, CompareHeuristic> openList;
    openList.push(playerPos);

    Position currentPos{};

    int adjMovesRow[] = {1, -1, 1, 1, -1, -1, 0, 0};
    int adjMovesCol[] = {0, 0, 1, -1, -1, 1, 1, -1};

    while(calculateManhattan(currentPos, goalPos)!=0 && !openList.empty()){

        currentPos = openList.top();


        board[currentPos.row][currentPos.col] = 'o';
        openList.pop();
        for(int i=0;i<8;i++){
            if((currentPos.row + adjMovesRow[i]<numRows && currentPos.row + adjMovesRow[i]>=0) && (currentPos.col + adjMovesCol[i]<numCols && currentPos.col + adjMovesCol[i]>=0)){
                if(board[currentPos.row+adjMovesRow[i]][currentPos.col+adjMovesCol[i]]!=wallChar){
                    Position newMove = Position{currentPos.row+adjMovesRow[i], currentPos.col+adjMovesCol[i]};

                    // check if position already exists in closed List
                    bool isInClosedList = false;
                    for(int k=0;k<closedList.size();k++){
                        if(closedList[k].row==currentPos.row && closedList[k].col==currentPos.col) isInClosedList = true;
                    }
                    newMove.heuristicVal = calculateManhattan(newMove, goalPos);
                    Position lastPos;
                    lastPos.row = currentPos.row;
                    lastPos.col = currentPos.col;
                    lastPos.lastPos = currentPos.lastPos;
                    newMove.lastPos = new Position{currentPos.row, currentPos.col, currentPos.heuristicVal, currentPos.lastPos};
                    if(!isInClosedList) {
                        openList.push(newMove);
                    }
                }
            }
        }
        closedList.push_back(currentPos);
    }
    printSolvedEnv(currentPos, playerPos);

}



/*
 Maze Input Example
    __________
    __________
    ___P__B___
    __BBBBB___
    ___G______
*/

int main()
{
    cout<<"Hello user!\nDesign your matrix:\n>Use _ for empty tiles\n>Use B for wall blocks\n>Use P & G to position your playerChar & goal respectively\n>Enter end to 'end' the input.\n"<<endl;
    bool end = false;

    int row, col;
    cout<<"\nEnter Number of rows and cols: ";
    cin>>row>>col;

    for(int i=0;i<row;i++){
        vector<char> row;
        for(int j=0;j<col;j++){
            char el;
            cin>>el;
            row.push_back(el);
        }
        env.push_back(row);
    }

    cout<<"\nSolution using Best First Search:\n";
    bfs(env);

    return 0;
}
