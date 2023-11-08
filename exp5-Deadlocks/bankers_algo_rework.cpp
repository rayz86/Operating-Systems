//needs to be reworked, pls refer the second code
#include<iostream>
using namespace std;
int r,n;
bool safety(int n,int r,int alloc[][10],int available[],int need[][10])
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
                    if (need[p][j]>work[j])
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
    cout << endl<<endl << "safe sequence is: ";
    cout << "{ ";
    for (int i = 0; i < n ; i++)
        cout <<"P[" << safeSequence[i] << "]"<<" ";
    cout << "}";
    cout<<endl;

    return true;
}

void resource_req(int n, int r, int alloc[][10], int Max[][10], int available[], int need[][10], int req_p, int req_R[])
{
    for (int i = 0; i < r; i++)
    {
        if (req_R[i] > need[req_p][i] || req_R[i] > available[i])
        {
            cout <<endl << "Resource request cannot be granted" << endl;
            return;
        }
    }

    for (int i = 0; i < r; i++)
    {
        available[i] -= req_R[i];
        alloc[req_p][i] += req_R[i];
        need[req_p][i] -= req_R[i];
    }

    cout<<"AFTER RESOURCE REQUEST "<<endl;
        cout << "ALLOCATION MATRIX "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cout<<alloc[i][j];
        }
        cout << endl;
    }
     cout << endl;

    cout<<"MAX MATRIX"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cout<<Max[i][j];
        }
        cout << endl;
    }
     cout << endl;

    cout << " AVAILABLE MATRIX "<<endl;
    for(int i=0; i<r; i++)
    {
        cout<< available[i] << "\t";
    }
    cout << endl<<endl;

    cout << " NEED MATRIX "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cout<< need[i][j] <<" ";
        }
        cout << endl;
    }
     cout << endl;


    bool safe = safety(n, r, alloc, available, need);
    if (!safe)
    {
        for (int i = 0; i < r; i++)
        {
            available[i] += req_R[i];
            alloc[req_p][i] -= req_R[i];
            need[req_p][i] += req_R[i];
        }

        cout <<endl<< "Resource request cannot be granted" << endl;
    }
    else
    {
        cout <<endl<< "Resource request granted" << endl;
    }
}
int main()
{
    int R[10],alloc[10][10],Max[10][10],alloc_sum[10]= {0},available[10],need[10][10];

    cout << "Enter the number of processes : ";
    cin >> n;

    cout << "Enter the number of Resources : ";
    cin >> r;


    for(int i = 0; i < r; i++)
    {
        cout << "Enter the total instances of resource R[ " << i <<"] :";
        cin >> R[i];
    }

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

    cout << "Enter the Maximum R that can be allocated to processes : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            cin>>Max[i][j];

        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<n; j++)
        {
            alloc_sum[i] += alloc[j][i];
        }
    }

    cout << " Available matrix : "<<endl;

    for(int i=0; i<r; i++)
    {
        available[i]= R[i]-alloc_sum[i];
        cout<< available[i] << "\t";
    }
    cout<<endl;

    cout << " Need matrix : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P["<<i<<"]:";
        for(int j=0; j<r; j++)
        {
            need[i][j]= Max[i][j]-alloc[i][j];
            cout<< need[i][j] <<" ";
        }
        cout << endl;
    }
    safety(n,r,alloc,available,need);
    int req_p,req_R[10];
    cout<<endl<<endl;
    cout<<" RESOURCE REQUEST ";
    cout<<endl;
    cout<<"Enter the process which is requesting :";
    cin>>req_p;
    for(int i = 0; i < r; i++)
    {
        cout << "Enter the requested instances of resource R[ " << i <<"] :";
        cin >> req_R[i];
    }

    resource_req(n,r,alloc,Max,available,need,req_p,req_R);
    return 0;
}
