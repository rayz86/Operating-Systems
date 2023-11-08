//Implementing First Fit algorithm (Segmentation Method)
//Rayyan Shaikh
//21co43

#include<iostream>
#define MAX 5
using namespace std;
void first();
int buffer[MAX]; //{200,100,150,60}
int process[MAX]; // {80,200,50,120}
int n=4;

int main()
{
    cout<<"Enter the total processes:";
    cin>>n;
    
    cout<<"Enter buffer sizes:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"->Buffer "<<i+1<<":";
        cin>>buffer[i];
    }
    
    cout<<"Enter process sizes:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"->Process "<<i+1<<":";
        cin>>process[i];
    }
    
    cout<<"\n-----------------------------------\n";
    cout<<"Buffers:";
    for(int i=0;i<n;i++)
    {
        cout<<buffer[i]<<" ";
    }
    cout<<"\nProcesses:";
    for(int i=0;i<n;i++)
    {
        cout<<process[i]<<" ";
    }
    cout<<"\n-----------------------------------\n";

    first();
}

void first()
{
    cout<<"FIRST FIT:";
    bool alloc[MAX];
    for(int i=0;i<n;i++)
        alloc[i]=false;

    for(int i=0;i<n;i++)
    {
        int j=0;
        int flag=0;
        while(j<n)
        {
            if(process[i]<=buffer[j] && alloc[j]==false)
            {
                cout<<"\nB"<<j+1<<"("<<buffer[j]<<")"<<" -> "<<"P"<<i+1<<"("<<process[i]<<")";
                alloc[j]=true;
                flag=1;
                break;
            }
            j++;
        }
        if(flag==0)
        {
            cout<<"\nP"<<i+1<<" -> Unallocated";
        }
    }
}
