#include<iostream>
int mutex=1, in=0,out=0, buffer[5], next_prod,next_consum, full=0, empty=4,bs, counter=0;
void prod();
void consum();
int wait(int);
int signal(int);
using namespace std;

int main()
{
    cout<<"enter buffer size";
    cin>>bs;

    int x;
    while(1)
    {
        cout<<"\n1.Producer 2.Consumer 3.EXIT";
        cin>>x;
        switch(x)
        {
            case 1:
                prod();
                break;
            case 2:
                consum();
                break;
            case 3:
                exit(1);
            default:
                cout<<"Invalid Input";
        }
    }
}

int wait(int s)
{
    if(s<0)
    {
        cout<<"deadlock";
    }
    s--;
    return s;
}

int signal(int s)
{
    s++;
    return s;
}

void prod()
{
    mutex=wait(mutex);
    empty=wait(empty);
    if(counter==bs)
    {
        cout<<"Buffer full";
    }
    else
    {
        cout<<"enter item to produce:";
        cin>>next_prod;
        buffer[in]=next_prod;
        cout<<"Item Produced->"<<next_prod;
        in=(in+1)%bs;
        counter++;
    }
    mutex=signal(mutex);
    full=signal(full);
}

void consum()
{
    mutex=wait(mutex);
    full=wait(full);
    if(counter==0)
    {
        cout<<"Buffer empty";
    }
    else
    {
        next_consum=buffer[out];
        cout<<"Item Consumed->"<<next_consum;
        out=(out+1)%bs;
        counter--;
    }
    empty=signal(empty);
    mutex=signal(mutex);
}
