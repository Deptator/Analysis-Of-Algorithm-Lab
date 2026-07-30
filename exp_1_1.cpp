#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, high, pi+1);
    }
}

int main(){
    int n;

    cout<<"Enter the number of elements:";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements:\n";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    QuickSort(arr,0,n-1);

    cout<<"Sorted array:\n";

    for(int i = 0; i<n; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}