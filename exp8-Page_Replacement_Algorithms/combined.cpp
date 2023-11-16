//needs reworking
#include<iostream>
#define SIZE 50
using namespace std;

int frames, str[SIZE], n = 0;

int isThere(int que[], int a)
{
    for(int i = 0; i < frames; i++)
        if(que[i] == a)
            return 1;
    return 0;
}
int f(int que[], int a)
{
    int temp = 0;
    int checked[10] = {0};
    for(int j = a; j >= 0; j --)
    {
        if(temp == frames - 1)
            break;
        for(int i = 0; i < frames; i++)
        {
            if(que[i] == str[j] && temp != frames - 1 && checked[i] != 1)
            {
                temp++;
                checked[i]= 1;
            }
        }
    }
    for(int i = 0; i < frames; i++)
        if(checked[i] == 0)
            return i;
}

int f1(int que[], int a)
{
    int temp = 0;
    int checked[10] = {0};
    for(int j = a; j < n; j++)
    {
        if(temp == frames - 1)
            break;
        for(int i = 0; i < frames; i++)
        {
            if(que[i] == str[j] && temp != frames - 1 && checked[i] != 1)
            {
                temp++;
                checked[i]= 1;
            }
        }
    }
    for(int i = 0; i < frames; i++)
        if(checked[i] == 0)
            return i;

}

void FIFO()
{
    int que[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int pf = 0, ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(!isThere(que, str[i]))
        {
            pf++;
            que[ptr] = str[i];
            ptr = (ptr + 1) % frames;
        }
    }
    cout << "\nTotal Page Faults [FIFO] : " << pf << endl;
}
void LRU()
{
    int que[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int pf = 0, ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(!isThere(que, str[i]))
        {
            if(ptr >= frames)
            {
                int index = f(que, i - 1);
                que[index] = str[i];
            }
            else
                que[ptr++] = str[i];
            pf++;
        }
    }
    cout << "\nTotal Page Faults [LRU] : " << pf<< endl;
}
void Optimal()
{
    int que[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int pf = 0, ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(!isThere(que, str[i]))
        {
            if(ptr >= frames)
            {
                int index = f1(que, i+1);
                que[index] = str[i];
            }
            else
                que[ptr++] = str[i];
            pf++;
        }
    }
    cout << "\nTotal Page Faults [OPTIMAL] : " << pf << endl;
}

int main()
{
    cout <<"Enter the total frames available : ";
    cin >> frames;
    cout << "Enter the page reference string[Enter -1 to stop]:\n";
    do
    {
        cin >> str[n];
    }while(str[n++] != -1);
    n--;
    FIFO();
    LRU();
    Optimal();
    return 0;
}
