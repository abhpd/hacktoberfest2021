/*
PROBLEM
In this problem we will be considering a game played with four wheels. Digits ranging from 0 to 9
are printed consecutively (clockwise) on the periphery of each wheel. The topmost digits of the wheels
form a four-digit integer. For example, in the following figure the wheels form the integer 8056. Each
wheel has two buttons associated with it. Pressing the button marked with a left arrow rotates the
wheel one digit in the clockwise direction and pressing the one marked with the right arrow rotates it
by one digit in the opposite direction.
The game starts with an initial configuration of the wheels. Say, in the initial configuration the
topmost digits form the integer S1S2S3S4. You will be given some (say, n) forbidden configurations
Fi1 Fi2 Fi3 Fi4
(1 ≤ i ≤ n) and a target configuration T1T2T3T4. Your job will be to write a program that
can calculate the minimum number of button presses required to transform the initial configuration to
the target configuration by never passing through a forbidden one.
Input
The first line of the input contains an integer N giving the number of test cases to follow.
The first line of each test case contains the initial configuration of the wheels specified by 4 digits.
Two consecutive digits are separated by a space. The next line contains the target configuration. The
third line contains an integer n giving the number of forbidden configurations. Each of the following n
lines contains a forbidden configuration. There is a blank line between two consecutive input sets.
Output
For each test case in the input print a line containing the minimum number of button presses required.
If the target configuration is not reachable then print ‘-1’.
Sample Input
2
8 0 5 6
6 5 0 8
5
8 0 5 7
8 0 4 7
5 5 0 8
7 5 0 8
6 4 0 8
0 0 0 0
5 3 1 7
8
0 0 0 1
0 0 0 9
0 0 1 0
0 0 9 0
0 1 0 0
0 9 0 0
1 0 0 0
9 0 0 0
Sample Output
14
-1
*/

//A* search solution
#include<vector>
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

//state element
typedef struct state_{
	int digit[4];
	int heuristic;
	int depth;

	//defining < operator
	bool operator<(const state_& val) const {
		return heuristic < val.heuristic;
	}
}state;

//compare 2 states
bool equal(state a, state b){
  for(int i=0; i<4; i++){
    if(a.digit[i] != b.digit[i]) return false;
  }
	return true;
}

//evaluate the distance between 2 states
int eval(int curr[4], int final[4]){
	int a, b, h = 0;
	for(int i=0; i<4; i++){
		a = abs(curr[i] - final[i]);
		b = 10-a;
		if(a>b) h+=a;
		else h+=b;
	}
	return h;
}

//generate the 8 next states, given a father state
vector<state> next_states(state s, state final){
  vector<state> next(8, s);

  for(int i=0; i<8; i+=2){
    next[i].depth = (s.depth+1);
    next[i+1].depth = (s.depth+1);

    next[i].digit[i/2] = (next[i].digit[i/2]+1)%10;
    next[i+1].digit[i/2] = ((next[i+1].digit[i/2]-1)+10)%10;

		//apply the heuristic
		next[i].heuristic = eval(next[i].digit, final.digit) - next[i].depth;
    next[i+1].heuristic = eval(next[i+1].digit, final.digit) - next[i+1].depth;
  }

  return next;
}

//bfs search
int bfs(state current, state final, vector<vector<int>> forbidden){
	vector<state> next(8);
	int visited[10][10][10][10] = {0};
	priority_queue<state> q;

	//add forbidden states to visited
	for(int i=0; i<(int)forbidden.size(); i++){
		visited[forbidden[i][0]][forbidden[i][1]][forbidden[i][2]][forbidden[i][3]] = 1;
	}

	//if the first state is invalid
	if (!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]){
		visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1;
		q.push(current);

		//bfs
		while(!q.empty()) {
			current = q.top();
			q.pop();
			// reaches the final state and returns his depth
			if(equal(current, final)){
				return current.depth;
			}

			//calculate next states
			next = next_states(current, final);

			//continues the search
			for (int i=0; i<8; i++){
				if (!visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]]){
					visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;
					q.push(next[i]);
				}
			}
		}
	}
	return -1;
}

int main(void){
  int n, cont=0;

	//cases number
	cin>>n;

  for(int i=0; i<n; i++){
    int f;
		state initial;
		state target;
		initial.depth = 0;
		target.depth = 0;
		cont++;
    //getting initial number
    for(int j=0; j<4; j++){
      cin>>initial.digit[j];
    }
     //getting target
    for(int j=0; j<4; j++){
      cin>>target.digit[j];
    }

    //forbidden
    cin>>f;
    vector<vector<int>> forbidden(f, vector<int>(4));
    for(int j=0; j<f; j++){
      for(int k=0; k<4; k++){
        cin>>forbidden[j][k];
      }
    }

		//output
		cout << bfs(initial, target, forbidden) << "\n";
  }

  return 0;
}
