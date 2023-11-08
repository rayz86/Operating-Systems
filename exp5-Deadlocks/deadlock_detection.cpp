#include<iostream>
using namespace std;
int r,n;

bool deadlock_detection(int n,int r,int alloc[][10],int request[][10],int available[])
{
    int i,work[r];
    bool finish[n]= {0};
    int safeSequence[n];
    for(int i=0; i<r; i++)
    {
        work[i]=available[i];
    }
    int count=0;
    while (count < n)
    {
        bool found =false;
        for(int p=0; p<n; p++)
        {
            if(finish[p]==0)
            {
                int j;
                for(j=0; j<r; j++)
                    if (request[p][j]>work[j])
                        break;

                if (j==r)
                {
                    for (int k=0; k<r; k++)
                        work[k]+=alloc[p][k];
                    safeSequence [count ++]=p;
                    finish[p]=1;
                    found = true;
                }
            }
        }

        if (found ==false)
        {
            cout << endl << "System is not in safe state";
            return false;
        }
    }
    cout << endl << "System is in safe state";
    cout << endl <<endl << "safe sequence is: ";
    cout << "{ ";
    for (int i = 0; i < n ; i++)
        cout <<"P[" << safeSequence[i] << "]"<<" ";
    cout << "}";

    return true;
}
int main()
{
    int R[10],alloc[10][10],request[10][10],alloc_sum[10]= {0},available[10];

    cout << "Enter the number of processes : ";
    cin >> n;

    cout << "Enter the number of Resources : ";
    cin >> r;

    cout << "Enter the Resources allocated to processes : ";
    cout<<endl;
    for(int i=0; i<n; i++)
    {
          cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cin>>alloc[i][j];
        }
    }

    cout << "Enter the Request by the processes : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cin>>request[i][j];

        }
    }
   cout << "Enter the available resources : "<<endl;
    for(int i=0; i<r; i++)
    {
        cin>>available[i];
    }
    deadlock_detection(n,r,alloc,request,available);
     return 0;
}

