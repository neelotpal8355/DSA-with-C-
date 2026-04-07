Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method :1 - Start from the least significant digit (rightmost). Add 1. If the digit becomes 10, set it to 0 and continue the carry to the left. If we finish the loop and still have a carry, insert 1 at the beginning.
Time: O(n) – worst case when all digits are 9. Space: O(1) extra (excluding output).

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // No further carry: increment and return
                digits[i]++;
                return digits;
            }
            // Current digit is 9: set to 0 and continue carry
            digits[i] = 0;
        }
        
        // If we exit the loop, all digits were 9 (e.g., [9,9,9])
        // We need an extra leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 2 - Recursive Approach :use recursion to process from the end . base case : ehn when index <0 , return 1(carry). otherwise , add  carry to current digit  and propogate.
Time: O(n) . Space: O(n) due to recursion stack (could cause stack overflow for large n, but n ≤ 100, fine).

class Solution {
public:
    int add(vector<int>& digits, int i){               //here we use recursion to add 1 to the last digit, if it becomes 10, we set it to 0 and add 1 to the next digit, until we find a digit that is not 9 or we reach the beginning of the array. If we reach the beginning of the array and still have a carry, we need to insert a new digit at the beginning of the array.
        if (i < 0) return 1;                      //first we check if we have reached the beginning of the array, if we have, we return 1 to indicate that we need to insert a new digit at the beginning of the array.
        if (digits[i] +  1 == 10){                //then  we check if the current digit plus 1 equals 10, if it does, we set the current digit to 0 and call the function recursively on the next digit to the left.
            digits[i] = 0;
            return add(digits, i- 1);             //if the current digit plus 1 does not equal 10, we simply add 1 to the current digit and return 0 to indicate that we do not need to insert a new digit at the beginning of the array.
        }else{
            digits[i]++;                          //here we add 1 to the current digit and return 0 to indicate that we do not need to insert a new digit at the beginning of the array.
            return 0;
        }
    }
    vector<int> plusOne(vector<int>& digits) {  // the main function that calls the add function and checks if we need to insert a new digit at the beginning of the array.
        if (add(digits, digits.size() - 1) == 1) { // then we do need to insert a new digit at the beginning of the array, we insert 1 at the beginning of the array.
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 3 -Using a Deque for Efficient Front Insertion :Convert the vector to a deque, which supports O(1) insertion at the front. After processing, convert back to vector.
  Time: O(n) ,Space: O(n) (because we create a deque copy).

vector<int> plusOne(vector<int>& digits) {              //in this approach we first convert the vector to a deque, then we add 1 to the last element and handle the carry if needed. Finally, we convert the deque back to a vector and return it.
    deque<int> dq(digits.begin(), digits.end());        //here we convert the vector to a deque by using the constructor of deque that takes two iterators as arguments. We pass the begin and end iterators of the vector to create a deque with the same elements.
    int carry = 1;
    for (int i = dq.size() - 1; i >= 0 && carry; --i) { //we used loop to iterate through the deque from the last element to the first element. We also check if there is a carry that needs to be added to the current element. If there is no carry, we can stop the loop early.
        int sum = dq[i] + carry;
        dq[i] = sum % 10;                               // we did this to update the current element in the deque with the new value after adding the carry. We use the modulus operator to get the last digit of the sum, which is what we want to store in the current position.
        carry = sum / 10;                              // we did this to calculate the new carry for the next iteration. We use integer division to get the quotient of the sum divided by 10, which will be either 0 or 1 depending on whether the sum is less than 10 or not.    
    }
    if (carry) dq.push_front(1);                        //if there is still a carry after the loop, it means we need to add a new digit at the front of the deque. We can do this by using the push_front method of deque, which adds an element to the front of the deque.
    return vector<int>(dq.begin(), dq.end());           //finally, we convert the deque back to a vector by using the constructor of vector that takes two iterators as arguments. We pass the begin and end iterators of the deque to create a vector with the same elements.
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 4 -Reverse, Process, Reverse :Reverse the array, process from left (which is original LSD), then reverse back.
Time: O(n) – two reverses + one pass. Space: O(1) extra.

  vector<int> plusOne(vector<int>& digits) {                  //in this function we are given a vector of integers and we have to add 1 to the number represented by the vector and return the resulting vector
    reverse(digits.begin(), digits.end());                  //here we are reversing the vector to make it easier to add 1 to the last digit and handle the carry
    int carry = 1;
    for (int i = 0; i < digits.size() && carry; ++i) {      //we are iterating through the digits and adding the carry to the current digit until there is no carry left
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) digits.push_back(1);                         //if there is still a carry left after the loop, it means we need to add a new digit at the end of the vector (which is the beginning of the number)
    reverse(digits.begin(), digits.end());
    return digits;
}
 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Method: 5 - Convert to String then Back :Convert digits to a string, increment the number as a string, then convert back to vector.
  Time: O(n)Space: O(n) for the string and result.

vector<int> plusOne(vector<int>& digits) {          // Convert the digits to a string for easier manipulation
    string num;
    for (int d : digits) num.push_back('0' + d);    //here we are converting the digits to characters and appending them to the string num
    
    int i = num.size() - 1;                          //here we are starting from the last digit of the number and moving towards the first digit
    while (i >= 0 && num[i] == '9') {               // If the current digit is '9', we set it to '0' and move to the next digit
        num[i] = '0';                              
        i--;
    }
    if (i >= 0) num[i]++;                   // If we found a digit that is not '9', we simply increment it  
    else num = "1" + num;
    
    vector<int> result;
    for (char c : num) result.push_back(c - '0');       // Convert the string back to a vector of digits
    return result;
}
________________________________________________________________________________________________________________________________________________________________________________________________________________________________




