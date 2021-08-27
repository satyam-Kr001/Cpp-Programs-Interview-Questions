/*
......This a program for finding global maxima in an array. Global maxima is an element which is greater
than all the prtevious element and also greater than the following element..........
*/


#include<bits/stdc++.h>
using namespace std;

void recordBreaker(int arr[], int n){
    int max = arr[0];
    int globalmax = 0;
    if(arr[0]>arr[1]){
        cout << arr[1];
    }
    if(arr[n-1]>arr[n-2]){
        cout << arr[n-1];
    }
    for(int i=1; i<n-1; i++){
        if(arr[i]>max and arr[i]>arr[i+1]){
            max = arr[i];
            if(globalmax < max){
                globalmax = max;
            }
        }

        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout << globalmax;
}

int main(){
    int arr[] = {1,2,0,7,2,0,2,2};
    int n = 8;
    recordBreaker(arr,n);
}