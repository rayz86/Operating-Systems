#include<iostream>
using namespace std;
#define max 10

int n,pro[max],burst[max],waitF[max],turnF[max],completeF[max],sumw,sumt;
void cals();
void display();

int main()
{
    cout<<"enter the no of processes:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        pro[i]=i+1;
        cout<<"Process P"<<i+1;
        cout<<"\n->Burst Time:";
        cin>>burst[i];
    }

    cals();
    display();
}

void cals()
{
    completeF[0]=burst[0];
    for(int i=1;i<n;i++)
    {
        completeF[i]=completeF[i-1]+burst[i];
    }

    waitF[0]=0;
    for(int i=1;i<n;i++)
    {
        waitF[i]=completeF[i]-burst[i];
        sumw=sumw+waitF[i];
    }

    for(int i=0;i<n;i++)
    {
        turnF[i]=waitF[i]+burst[i];
        sumt=sumt+turnF[i];
    }
}

void display()
{
    cout<<"\n\nProcess\tCompletetion Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\nP"<<pro[i]<<"\t"<<completeF[i]<<"\t\t\t"<<burst[i]<<"\t\t"<<waitF[i]<<"\t\t"<<turnF[i];
    }
    cout<<"\navg wait="<<sumw/n;
    cout<<"\navg turn="<<sumt/n;
}