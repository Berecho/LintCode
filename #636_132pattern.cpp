class Solution {
public:
    /**
     * @param nums a list of n integers
     * @return true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int>& nums) {
        // Write your code here
        int second,third,i=nums.size()-2;
        second=INT_MIN;
        if(nums.size()<3)
            return false;
        stack<int> wait;
        wait.push(nums.back());
        while(i>=0){
            if(nums[i]<second) 
                return true;
            if(wait.top()>nums[i])
                wait.push(nums[i]);
            else 
            {
                while(!wait.empty()&&wait.top()<nums[i]){
                    second=wait.top();
                    wait.pop();
                }
                wait.push(nums[i]);
            }
            i--;
        }
        return false;
    }
};
