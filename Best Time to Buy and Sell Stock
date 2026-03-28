You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
solution:
public:
    int maxProfit(vector<int>& prices) {
        //INT_MAX is the maximum value an int can hold, so we initialize minPrice to this value to ensure that any price in the array will be less than it, allowing us to correctly identify the minimum price as we iterate through the array.
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices){
            // If the current price is less than the minimum price found so far, we update minPrice to this new lower price.
            if (price < minPrice){     
                minPrice = price;
            }
            // If the current price is greater than the minimum price, we calculate the potential profit by subtracting minPrice from the current price. If this potential profit is greater than the maxProfit we've recorded so far, we update maxProfit to this new value.
            else if (price - minPrice > maxProfit ){  
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
        
    }
};
