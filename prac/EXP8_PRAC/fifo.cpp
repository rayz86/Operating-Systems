#include<iostream>
using namespace std;
#define max 10

int main()
{
    int page_found=0;
    int page_faults=0;
    int replacement_index=0;
    int ram_size, n;
    int ram[max],pageref[max];

    cout<<"enter the no of pages:";
    cin>>n;

    cout<<"enter the ram size:";
    cin>>ram_size;

    cout<<"enter pages:";
    for(int i=0;i<n;i++)
        cin>>pageref[i];

    for(int i=0;i<ram_size;i++)
        ram[i]=-1;
    
    for(int i=0;i<n;i++)
    {
        page_found=0;
        for(int j=0;j<ram_size;j++)
        {
            if(pageref[i]==ram[i])
            {
                page_found=1;
            }
        }
        if(!page_found)
        {
            page_faults++;
            ram[replacement_index]=pageref[i];
            replacement_index=(replacement_index+1) % ram_size;
        }
    }
    cout<<"Page Faults:"<<page_faults;
}