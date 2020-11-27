//--- Q: 1018. Binary Prefix Divisible By 5

//--- method 1: mod 5 every step
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int sum = 0;
        vector<bool> res;
        for (int i = 0; i < A.size(); ++i) {
            sum = sum * 2 + A[i];
            sum %= 5;
            res.push_back(!sum);
        }
        return res;
    }
};