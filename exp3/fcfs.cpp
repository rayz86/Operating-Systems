//First come first serve without arrival time
//Rayyan Shaikh
#include<iostream>
using namespace std;
void gantt(); void waitF(); void turnF(); void completionF(); void display();
#define max 10
int n ,pro[max], burst[max], wait[max], turn[max],complete[max],sumt=0,sumw=0 ;

int main()
{
    cout<<"Enter the number of processes:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        pro[i]=i+1;
        cout<<"enter burst time for process p"<<i+1<<":";
        cin>>burst[i];
    }
    waitF();
    turnF();
    completionF();
    gantt();
    display();
}
void waitF()
{
    wait[0]=0;
    for(int i=1;i<n;i++)
    {
        wait[i]=wait[i-1]+burst[i-1];
        sumw=sumw+wait[i];
    }
}
void turnF()
{
    for(int i=0;i<n;i++)
    {
        turn[i]=wait[i]+burst[i];
        sumt=sumt+turn[i];
    }
}
void completionF()
{
    complete[0]=burst[0];
    for(int i=1; i<n; i++)
    {
        complete[i]=complete[i-1]+burst[i];
    }
}
void gantt()
{
    cout<<"\n****Gantt Chart****\n";
    cout<<" |";
    for(int i=0;i<n;i++)
      cout<<"P"<<pro[i]<<" | ";
    cout<<endl;
    cout<<" 0";
    for(int i=0;i<n;i++)
      cout<<"   "<<turn[i];
    cout<<endl;
}

void display()
{
    cout<<"\nProcess\t\tCompletion time\t\tWaiting time\tTurnaround time\n";
    for(int i=0;i<n;i++)
        cout<<"P"<<pro[i]<<"\t\t"<<complete[i]<<"\t\t\t"<<wait[i]<<"\t\t"<<turn[i]<<"\n";
    
    cout<<"\nAverage waiting time: "<<sumw/n;
    cout<<"\nAverage turnaround time: "<<sumt/n;
}