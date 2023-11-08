//Implementing First, Best and Worst fit algorithms (Segmentation Method)
//Rayyan Shaikh
//21co43

#include<iostream>
#define MAX 5
using namespace std;
void first();
void best();
void worst();
void sort(int, int[]);
//int process[MAX], buffer[MAX], n;
int buffer[MAX]={200,100,150,60};
int process[MAX]={80,200,50,120};
int n=4;
string op[MAX];

int main()
{
    //optional user inputs
    /*
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
    */
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

    int x;
    cout<<"1.First Fit 2.Best Fit 3.Worst Fit"<<endl;
    cout<<"Choice:";
    cin>>x;
    switch(x)
    {
        case 1:
            first();
            break;

        case 2:
            best();
            break;

        case 3:
            worst();
            break;
    }   
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
void sort(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void best()
{
    cout<<"\n\nBEST FIT:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
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
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j]<process[j+1])
            {
                int temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }
    bool alloc[MAX];
    for(int i=0;i<n;i++)
        alloc[i]=false;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(process[i]<=buffer[i] && alloc[j]==false)
        {
            op[i]= "P "+to_string(process[i])+" -> B "+to_string(buffer[i]);
            alloc[j]=true;
            j++;
        }
        else
            op[i]= "P "+to_string(process[i]);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<op[i]<<endl;
}

void worst()
{
    cout<<"\n\nWorst Fit:";
    sort(n,buffer);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(process[i]<=buffer[i])
        {
            op[i]= "P "+to_string(process[i])+" -> B "+to_string(buffer[i]);
            j++;
        }
        else
            op[i]= "P "+to_string(process[i]);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<op[i]<<endl;
}