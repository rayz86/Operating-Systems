//Implementing Best Fit algorithm (Segmentation Method)
//Rayyan Shaikh
//21co43

#include<iostream>
#define MAX 5
using namespace std;
void best();
int process[MAX], buffer[MAX], n;
int n=4;
string op[MAX];

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
    best();
}

void best()
{
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
    cout<<"\n\nBEST FIT:";
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
