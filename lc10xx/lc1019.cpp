//--- Q: 1019. Next Greater Node In Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: two pass O(n) backtrack, better
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode *cur;
        stack<int> sk;
        cur = head;
        while(cur)
        {
        	res.push_back(cur->val);
        	cur = cur->next;
        }
        for (int i = res.size()-1; i >= 0 ; --i)
        {
        	while (sk.size() != 0 && sk.top() <= res[i])
        	{
        		sk.pop();
        	}
        	int val = res[i];
        	if (!sk.size())
        		res[i] = 0;
        	else
        		res[i] = sk.top();
        	sk.push(val);
        }
        return res;
    }
};

//--- method 2: two pass O(n)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode *cur;
        stack<pair<int,int>> sk;
        int cnt;
        cur = head, cnt = 0;
        while(cur)
        {
        	cur = cur->next;
        	cnt++;
        }
        res = vector<int>(cnt, 0);
        cur = head, cnt = 0;
        while (cur)
        {
        	while (sk.size() != 0 && sk.top().second < cur->val)
        	{
        		res[sk.top().first] = cur->val;
        		sk.pop();
        	}
        	sk.push({cnt++, cur->val});
        	cur = cur->next;
        }

        return res;
    }
};