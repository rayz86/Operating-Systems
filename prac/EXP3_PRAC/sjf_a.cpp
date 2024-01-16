#include<iostream>
using namespace std;
#define max 10
int n,pro[max],burst[max],arr[max],complete[max],wait[max],turn[max];
float sumw,sumt;
void cals();
void display();
void swap(int *,int *);
void sjf();

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


int main()
{
    cout<<"enter the no of processes:";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        pro[i]=i;
        cout<<"Process P"<<i;
        cout<<"\n->Arrival Time:";
        cin>>arr[i];
        cout<<"\n->Burst Time:";
        cin>>burst[i];
    }
    sjf();
}

void sjf()
{
    bool arrTF[n];
    for(int i=0;i<n;i++)
        arrTF[i]=false;
    int currAR=0;
    for(int i=0;i<n;i++)
    {
        if(currAR>arr[i])
        {
            arrTF[i]=true;
        }
    }
}

void display()
{
    cout<<"\n\nProcess\tCompletetion Time\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"\nP"<<pro[i]<<"\t"<<complete[i]<<"\t\t\t"<<burst[i]<<"\t\t"<<arr[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i];
    }
    cout<<"\navg wait="<<sumw/n;
    cout<<"\navg turn="<<sumt/n;
}
