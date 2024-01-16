#include<iostream>
using namespace std;
#define max 10

int main()
{
    int ram_size, n;
    int page_faults=0;
    int page_found=0;
    int replacement_index=0;
    int ram[max], pageref[max];
    int frame_index[max];

    cout<<"enter the ram size:";
    cin>>ram_size;
    cout<<"enter the page references:";
    cin>>n;

    cout<<"enter the pages:";
    for(int i=0;i<n;i++)
        cin>>pageref[i];
    
    for(int i=0;i<ram_size;i++)
    {
        ram[i]=-1;
        frame_index[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        page_found=0;
        for(int j=0;j<ram_size;j++)
        {
            if(pageref[i]==ram[j])
            {
                page_found=1;
                frame_index[j]=i;
            }
        }
        if(!page_found)
        {
            page_faults++;
            replacement_index=0;
            for(int j=0;j<ram_size;j++)
            {
                if(frame_index[replacement_index]>frame_index[j])
                {
                    replacement_index=j;
                }
            }
            ram[replacement_index]=pageref[i];
            frame_index[replacement_index]=i;
        }
    }
    cout<<"Page Faults:"<<page_faults;
}