#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> ans;
void permutation(vector<int> &arr, int idx)
{
    int j =0;
    if (idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i], arr[idx]);
        permutation(arr,idx+1);
        swap(arr[i], arr[idx]);
    }
}
int main()
{
    int n;
    cout << "Enter number of array";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array";
    for(auto &i : arr)
        cin >> i;
    permutation(arr,0);
    for(auto v : ans){
        for(auto i : v){
            cout << i <<" ";
        }
        cout << endl;
    }
}