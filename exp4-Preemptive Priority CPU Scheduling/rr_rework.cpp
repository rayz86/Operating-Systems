//Preemptive CPU Scheduling
//Round Robin with Arrival time
//Rayyan Shaikh
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Process 
{
    int PI, AT, BT, RT, WT, TT, GT, CT;
};

int main() {
    int n, time_slice;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter the time slice: ";
    cin>>time_slice;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++) 
    {
        processes[i].PI = i + 1;
        cout<<"\nProcess P"<<i+1<<endl;
        cout<<"->Arrival Time:";
        cin>>processes[i].AT; 
        cout<<"->Burst Time:";
        cin>>processes[i].BT; 
        processes[i].RT = processes[i].BT;
        processes[i].WT = 0;
        processes[i].TT = 0;
    }

    int currentTime = 0, completed = 0;
    queue<Process> readyQ;

    while(!readyQ.empty() || !processes.empty() || currentTime<completed)
    {
        for (int i = 0; i < n; i++) 
        {
            if (processes[i].AT <= currentTime) 
            {
                readyQ.push(processes[i]);
            }
            if(!readyQ.empty())
            {
                Process currentProcess=readyQ.front();
                readyQ.pop();
                int executionTime=min(time_slice,currentProcess.BT);

                currentProcess.BT-=executionTime;
                currentTime+=executionTime;
                cout<<"Process P"<<currentProcess.PI<<" executed for "<<executionTime<<" units at time "<<currentTime<<endl;

                processes[i].WT = currentTime - processes[i].BT;
                processes[i].TT = processes[i].WT + processes[i].BT;

                if(currentProcess.BT>0)
                {
                    readyQ.push(currentProcess);
                }
                else
                {
                    currentTime++;
                }
                completed++;
            }
        }
    }


    /*while (completed < n) {
        for (int i = 0; i < n; i++) 
        {
            if (processes[i].AT <= currentTime) 
            {
                if (processes[i].RT <= time_slice) 
                {
                    currentTime += processes[i].RT;
                    processes[i].RT = 0;
                    completed++;

                    
                } 
                else 
                {
                    currentTime += time_slice;
                    processes[i].RT -= time_slice;
                }
            }
        }
    }*/

    float awt = 0, att = 0;
    for (int i = 0; i < n; i++) 
    {
        awt += processes[i].WT;
        att += processes[i].TT;
    }

    processes[0].GT=processes[1].AT;
    //processes[0].CT=0;
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
