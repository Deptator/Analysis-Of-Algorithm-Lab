#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int n = arr.size();

    for (int j=0;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[high]);
        }
    }
}
void Quicksort(int *arr, int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        Quicksort(arr, low , pi-1);
        Quicksort(arr, high , pi+1);

    }
}



int main(){
    vector<int> arr = {2,1,0,7,6,3,5};
    Quicksort(arr,0,arr.size-1);

    for (auto x: arr){
        cout << x <<" ";
    }
    return 0;
}