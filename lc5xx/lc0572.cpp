//--- Q: 572. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder traversal
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        else if (!s || !t) return false;
        if (s->val == t->val && isSameTree(s,t))
        		return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
    	if (!s & !t) return true;
    	if (!s || !t) return false;
    	if (s->val != t->val) return false;
    	return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

//--- method 2: string recording for substree
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string sstr = postorder(s);
        string tstr = postorder(t);
        return sstr.find(tstr) != string::npos;
    }
    string postorder(TreeNode *root)
    {
    	string strl = ",#", strr = ",#";
    	if (root->left)
    		strl = postorder(root->left);
    	if (root->right)
    		strr = postorder(root->right);
    	string now = "," + to_string(root->val) + strl + strr;
    	return now;
    }
};