//Page replacement First in First out algorithm
//Rayyan Shaikh
#include<iostream>
using namespace std;

#include <iostream>
#define MAX 100

using namespace std;

int main() {
    int page_found = 0;
    int page_faults = 0;
    int ram_size;
    int no_of_pages;
    int replacement_index = 0;

    int ram[MAX];
    int page_reference[MAX];

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
    }
    for(int i=0; i<no_of_pages; i++) {
        page_found = 0;
        for(int j=0; j<ram_size; j++) {
            if(page_reference[i] == ram[j]) {
                page_found = 1;
            }
        }
        if(!page_found) {
            page_faults++;
            ram[replacement_index] = page_reference[i];
            replacement_index = (replacement_index + 1) % ram_size;
        }
    }
    cout<< "Page Faults : " << page_faults;
    return 0;
}
// 21
// 3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5

// Enter the size of RAM : 3
// Enter no of pages : 21
// Enter the pages : 3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5
// Page Faults : 16