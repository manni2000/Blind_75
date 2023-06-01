#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;

       for(auto i:nums){
           hashset.insert(i);
       }
       int longestset = 0;

       for(auto i:nums){
           if(!hashset.count(i-1)){
               int currentNum = i;
               int count = 1;

               while(hashset.count(currentNum+1)){
                   currentNum+=1;
                   count+=1;
               }
            longestset = max(longestset, count);
           }
       }
       return longestset;
    }
};

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution obj;
    int result = obj.longestConsecutive(nums);
    std::cout<<result;

  return 0;
}