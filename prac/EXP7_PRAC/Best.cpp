#include<iostream>
using namespace std;
#define max 10
int buffer[max], process[max];
int n;
void best();

int main()
{
    cout<<"Enter the number of processes:";
    cin>>n;

    cout<<"Enter the buffer sizes:";
    for(int i=0;i<n;i++)
    {
        cin>>buffer[i];
    }

    cout<<"Enter the process sizes:";
    for(int i=0;i<n;i++)
    {
        cin>>process[i];
    }

    cout<<"\nBuffers: ";
    for(int i=0;i<n;i++)
    {
        cout<<buffer[i]<<" ";
    }
    cout<<"\nProcesses: ";
    for(int i=0;i<n;i++)
    {
        cout<<process[i]<<" ";
    }

    best();
}

void best()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(buffer[j]<buffer[j+1])
            {
                int temp=buffer[j];
                buffer[j]=buffer[j+1];
                buffer[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(process[j]<process[j+1])
            {
                int temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }

    bool arr[max];
    for(int i=0;i<n;i++)
        arr[i]=false;

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[j]==false && process[i]<=buffer[i])
        {
            cout<<"\nB"<<i+1<<"["<<buffer[i]<<"] -> P"<<i+1<<"["<<process[i]<<"]";
            arr[j]=true;
            j++;
        }
        else
        {
            cout<<"\nP"<<i+1<<" -> Unallocated";
        }
    }
}