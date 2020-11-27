//--- Q: 448. Find All Numbers Disappeared in an Array

//--- method 1: 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[abs(nums[i])-1] < 0)
        		continue;
        	nums[abs(nums[i])-1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] > 0)
        		res.push_back(i+1);
        }
        return res;
    }
};