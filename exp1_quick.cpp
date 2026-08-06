#include<bits/stdc++.h>
using namespace std;



int partition(int arr, int low, int high){
    int pi = arr[high];
    int i = low - 1;
    for (int j=0; j<high; j++){
        if(arr[j]<=pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }

}

int QuickSort(int arr, int low, int high){
    if(low <= high){
        int pi = partition( arr,  low,  high);
        QuickSort( arr, low, pi-1);
        QuickSort(arr, pi+1, high);

    }
}

int main(){
    int arr[6] = {2, 1, 7, 0, 5, 3};
    int n = sizeof(arr);


}