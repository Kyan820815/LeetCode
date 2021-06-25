//--- Q: 136. Single Number

//--- method 1: xor operation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int res;
  		for (int i = 0; i < nums.size(); ++i)
  			res ^= nums[i];
  		return res;
    }
};