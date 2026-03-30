Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method : 1 - Hash table > Time: O(n) — single pass, average O(1) set operations. Space: O(n) — in the worst case, we store all distinct elements.

class Solution{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;                         // Create a hash set to store seen numbers as seen 
        for (int num : nums){                          // Iterate through each number in the input vector nums
            if (seen.find(num) != seen.end()) {       // ***If the search for 'num' did NOT hit a dead end, it means the number was actually found in the set.***
                return true;                         // If so, return true indicating a duplicate was found
            }
            seen.insert(num);                        // Otherwise, insert the number into the set for future reference
        }
        return false:                               // If we finish iterating through all numbers without finding duplicates, return false
    }
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method : 2 - Sorting (best)>  Time Complexity: O(n log n) ,Space Complexity: O(1) (if sorting in-place, ignoring the space used by the sorting algorithm itself)
class solution{
public:
 bool conntainsDuplicate(vector<int>& nums){
    sort(nums.begin(),nums.end());       // first sort the array
    for (int i=1;i<nums.size();i++){     // then check if there are any adjacent elements that are the same
        if (nums[i] == nums[i-1]){       // if there are, return true
            return true;                 //*** if return true occured then function will end without going further 
        }                                // return - exit the function and return the value true to the caller without executing any further code in the function
    }
    return false;                      
 }
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method : 3 - Brute Force ( Not recommended) >  O(n²) time, O(1) space , only for the small arrays

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {           // O(n^2) time complexity 
            for (int j = i + 1; j < nums.size(); j++) {   // O(n) time complexity
                if (nums[i] == nums[j]) return true;      // O(1) time complexity
            }
        }
        return false;
    }
};

______________________________________________________________________________________________________________________________________-

Comparission
Hash Set (previous answer): O(n) time, O(n) space – best for average case.

Sorting: O(n log n) time, O(1) space – useful when space is a concern.

Brute Force: O(n²) time, O(1) space – only for very small arrays.























