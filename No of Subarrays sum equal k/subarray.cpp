#include <bits/stdc++.h>
using namespace std;
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = nums[i];
            for(int j=i+1 ; j<n ; j++){
                sum = sum+nums[j];
                if(sum == k){
                    count++;
                }
            } 
        }
        return count;
    }
    int main(){
        vector <int> nums = {1,1,1,1};
        int k = 2;
        int res = subarraySum(nums, k);
        cout << res;
    }
    