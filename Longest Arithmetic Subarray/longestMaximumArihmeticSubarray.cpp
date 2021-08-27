#include<bits/stdc++.h>
using namespace std;

int subarray(int arr[], int n){
    int i =0;
    int diff = arr[0]-arr[1];
    int count = 2;
    int maxcount = 2;
    for(i=2; i<n; i++){
        
        if(arr[i]-arr[i+1]== diff){
            count++;
        }
        
        if(count >maxcount){
            maxcount = count;
        }
            
        else{
            count=2;
            diff = arr[i]-arr[i+1];
        }
    }
    cout << maxcount;
}

int main(){
    int n = 7;
    int arr[] = {10,7,4,6,8,10,11};
    subarray(arr,n);
}