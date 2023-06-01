#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset; // set is used to container
        // that stores unique elements. It does not allow duplicates.
        
        for(int n: nums){ //Check if the current element 'n' is already present in the hashset

            if(hashset.count(n)>0){ //Found duplicate in hashset
                return true; //return true
            }
            hashset.insert(n); // Add next elements of nums in hashset
        }
     return false; //otherwise return false
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    bool result1 = solution.containsDuplicate(nums1);
    std::cout << "Contains duplicate in nums1? " << (result1 ? "Yes" : "No") << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 1, 5};
    bool result2 = solution.containsDuplicate(nums2);
    std::cout << "Contains duplicate in nums2? " << (result2 ? "Yes" : "No") << std::endl;

    return 0;
}
