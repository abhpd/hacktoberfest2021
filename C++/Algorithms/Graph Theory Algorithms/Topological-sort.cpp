/*
This code will let you understand topological sorting using Leetcode 210. Course Schedule II,
which is based on topological sorting
The question is :
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> curr_set;
    int idx = 0;

    for (auto x : prerequisites)
    {
        //edge from 1 to 0
        graph[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
    //initialize with all elements of 0 indegree
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            curr_set.push_back(i);
    }

    while (idx < curr_set.size())
    {

        //Decrease indegree of all neighbours by 1
        for (auto x : graph[curr_set[idx]])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                curr_set.push_back(x);
                //cout<<x<<endl;
            }
        }

        idx++;
    }
    return curr_set.size() == numCourses ? curr_set : vector<int>();
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> ans = findOrder(numCourses, prerequisites);

    cout << "The topological sorting will be : ";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}