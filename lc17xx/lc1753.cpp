//--- Q: 1753. Maximum Score From Removing Stones

//--- method 1: find max and min
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int res = 0;
        vector<int> arr = {a, b, c};
        while (1) {
            sort(arr.begin(), arr.end());
            if (!arr[0]) {
                res += min(arr[1], arr[2]);
                break;
            } else {
                ++res;
                --arr[0], --arr[2];
            }
        }
        return res;
    }
};