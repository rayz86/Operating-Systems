#include<iostream>
using namespace std;
#define max 10

int n,pro[max],order[max],arr[max],burst[max],waitF[max],turnF[max],completeF[max];
float sumw,sumt;
void cals();
void display();
void sort();

int main()
{
    cout<<"enter the no of processes:";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        pro[i]=i;
        cout<<"Process P"<<i;
        cout<<"\n->Burst Time:";
        cin>>burst[i];
    }

    sort();
    cals();
    display();
}

void sort()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(burst[j]>burst[j+1])
            {
                int temp=burst[j];
                burst[j]=burst[j+1];
                burst[j+1]=temp;

                temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }
}

void cals()
{
    for(int i=1;i<=n;i++)
    {
        completeF[i]=completeF[i-1]+burst[i];
        waitF[i]=completeF[i]-burst[i];
        turnF[i]=waitF[i]+burst[i];
        sumw=sumw+waitF[i];
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