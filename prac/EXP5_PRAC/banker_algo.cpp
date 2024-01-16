#include<iostream>
using namespace std;
#define max 10
int n,m;
int alloc[max][max], maxi[max][max],need[max][max],avail[max];
void display(int [][max]);
void safeseq();
void request();
void display();
int main()
{
    cout<<"enter no. of processes:";
    cin>>n;
    cout<<"enter no. of resources:";
    cin>>m;

    cout<<"Allocation matrix:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>alloc[i][j];
        }
    }
    cout<<"\nMax Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maxi[i][j];
        }
    }
    cout<<"Enter available vector:\n";
    for(int i=0;i<m;i++)
    {
        cout<<"->R"<<i<<":";
        cin>>avail[i];
    }
    
    //need matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=maxi[i][j]-alloc[i][j];
        }
    }
    cout<<"need matix:";
    display(need);
    safeseq();
}

void display(int a[][max])
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int work[max], count=0,check1=0,check2=0,finish[max],seq[max],s=0;
void safeseq()
{
    int flag=0;
    for(int j=0;j<m;j++)
        work[j]=avail[j];
    
    for(int i=0;i<n;i++)
        finish[i]=0;
    
    while(count!=n)
    {
        for(int i=0;i<n;i++)
        {
            check1=0;
            for(int j=0;j<m;j++)
            {
                if(finish[i]==0 && (need[i][j]<=work[j]))
                {
                    check1++;
                }
                if(check1==m)
                {
                    for(int j=0;j<m;j++)
                    {
                        work[j]=work[j]+alloc[i][j];
                        finish[i]=1;
                    }
                    seq[s]=i;
                    s++;
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(finish[i]==1)
                check2++;
            if(check2==m)
                flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"before request";
        display();
        cout<<"\nsafe seq: ";
        for(int i=0;i<n;i++)
        {
            cout<<"P"<<seq[i]<<"\t";
        }
    }
    else
        cout<<"No safe seq";

    int x;
    cout<<"\nhave a addional request?(0/1)";
    cin>>x;
    if(x==1)
        request();
}

void request()
{
    int reqR;
    cout<<"enter the process requesting resource";
    cin>>reqR;

    int req[max];
    cout<<"enter the request:";
    for(int j=0;j<m;j++)
    {
        cin>>req[j];
    }
    for(int j=0;j<m;j++)
    {
        if(req[j]<=need[reqR][j])
        {
            if(req[j]<=avail[j])
            {
                alloc[reqR][j]=alloc[reqR][j]+req[j];
                need[reqR][j]=need[reqR][j]-req[j];
                avail[j]=avail[j]-req[j];
            }
        }
        else
        {
            cout<<"req cannot be granted";
            return;
        }
    }
    cout<<"request can be granted";
    cout<<"\nafter request";
    display();
}

void display()
{
    cout<<"\nAllocation matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<alloc[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nMax matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<maxi[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nNeed matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nAvailable vector:\n";
    for(int i=0;i<n;i++)
    {
        cout<<avail[i]<<" ";
    }
}

// 0 1 0 2 0 0 3 0 3 2 1 1 0 0 2
// 0 0 0 2 0 2 0 0 0 1 0 0 0 0 2
// 0 0 0

//bankers
// 0 1 0 3 0 2 3 0 3 2 1 2 0 0 2
// 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
// 2 3 0