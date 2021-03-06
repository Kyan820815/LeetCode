//--- Q: 0255. Verify Preorder Sequence in Binary Search Tree

//--- method 1: O(n) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        vector<int> sk;
        int minv = INT_MIN;
        for (int i = 0; i < preorder.size(); ++i) {
            if (minv >= preorder[i]) {
                return false;
            }
            while (sk.size() && sk.back() < preorder[i]) {
                minv = sk.back();
                sk.pop_back();
            }
            sk.push_back(preorder[i]);
        }
        return true;
    }
};

//--- method 2: O(1) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int idx = -1, minv = INT_MIN;
        for (int i = 0; i < preorder.size(); ++i) {
            if (minv >= preorder[i]) {
                return false;
            }
            while (idx >= 0 && preorder[idx] < preorder[i]) {
                minv = preorder[idx--];
            }
            preorder[++idx] = preorder[i];
        }
        return true;
    }
};

//--- follow up: postorder
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        postorder = {10, 3, 2, 6, 5};
        // postorder = {1, 3, 2, 6, 5};
        int maxv = INT_MAX, idx = postorder.size();
        for (int i = 0; i < postorder.size(); ++i) {
            if (maxv <= postorder[i]) {
                return false;
            }
            while (idx < postorder.size() && postorder[idx] > postorder[i]) {
                maxv = postorder[idx++];
            }
            postorder[--idx] = postorder[i];
        }
        return true;
    }
};
