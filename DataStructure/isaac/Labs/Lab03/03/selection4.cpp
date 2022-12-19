// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
//	selection.cpp - This brute force version of Selection Sort that takes O(n^2).
/*************************************************************
    Lab03 - Understanding a better coding in C/C++
    - NMN(No magic number)
    - DRY(Don't repeat yourself)
    - malloc(), free()
    - assert()
    - rand()
    - mod operator %
    - #if macro
    - Learn about __a better coding__ after all.
***************************************************************/
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

void printList(int *list, int n);
void selectionSort(int *list, int n);

int main(int argc, char *argv[]) {
    int N;
    int * list;
    int rand_num;
    
    if(argc == 1){
        
        do{
        cout << "Enter a number of samples: ";
        cin >> N;
        
        if(N<=1)
            cout << "Retry..." << endl;
            
        }while(N<=1);
        
    }
    
    else{
        N = strtol(argv[1], nullptr, 10);
        
        if(N<=1){
            cout << "Usage: selection [N]" << endl;
            return 0;
        }
        
    }
    
    list = new int(N);
    
    assert(list);
    
    for(int i=0; i<N; i++){
        list[i] = rand()%(N+1);
    }
    
    
    cout << "UNSORTED(" << N << "): " << endl;
    
    printList(list, N);
	
    selectionSort(list, N);

	cout << "SORTED(" << N << "): " << endl;
  
    printList(list, N);

    cout << "Happy Coding~~" << endl;
    
    delete(list);
}

void selectionSort(int *list, int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min]) min = j;
        swap(list[i], list[min]); // Swap min found with the 1st data unsorted
    }
}

void printList(int *list, int n){
    
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
        
    printf("\n");
}
