//--- Q: 621. Task Scheduler

//--- method 1: O(n) time, other beautiful code
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int max_len = INT_MIN, max_cnt;
    	int pair_cnts;
        int emply_slots;
        int available_slots;
        int idle;
    	vector<int> cnt(26, 0);

        for (int i = 0; i < tasks.size(); ++i)
			cnt[tasks[i]-'A']++;
        for (int i = 0; i < 26; ++i)
        {
        	if (cnt[i] > max_len)
        	{
        		max_len = cnt[i];
        		max_cnt = 1;
        	}
        	else if (cnt[i] == max_len)
        		max_cnt++;
        }

        pair_cnts = max_len-1;
        emply_slots = pair_cnts*(n-(max_cnt-1));
        available_slots = (int)tasks.size() - max_cnt*max_len;
        idle = max(0, emply_slots-available_slots);

		return (int)tasks.size() + idle;        
    }
};

//--- method 2: O(n) time
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        int maxcnt = 0, kind = 0;
        for (auto &ch: tasks) {
            if (++cnt[ch-'A'] > maxcnt) {
                maxcnt = cnt[ch-'A'];
                kind = 1;
            } else if (cnt[ch-'A'] == maxcnt) {
                ++kind;
            }
        }
        return max((maxcnt-1)*(1+n)+kind, (int)tasks.size());
    }
};