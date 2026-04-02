Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 1 - Kadane’s Algorithm (Dynamic Programming) – O(n) Time, O(1) Space

class Solution {
public:
    int maxSubArray(vector<int>& nums) {                    //Kadane's Algorithm
        int maxSum = nums[0];                               //Initialize maxSum with the first element of the array
        int currSum = nums[0];                              //Initialize currSum with the first element of the array
        for (int i = 1; i < nums.size(); ++i) {             //Iterate through the array starting from the second element
            currSum = max(nums[i], currSum + nums[i]);      //Decide whether to extend the existing subarray or start a new one
            maxSum = max(maxSum, currSum);                  //Update the maximum sum if the current sum is larger
        }
        return maxSum;                      //Return the maximum sum of a contiguous subarray   
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 2 - Divide and Conquer – O(n log n) Time, O(log n) Space (recursion stack)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);            // Time complexity: O(n log n) due to the divide and conquer approach
    }
private:
    int divideAndConquer(vector<int>& nums, int left, int right) {     // Time complexity: O(n) for each level of recursion, and there are log n levels, resulting in O(n log n) overall
        if(left == right) return nums[left];                          // Base case: if the left and right indices are the same, return the single element at that index
        int mid = left + (right - left) / 2;                           // Calculate the midpoint index to divide the array into two halves

        int leftMax = divideAndConquer(nums, left,mid);              // Recursively find the maximum subarray sum in the left half of the array 
        int rightMax = divideAndConquer(nums, mid + 1, reight);     // Recursively find the maximum subarray sum in the right half of the array
        int crossMax = crossdSum(nums,left,mid,right);              // Calculate the maximum subarray sum that crosses the midpoint, which includes elements from both halves of the array

        return max{leftMax, rightMax, crossMax};                    // Return the maximum of the three values: the maximum subarray sum in the left half, the maximum subarray sum in the right half, and the maximum subarray sum that crosses the midpoint
    }

    int maxCrossSum(vector<int>& nums, int left, int mid, int right) {     // Time complexity: O(n) because we iterate through the elements from the midpoint to the left and from the midpoint to the right once each
        int leftSum = INT_MIN;                                             // Initialize leftSum to the smallest possible integer value to ensure that any sum calculated will be greater than this initial value
        int sum = 0;
        for (int i = mid; i>= left ; --i){                                  // Iterate from the midpoint to the left, adding each element to the sum variable. If the current sum exceeds leftSum, update leftSum to the new value. This loop calculates the maximum subarray sum that ends at the midpoint and extends to the left.
            sum += nums[i];                                                 // Update leftSum if the current sum is greater than the previously recorded leftSum, ensuring that leftSum always holds the maximum subarray sum found so far in this loop
            if (sum > leftSum) leftSum = sum;                               // Update leftSum if the current sum is greater than the previously recorded leftSum, ensuring that leftSum always holds the maximum subarray sum found so far in this loop
        }

        int rightSum = INT_MIN;                                             // Initialize rightSum to the smallest possible integer value for the same reason as leftSum, ensuring that any sum calculated will be greater than this initial value
        sum = 0;
        for (int i = mid + 1 ; i<= right ; i++) {                           // Iterate from the midpoint to the right, adding each element to the sum variable. If the current sum exceeds rightSum, update rightSum to the new value. This loop calculates the maximum subarray sum that starts at the midpoint and extends to the right.
            sum += nums[i];                                                 // Update rightSum if the current sum is greater than the previously recorded rightSum, ensuring that rightSum always holds the maximum subarray sum found so far in this loop
            if (sum > rightSum) {                                           // Update rightSum if the current sum is greater than the previously recorded rightSum, ensuring that rightSum always holds the maximum subarray sum found so far in this loop
                rightSum = sum;                                             // Update rightSum if the current sum is greater than the previously recorded rightSum, ensuring that rightSum always holds the maximum subarray sum found so far in this loop
            }
        }
        return leftSum +rightSum;                                           // Return the sum of leftSum and rightSum, which represents the maximum subarray sum that crosses the midpoint, including elements from both halves of the array
    }

};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 3 - Brute Force – O(n²) Time, O(1) Space

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {            //O(n^2) solution
            int max_sum = nums[0];                      //initially set max_sum to the first element of the array
            for (int i = 0 ; i < nums.size(); i++) {    //iterate through the array
                int sum = 0;                //initialize sum to 0 for each new starting point   
                for (int j = i; j < nums.size(); j++) {     //iterate from the current starting point to the end of the array
                    sum += nums[j];                         //add the current element to the sum
                    if (sum > max_sum) {            //if the current sum is greater than the max_sum, update max_sum
                        max_sum = sum;
                    }
                }
            }
            return max_sum;
        }

}
______________________________________________________________________________________________________________________________________________________________________________________________________________________


Method	            Time Complexity	    Space Complexity	          Pros	                                          Cons
Kadane (DP)	        O(n)	              O(1)	                      Optimal, simple, fast	                          None for this problem
Divide & Conquer	  O(n log n)	        O(log n)	                  Teaches recursion, alternative approach	        Slightly slower, more complex
Brute Force	        O(n²)	              O(1)	                      Easy to implement	                              Too slow for large arrays
























