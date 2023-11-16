//Page replacement Least recently used algorithm
//Rayyan Shaikh
#include<iostream>
using namespace std;

int main()
{
    int ram_size, n, pages[20], ram[20], page_found, frame_index[20], replacement_index=0, page_faults=0;
    cout<<"Enter the size of RAM :";
    cin>>ram_size;
    cout<<"Enter the no of pages :";
    cin>>n;

    cout<<"Enter the pages:";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];   
    }
    for(int j=0;j<n;j++)
    {
        ram[j]=-1;
        frame_index[j]=-1;
    }

    for(int i=0;i<n;i++)
    {
        page_found=0;
        for(int j=0;j<ram_size;j++)
        {
            if(pages[i]==ram[j])
            {
                page_found=1;
                frame_index[j]=-1;
            }
        }
        if(!page_found)
        {
            page_faults++;
            replacement_index=0;
            for(int j=0;j<ram_size;j++)
            {
                if(frame_index[replacement_index]>frame_index[j])
                    replacement_index=j;
            }
            ram[replacement_index]=pages[i];
            replacement_index=(replacement_index+1)%ram_size;
        }
    }
    cout<<"Total Page Faults: "<<page_faults;
}

// Enter the size of RAM :3
// Enter the no of pages :12
// Enter the pages:0 1 2 3 0 1 4 0 1 2 3 4
// Total Page Faults: 12