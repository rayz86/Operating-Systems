//Page replacement Least recently used algorithm
//Rayyan Shaikh
#include <iostream>
#define MAX 100
using namespace std;

int main() 
{
    int page_found, page_faults = 0, ram_size, no_of_pages, replacement_index = 0, ram[MAX], page_reference[MAX], frame_index[MAX];

    cout << "Enter the size of RAM : ";
    cin >> ram_size;

    cout << "Enter no of pages : ";
    cin >> no_of_pages;

    cout << "Enter the pages : ";
    for(int i=0; i<no_of_pages; i++) {
        cin >> page_reference[i];
    }

    for(int j=0; j<ram_size; j++) {
        ram[j] = -1;
        frame_index[j] = -1;
    }

    for(int i=0; i<no_of_pages; i++) {
        page_found = 0;
        for(int j=0; j<ram_size; j++) {
            if(page_reference[i] == ram[j]) {
                page_found = 1;
                frame_index[j] = i;
            }
        }
        if(!page_found) {
            page_faults++;
            replacement_index = 0;
            for(int j=0; j<ram_size; j++) {
                if(frame_index[replacement_index] > frame_index[j]) {
                    replacement_index = j;
                }
            }
            ram[replacement_index] = page_reference[i];
            frame_index[replacement_index] = i;
        }
    }
    cout << "Page Faults : " << page_faults;
    return 0;
}

// Enter the size of RAM : 3
// Enter no of pages : 21
// Enter the pages : 3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5
// Page Faults : 17