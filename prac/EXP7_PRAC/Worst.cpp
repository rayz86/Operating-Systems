#include<iostream>
using namespace std;
#define max 10
int n, buffer[max],process[max];
void worst();
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

    worst();
}

void worst()
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

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(process[i]<=buffer[i])
        {
            cout<<"\nB"<<i+1<<"["<<buffer[i]<<"] -> P"<<i+1<<"["<<process[i]<<"]";
            j++;
        }
        else
            cout<<"\nP"<<process[i];
    }
}