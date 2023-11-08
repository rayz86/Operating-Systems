#include<iostream>
using namespace std;
#define max 10
int n, m, count=0, check1=0, check2=0, s=0;
int p[max],alloc[max][max], maxi[max][max], avail[max], need[max][max], work[max], finish[max], sequence[max];
void input();
void display(int []);
void safe_seq();

void display(int disp[max][max])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<disp[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void input()
{
    cout<<"enter the number of proceses:";
    cin>>n;
    cout<<"enter the number of resources:";
    cin>>m;
    cout<<"Allocation Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"->Enter value for P"<<i<<" R"<<j<<":";
            cin>>alloc[i][j];
        }
    }
    cout<<"\nMax Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"->Enter value for P"<<i<<" R"<<j+1<<":";
            cin>>maxi[i][j];
        }
    }
    cout<<"Enter available vector:\n";
    for(int i=0;i<m;i++)
    {
        cout<<"->R"<<i<<":";
        cin>>avail[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=maxi[i][j]-alloc[i][j];
        }
    }
    cout<<"\nNeed matrix:\n";
    display(need);
}

void safe_seq()
{
    int flag=0;
    for(int j=0;j<m;j++)
    {
        work[j]=avail[j];
    }
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }
    while(count!=n)
    {
        for(int i=0;i<n;i++)
        {
            check1=0;
            for(int j=0;j<m;j++)
            {
                if(finish[i]==0 && (need[i][j] <= work[j]))
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
                    sequence[s]=i;
                    s++;
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(finish[i]==1)
                check2++;
            if(check2==n)
            {
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        cout<<"\nSafe Sequence: ";
        for(int j=0;j<n;j++)
        {
            cout<<"P"<<sequence[j]<<"\t";
        }
    }
    else
        cout<<"\nSafe Sequence doesnt exist";
}

int main()
{
    input();
    safe_seq();
}