#include<bits/stdc++.h>
using namespace std;

//Two pointer approach
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {0, 0};
//     }
// };

//TC-O(N^N)
//SC-O(1)

//using Hashmap
class Solution {
public:
vector<int> twoSum(vector<int> &nums, int target){   // nums={2,4,6}, target = {9}
    unordered_map<int,int> numsMap;
    for(int i=0;i<nums.size();i++){
        auto it = numsMap.find(target-nums[i]); // it=target - nums[i]= 9-2=7

        if(it!=numsMap.end()) return {i, it->second}; 
        numsMap.insert({nums[i],i});
    }
    return {0,0};
  }
};

//TC-O(N)
//SC-O(N)

int main(){
    vector<int>nums = {2,4,6};
    int target;

    Solution obj;
    vector<int> result = obj.twoSum(nums,target);

    cout<<result[0]<<","<<result[1]<<endl;

    return 0;
}