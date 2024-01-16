#include<iostream>
#define max 10
using namespace std;
int n,m,i,j, alloc[max][max], req[max][max], avail[max];
int main()
{
    cout<<"processes:";
    cin>>n;
    cout<<"resources";
    cin>>m;

    cout<<"enter alloc:";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>alloc[i][j];
        }
    }
    cout<<"enter request:";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>req[i][j];       
        }
    }
    cout<<"available:";
    for(i=0;i<m;i++)
    {
        cin>>avail[i];
    }

    int finish[max], seq[max], work[max];
    int s=0,check1=0,check2=0, flag=0;
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(j=0;j<m;j++)
    {
        work[j]=avail[j];
    }

    int count=0;
    while (count!=n)
    {
        for(i=0;i<n;i++)
        {
            check1=0;
            for(j=0;j<m;j++)
            {
                if(finish[i]==0 && (req[i][j]<work[j]))
                {
                    check1++;
                }
                if(check1==m)
                {
                    work[j]=work[j]+alloc[i][j];
                    finish[i]=1;
                }
                count++;
                seq[s]=i;
                s++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(finish[i]==1)
                check2++;
            if(check2==m)
                flag=1;
        }
    }
    if(flag==1)
        cout<<"System is in safe state";
    else
        cout<<"System is not in safe state";
}