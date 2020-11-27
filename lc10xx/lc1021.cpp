//--- Q: 1021. Remove Outermost Parentheses

//--- method 1: use counter and skip outer parantheness
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int cnt = 1;
        for (int i = 1; i < S.size(); ++i) {
            cnt = S[i] == '(' ? cnt + 1 : cnt -1;
            if (cnt) {
                res.push_back(S[i]);
            } else {
                cnt = 1;
                ++i;
            }
        }
        return res;
    }
};
