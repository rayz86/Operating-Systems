//Shortest Job First with Arrival time
//Rayyan Shaikh
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
#define max 10
void sort(int [],double [],double []); void sjf(int [],double [],double []); void gantt(int [], double []);
int n;
void sort(int nOrder[],double burst[],double arrival[])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(arrival[j]>arrival[j+1]) 
            {
                int temp=arrival[j];
                arrival[j]=arrival[j+1];
                arrival[j+1]=temp;

                temp=burst[j];
                burst[j]=burst[j+1];
                burst[j+1]=temp;

                temp=nOrder[j];
                nOrder[j]=nOrder[j+1];
                nOrder[j+1]=temp;
            }
            else if(arrival[j]==arrival[j+1]) 
            {
                if(burst[j]>burst[j+1]) 
                {
                    int temp=arrival[j];
                    arrival[j]=arrival[j+1];
                    arrival[j+1]=temp;

                    temp=burst[j];
                    burst[j]=burst[j+1];
                    burst[j+1]=temp;

                    temp=nOrder[j];
                    nOrder[j]=nOrder[j+1];
                    nOrder[j+1]=temp;
                }
            }
        }
    }
}
void sjf(int nOrder[],double burst[],double arrival[])
{
    double wait[max],turn[max],complete[max],gchartval[max];
    float sumw,sumt; 
    for(int i=1;i<=n;i++)
    {
        nOrder[i]=i;
    }
    sort(nOrder,burst,arrival);
    gchartval[0]=arrival[1];
    for(int i=1;i<=n;i++) 
    { 
        gchartval[i]=gchartval[i-1]+burst[i]; 
        complete[i]=gchartval[i];
    }
    for(int i=1;i<=n;i++)
    {
        wait[i]=complete[i]-burst[i]-arrival[i];
        sumw=sumw+wait[i];
        turn[i]=wait[i]+burst[i];
        sumt=sumt+turn[i];
    }
    gantt(nOrder,gchartval);
    cout<<"\nProcess\t\tCompletion time\t\tWaiting time\tTurnaround time\n";
    for(int i=1;i<=n;i++)
        cout<<"P"<<nOrder[i]<<"\t\t"<<complete[i]<<"\t\t\t"<<wait[i]<<"\t\t"<<turn[i]<<"\n";

    cout<<"\nAverage waiting time: "<<sumw/n;
    cout<<"\nAverage turnaround time: "<<sumt/n;
}
void gantt(int nOrder[],double gchartval[])
{
    int num,digit=0;
    cout<<"\n****Gantt Chart****\n";
    cout<<"| ";
    for(int i=1;i<=n;i++)
      cout<<"P"<<nOrder[i]<<" | ";
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        digit=0;
        num=gchartval[i];
        digit=floor(log10(num))+1;
        if(digit==1)
            cout<<gchartval[i]<<"    ";
        else if(digit==2)
            cout<<gchartval[i]<<"   ";
    }
    cout<<endl;
}
int main()
{
    int nOrder[max];
    double burst[max],arrival[max];
    cout<<"Enter the no. of processes:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nProcess P"<<i;
        cout<<"\n->Arrival time:";
        cin>>arrival[i];
        cout<<"->Burst time:";
        cin>>burst[i];
    }
    sjf(nOrder,burst,arrival);
}
