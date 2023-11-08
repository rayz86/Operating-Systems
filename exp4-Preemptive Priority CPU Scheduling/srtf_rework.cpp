//Preemptive CPU Scheduling
//Shortest Remaining Time First with Arrival time
//Rayyan Shaikh
#include<iostream>
#include<limits.h>
using namespace std;
struct Process 
{
    int PI, AT, BT, RT, WT, TT, GT, CT;
};

int main() 
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    struct Process processes[n];

    for (int i = 0; i < n; i++) 
    {
        processes[i].PI = i + 1;
        cout<<"\nProcess P"<<i+1<<endl;;
        cout<<"->Arrival Time:";
        cin>>processes[i].AT;
        cout<<"->Burst Time:";
        cin>>processes[i].BT;
        processes[i].RT = processes[i].BT;
    }

    int currentTime = 0,completed = 0;
    float awt=0,att=0;

    while (completed < n) {
        int shortest = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            if (processes[i].AT <= currentTime && processes[i].RT < shortestTime && processes[i].RT > 0) 
            {
                shortest = i;
                shortestTime = processes[i].RT;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            processes[shortest].RT--;
            currentTime++;

            if (processes[shortest].RT == 0) 
            {
                processes[shortest].TT = currentTime - processes[shortest].AT;
                processes[shortest].WT = processes[shortest].TT - processes[shortest].BT;
                awt += processes[shortest].WT;
                att += processes[shortest].TT;
                
                completed++;
            }
        }
    }
    processes[0].GT=processes[0].AT;
    for(int i=1;i<n;i++)
    {
        processes[i].GT=processes[i-1].GT+processes[i].BT;
        processes[i].CT=processes[i].GT;
    }
    cout<<"\nProcess\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) 
    {
        cout<<"P"<<processes[i].PI<<"\t"<<processes[i].CT<<"\t\t"<<processes[i].WT<<"\t\t"<<processes[i].TT<<endl;
    }

    cout<<"\nAverage Waiting Time:"<<awt/n;
    cout<<"\nAverage Turnaround Time:"<<att/n;

    return 0;
}