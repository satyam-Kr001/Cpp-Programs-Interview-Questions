/*
------------------------This is a program to print smallest indexed repeating element -----------------
*/

#include<bits/stdc++.h>
using namespace std;

int repeatingEle(int arr[], int n){
    int N = INT_MAX;
    int idx[N];
    for(int i=0; i<N; i++){
        idx[i] = -1;
    } 
    int minidx = INT_MAX;
    for(int i=0; i<n; i++){
        if(idx[arr[i]]!=-1){
            minidx = min(minidx, idx[arr[i]]);
        }
        else {
            idx[arr[i]] = i;
        }
    }
    if(minidx == INT_MAX){
        cout << -1 <<endl;
    }
    else{
        return minidx+1 ;
    }
    cout << "Ji";
}

// int repeatingEle(int arr[], int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i]==arr[j]){
//                 return i;
//             }
//         }
//     }
// }

// int repeatingELe(int arr[], int n){
//     map<int, int> m;
//     for(int i=0; i<n; i++){
//         m[arr[i]]++;
//     }
//     map<int, int> :: iterator itr;  
//     int idx = -1;
//     for(itr = m.begin(); itr!=m.end(); itr++){
//         cout << itr->first << " ";
//         idx++;
//         if(itr->second>1){
//             return idx;
//         }
//     }
// }


int main(){
    int arr[] = {1,5,3,4,3,5,6};
    int n = 7;
    // int res = repeatingEle(arr,n);
    int res = repeatingEle(arr,n);
    cout << res;
    cout << "HII";
    return 0;
}