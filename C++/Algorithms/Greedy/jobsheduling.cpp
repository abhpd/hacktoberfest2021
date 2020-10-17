/*PROBLEM:
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline.
It is also given that every job takes the single unit of time, so the minimum possible deadline for any job is 1.
How to maximize total profit if only one job can be scheduled at a time.

SOLUTION:
It can be solved using greedy.Firstly sort all jobs in decreasing order of profit. 
Iterate over the jobs and find a time slot j for that job such that j<deadline and j is empty and greatest.
If no such j is present then ignore it.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Item{
    int dl;//dl=deadline;
    int profit;
    int job;
};
void init(Item &I,int d,int pro,int j){
    I.dl=d;
    I.profit=pro;
    I.job=j;
}
bool comp(Item i1,Item i2){
    return(i1.profit>i2.profit);
}
int max_deadline(Item I[20],int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        if(maxi<I[i].dl){
            maxi=I[i].dl;
        }
    }
    return maxi;
}
void sol(Item I[20],int n){
    sort(I,I+n,comp);
    int max_dl=max_deadline(I,n);
    bool slot[max_dl];
    for(int i=0;i<max_dl;i++){
        slot[i]=false;
    }
    for(int i=0;i<n;i++){
        int curr_dl=I[i].dl;
        if (slot[curr_dl]==false){
            slot[curr_dl]=true;
            cout<<I[i].job<<' ';
        }
        else{
            for(int j=curr_dl;j>0;--j){
                if(slot[j]==false){
                    slot[j]=true;
                    cout<<I[i].job<<' ';
                    break;
                }
            }
        }
    }
}
int main()
{
    int n,dl,profit,job;
    cout << "Enter no. of jobs" << endl;
    cin>>n;
    Item I[n];
    for(int i=0;i<n;i++){
        cout << "Enter job,profit and deadline:" << endl;
        cin>>job>>profit>>dl;
        init(I[i],dl,profit,job);
    }
    sol(I,n);
    return 0;
}
