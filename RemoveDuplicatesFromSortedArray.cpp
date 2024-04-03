class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        info
            input: array of integers sorted in increasing order
            output: k, number of uniique elemnts
            contraints:
                * what sizes of the array can i expect? 1 and 30,000
                * what range of values should i expect? -100 and 100
                
        example
            nums = [1,1,2], 
            -> 2, [1,2,x]
            
        brute force
            create an empty array and add the first value
            traverse the array nums
                each time i find a value that is not the last element of the new array
                    add that value to the new array
                    
            complexity:
                runtime: O(n)
                space: O(n)
                
        optimize
            bcr: O(n)
            
            to imporve memory use two pointers
            one fixed that only moves when we find a nuew value
            and another pointer that is traversing the array normally
            
        test:
            
            
                
        */
        
        //get size of array
        int n = nums.size();
        
        //declare variables
        int staticPtr = 0;
        
        /*
        nums = [1,2,2]
                  s
                      i
        
        */
        
        
        //traverse array
        for(int i = 0; i < n; i++){
            
            //check if we found new value
            if(nums[staticPtr] != nums[i]){
                staticPtr++;
                nums[staticPtr] = nums[i];
            }
        }
        
        
        return staticPtr + 1;
        
    }
};