#include<iostream>
using namespace std;
#define max 10

int main()
{
    int page_faults=0;
    int page_found=0;
    int replacement_index=0;
    int ram_size, n;
    int ram[max],pageref[max];
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
    }
    int maxi, index;
    for(int i=0;i<n;i++)
    {
        page_found=0;
        for(int j=0;j<ram_size;j++)
        {
            if(pageref[i]==ram[j])
            {
                page_found=1;
            }
        }
        if(!page_found)
        {
            page_faults++;
            replacement_index=0;
            maxi=-1;
            for(int j=0;j<ram_size;j++)
            {
                index=-1;
                if(ram[j]==-1)
                {
                    replacement_index=j;
                    break;
                }
                for(int k=i;k<n;k++)
                {
                    if(ram[j]==pageref[k])
                    {
                        index=k;
                        break;
                    }
                }
                if(index==-1)
                {
                    replacement_index=j;
                    break;
                }
                if(max<index)
                {
                    maxi=index;
                    replacement_index=j;
                }
            }
            ram[replacement_index]=pageref[i];
        }
    }
    cout<<"Page Faults:"<<page_faults;
}