//Producer consumer problem using semaphore n
//Rayyan Shaikh
//21co43

#include<iostream>
int mutex=1, empty=4,in=0, out=0, bs, next_prod, next_consum, full=0, buffer[5],counter=0;
int wait(int);
int signal(int);
void producer();
void consumer();
using namespace std;

int main()
{
    int x;
    cout<<"Enter Buffer Size:";
    cin>>bs;
    while(1)
    {
        cout<<"\n---------------------------------";
        cout<<"\n1.Produce 2.Consume 3.EXIT";
        cout<<"\n---------------------------------";
        cout<<"\nChoice:";
        cin>>x;

        switch(x)
        {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(1);
            default:
                cout<<"INAVLID INPUT";
        }
    }
}

int wait(int s)
{
    if(s<0)  //fixed "while" -> "if"
    {
        cout<<"Deadlock";
    }
    s--;
    return s;
}

int signal(int s)
{
    s++;
    return s;
}

void producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    if(counter==bs)
    {
        cout<<"BUFFER FULL";
    }
    else
    {
        cout<<"Item to produce:";
        cin>>next_prod;
        buffer[in]=next_prod;
        cout<<"\nProduced item: "<<next_prod;
        in=(in+1)%bs;
        counter++;
    }
    mutex=signal(mutex);
    full=signal(full);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    if(counter==0)
    {
        cout<<"BUFFER EMPTY"<<endl;
    }
    else
    {
        next_consum=buffer[out];
        cout<<endl<<"Item consumed:"<<next_consum<<endl;
        out=(out+1)%bs;
        counter--;
    }
    empty=signal(empty);
    mutex=signal(mutex);
}
