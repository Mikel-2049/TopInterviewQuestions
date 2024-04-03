class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        /*
        info
            input: Integer Array
            output: Integer (maximum profit)
            contraints:
                Max Array Size: 3*10^4
                Max Integer: 10^4
                
        example:
            prices = [7,1,5,3,6,4]
            5 - 1 = 4
            6 - 3 = 3
            7
            
        brute force:
            greedy algorithm
            we check if we are starting at lowest num
            run an initial traverse, stop once they go up
            if they never go up, return 0
            traverse from starting point and check until the end
            come back with the biggest value difference
                    
            complexity:
                runtime: O(n)
                space: O(n)
                
        optimize:
            *sliding window
            we check if we are starting at lowest num
            run an initial traverse, stop once they go up
            if they never go up, return 0
            traverse from starting point
            if new number > current number, sell
            save profit
            sum profits
        */
        
        int profit = 0;
        int n = prices.size();
        
        if (n <= 1) return 0; // If there's 0 or 1 prices, no profit can be made
        
        // Find the position of the first number where the next number is bigger than itself
        int position = findFirstIncreasePosition(prices);
        if (position == -1) return 0; // If there's no such position, no profit can be made

        for (int i = position; i < n - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        
        return profit;
    }

private:
    // Helper function to find the position of the first increase
    int findFirstIncreasePosition(const vector<int>& prices) {
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                return i; // Return the position as soon as an increase is found
            }
        }
        return -1; // Return -1 if no increase is found
    }
};
