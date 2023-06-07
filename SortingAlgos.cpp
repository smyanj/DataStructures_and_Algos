#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
//Insertion sort
void insertion_sort(double arr[], int size){
    //Initializing to 0
    int key = 0;
    int i = 0;

    for(int t = 0; t < size; t++){
        key = arr[t];
        //Insert t into sorted sequence
        i = t - 1;
        while(i > 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}
//Swap value function
void swap(int& x, int&y){
    //saves value of x into t to be swapped into y later
    int t = x;
    x = y;
    //y = x
    y = t;
}

//Selection sort
void selection_sort(double arr[], int size){
    int min;
    for(int i = 0; i < size - 1; i++){
        min = i;
        for(int j = i+1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}
//Quick sort function + partition within quicksort
int partition(double arr[], int p, int r){
    double move = arr[r];
    int t = (p-1);
    for(int i = p; i <= r; i++){
        if(arr[i] < move){
            t++;
            swap(arr[t], arr[i]);
        }
    }
    swap(arr[t+1], arr[r]);
    return (t+1);
}
void quick_sort(double arr[], int p, int r){
    if(p < r){
        int part = partition(arr, p, r);
        quick_sort(arr, p, part-1);
        quick_sort(arr, part+1, r);
    }
}
//Merge-sort
void merge(double arr[], int first, int second, int third){
    int p;
    int q;
    int r;

    int n1 = second - first + 1;
    int n2 = third - second;
    //assigning the left and right side to the array val
    double left[n1];
    double right[n2];

    //Iterating 
    for(p = 0; p < n1; p++)
        left[p] = arr[first + p]; 
    for(q = 0; q < n2; q++)
        right[q] = arr[second + q + 1];
    
    //Reset values to 0
    p = 0;
    q = 0;
    r = first;

    while(p < n1 && q < n2){
        if(left[p] <= right[q]){
            arr[r] = left[p];
            p++;
        }else{
            arr[r] = right[q];
            q++;
        }
        r++;
    }
    while(p < n1){
        arr[r] = left[p];
        p++;
        r++;
    }
    while(q < n2){
        arr[r] = right[q];
        q++;
        r++;
    }
}
void merge_sort(double arr[], int first, int third){
    if(first < third){
        int second = first + (third - first) / 2;
        //Call recursively
        merge_sort(arr, first, second);
        merge_sort(arr, second + 1, third);

        merge(arr, first, second, third);
    }
}
//Generating a random double(value) array
void randArr(double arr[], int a){
    //Use built in function srand
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < a; i++){
        arr[i] = 100.00 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / (1000.00 - 100.00));
        //arr[i] = 100.00 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (1000.00 - 100)));
    }
}
//
int main(){
    const int size = 100000;
    //double arr[size];
    double* arr = new double[size];

    //Create the random array using randArr
    randArr(arr, size);
    //Instantiate Insertion sort (runtime)
    double insertion_array[size];
    copy(arr, arr + size, insertion_array);
    clock_t start_insertion = clock();
    insertion_sort(insertion_array, size);
    clock_t end_insertion_cycle = clock();
    double inser_total_time = double(end_insertion_cycle - start_insertion) / CLOCKS_PER_SEC;
    //Instantiate selection sort (runtime)
    double selec_new_arr[size];
    copy(arr, arr+size, selec_new_arr);
    clock_t start_selection = clock();
    selection_sort(selec_new_arr, size);
    clock_t end_selection_cycle = clock();
    double selec_total_time = double(end_selection_cycle - start_selection) / CLOCKS_PER_SEC;
    //Instantiate Quick sort (runtime)
    double quick_new_arr[size];
    copy(arr, arr+size, quick_new_arr);
    clock_t start_quick = clock();
    quick_sort(quick_new_arr, 0, size-1);
    clock_t end_quick_cycle = clock();
    double quick_total_time = double(end_quick_cycle - start_quick) / CLOCKS_PER_SEC;
    //Instantiate Merge sort (runtime)
    double merge_new_arr[size];
    copy(arr, arr+size, merge_new_arr);
    clock_t start_merge = clock();
    merge_sort(merge_new_arr, 0, size-1);
    clock_t end_merge_cycle = clock();
    double merge_total_time = double(end_merge_cycle - start_merge) / CLOCKS_PER_SEC;
    //Final output table 
    cout << "Insertion Sort Time: " << inser_total_time * 1000 << " milliseconds" << endl;
    cout << "Selection Sort Time: " << selec_total_time * 1000 << " milliseconds" << endl;
    cout << "Quick Sort Time: " << quick_total_time * 1000 << " milliseconds" << endl;
    cout << "Merge Sort Time: " << merge_total_time * 1000 << " milliseconds" << endl;

    cout << "Press any key to exit... ";
    cin.get();

    

    return 0;
}

