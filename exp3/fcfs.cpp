//First come first serve without arrival time
//Rayyan Shaikh
#include<iostream>
using namespace std;

int main()
{
    int pro[10], burst[10], n;

    cout<<"Enter the number of processes:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        pro[i]=i+1;
        cout<<"enter burst time for process p"<<i+1<<":";
        cin>>burst[i];
    }

    cout<<"Process: ";
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<pro[i]<<" ";
    }
    cout<<"\nBurst time: ";
    for(int i=0;i<n;i++)
    {
        cout<<burst[i]<<" ";
    }
    int wait[10], turn[10],sumt=0,sumw=0;
    wait[0]=0;
    for(int i=1;i<n;i++)
    {
        wait[i]=wait[i-1]+burst[i-1];
        sumw=sumw+wait[i];
    }
    for(int i=0;i<n;i++)
    {
        turn[i]=wait[i]+burst[i];
        sumt=sumt+turn[i];
    }
    cout<<"\nWaiting time: ";
    for(int i=0;i<n;i++)
    {
        cout<<wait[i]<<" ";
    }
    cout<<"\nAverage waiting time: "<<sumw/n;
    cout<<"\nTurnaround time: ";
    for(int i=0;i<n;i++)
    {
        cout<<turn[i]<<" ";
    }
    cout<<"\nAverage turnaround time: "<<sumt/n;
}