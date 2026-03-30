Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method 1 : Brute force ( O(n^2) ) using the direct loop

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //iterate through the array to check the every indexes which will give the target
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1 ; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

------------------------------------------------------------------------------------------------------------------------------
Methods 2 : using the hash map ( O(n) )

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //now we can use a hash map to store the numbers as keys and their indices as values
        unordered_map<int, int> hashMap;
        //we can iterate through the array and check if the complement of the current number exists in the hash map
        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];        //here finded the comlement for each no then check complement if available or not
            //if the complement exists in the hash map, we can return the indices of the current number and the complement
            if (hashMap.find(complement) != hashMap.end()){      //it checks if the complement exists in the hash map if not then it will return hashMap.end() which is an iterator pointing to the end of the map
                return {hashMap[complement], i};
            }
            hashMap[nums[i]] = i;   //if the complement does not exist in the hash map, we can add the current number and its index to the hash map
        }
        return {};//if no solution is found, we can return an empty vector
    }
};
