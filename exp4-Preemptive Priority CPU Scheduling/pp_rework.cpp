//Preemptive CPU Scheduling
//Preemptive Priority Scheduling with Arrival time
//Rayyan Shaikh
#include<iostream>
using namespace std;

struct Process 
{
    int PI, AT, BT, RT, WT, TT, GT, CT, priority;
};

int main() {
    int n;

    cout<<"Enter the number of processes: ";
    cin>>n;

    Process processes[n];
    for (int i = 0; i < n; i++) 
    {
        processes[i].PI = i + 1;
        cout<<"\nProcess P"<<i+1<<endl;;
        cout<<"->Arrival Time:";
        cin>>processes[i].AT;
        cout<<"->Burst Time:";
        cin>>processes[i].BT;
        cout<<"->Priority:";
        cin>>processes[i].priority;
        processes[i].RT = processes[i].BT;
        processes[i].WT = 0;
        processes[i].TT = 0;
    }

    int currentTime = 0, completed = 0; 
    float awt = 0, att = 0;
    while (completed < n) 
    {
        int highestPriority = 99999;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) 
        {
            if (processes[i].AT <= currentTime && processes[i].priority < highestPriority && processes[i].RT > 0) 
            {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) 
        {
            currentTime++;
        } else 
        {
            processes[selectedProcess].RT--;
            currentTime++;

            if (processes[selectedProcess].RT == 0) 
            {
                completed++;
                processes[selectedProcess].WT = currentTime - processes[selectedProcess].AT - processes[selectedProcess].BT;
                processes[selectedProcess].TT = processes[selectedProcess].WT + processes[selectedProcess].BT;
                awt += processes[selectedProcess].WT;
                att += processes[selectedProcess].TT;
            }
        }
    }

    processes[0].GT=processes[1].AT;
    processes[0].CT=0;
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