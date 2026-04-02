Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 1 - Two-Pointer (Overwrite then Fill Zeros) – O(n) time, fewer swaps
First, copy all non-zero elements to the front. Then fill the remaining positions with zeros. This avoids swaps (reduces writes if zero count is high).

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;                            // pos is the position of the first zero in the array
        for (int i = 0; i< nums.size(); ++i){   // i is the position of the current element in the array
            if (nums[i] != 0){                  // if the current element is not zero, move it to the position of the first zero
                nums[pos++] = nums[i];          //
            }
        }
        while (pos < nums.size()){              // after moving all the non-zero elements to the front of the array, fill the rest of the array with zeros
            nums[pos++] = 0;                    // pos is the position of the first zero in the array
        }
        
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 2 - Two-Pointer (Swap) – O(n) time, O(1) space
Use one pointer lastNonZeroFoundAt to track the position where the next non-zero element should be placed. Iterate through the array; when a non-zero is found, swap it with the element at lastNonZeroFoundAt and increment the pointer.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {                // Two-pointer approach
        int lastNonZero = 0;                            // Pointer to track the position of the last non-zero element
        for (int i = 0; i < nums.size(); ++i) {         // Iterate through the array
            if (nums[i] != 0) {                         // If the current element is non-zero
                swap(nums[lastNonZero], nums[i]);       // Swap the current non-zero element with the element at lastNonZero index
                ++lastNonZero;                          // Move the lastNonZero pointer to the next position
            }
        }
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 3 - Using std::stable_partition (STL) – O(n) time
Use the C++ algorithm stable_partition which reorders elements based on a predicate while preserving relative order. Partition nums so that all non-zero elements come before zeros.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {                                                // 1. Two Pointers
        stable_partition(nums.begin(), nums.end(), [](int x) { return x != 0; });       // the process of partitioning the range [first, last) into two groups: those for which the predicate returns true and those for which it returns false, while preserving the relative order of the elements in each group.
    }                                                                                   //the stable_partition algorithm rearranges the elements in the range [first, last) such that all elements for which the predicate returns true are placed before all elements for which the predicate returns false, while maintaining the relative order of the elements in each group.
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 4 - Optimized Two-Pointer (Minimizing Operations) – O(n)
Combine the swap method but avoid swapping when the element is already in the correct place (i.e., i == lastNonZero and nums[i] != 0). This reduces unnecessary swaps.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {            // Two Pointers
        int lastNonZero = 0;                        //int lastNonZero = 0; // Pointer to the last non-zero element
        for (int i = 0; i < nums.size(); i++){      // Iterate through the array
            if (nums[i] != 0){                      //here we check if the current element is non-zero then we swap it with the last non-zero element 
                if (i != lastNonZero    ){          // Swap the current element with the last non-zero element and increment the last non-zero pointer
                    swap(nums[lastNonZero],nums[i]);//here we check if the current index is not equal to the last non-zero index then we swap the elements at those indices and increment the last non-zero pointer. This way we move all the non-zero elements to the front of the array and all the zeroes to the end of the array.
                }
                ++lastNonZero;                         // Increment the last non-zero pointer
            }
        }
    }        
};    
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 5 - Brute Force (Shifting) Time: O(n²) – worst case when many zeros. Space: O(1) – in-place.
Iterate through the array. When a zero is found, shift all subsequent elements one position left, then place the zero at the end. This is O(n²) time.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {           
        int n = nums.size();                        // Get the size of the input vector
        int i = 0;                                  // Initialize index i to 0
        while (i < n) {                             //here we loop through the vector until we reach the end such that we can check for zeroes and move them to the end and also maintain the order of non-zero elements
            if (nums[i] == 0) {                     // If the current element is zero, we need to move it to the end
                for (int j = i; j < n - 1; ++j) {   // Shift all elements to the left starting from index i to n-1
                    nums[j] = nums[j + 1];
                }
                nums[n - 1] = 0;                    // Place zero at the end of the vector
                --n;                    // Decrease n to avoid checking the last element which is now zero
            } else {
                ++i;                         // If the current element is not zero, move to the next index
            }
        }
    }
};

________________________________________________________________________________________________________________________________________________________________________________________________________________________-

Method	                        Time	Space	      Writes (approx)	            Pros	                                              Cons
Brute Force (shift)            	O(n²)	O(1)	      O(n²)                    	  Simple to understand	                              Very slow for large n
Two-pointer (swap)            	O(n)	O(1)	      ≤ 3n (if all swapped)      	Standard, simple, in‑place      	                  More writes than overwrite method
Overwrite then fill zeros	      O(n)	O(1)      	≤ 2n	                      Fewer writes, good for large zero counts	          Two passes
stable_partition	              O(n)	O(1)?      	Implementation dependent	  One line of code	                                  May use extra memory;less control
Optimized swap (skip self)	    O(n)	O(1)	      ≤ 3n but fewer in practice	Minimizes swaps when array already partly ordered  	Slightly more complex logic


















