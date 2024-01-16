#include<iostream>
using namespace std;
#define max 10
int buffer[max], process[max];
int n;
void first();

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

    first();
}

void first()
{
    bool arr[max];
    for(int i=0;i<n;i++)
        arr[i]=false;

    for(int i=0;i<n;i++)
    {
        int j=0;
        int flag=0;
        while(j<n)
        {
            if(arr[j]==false && process[i]<=buffer[j])
            {
                cout<<"\nB"<<j+1<<"["<<buffer[j]<<"] -> P"<<i+1<<"["<<process[i]<<"]";
                arr[j]=true;
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