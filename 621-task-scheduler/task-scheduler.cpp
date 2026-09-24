class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char x : tasks)
            freq[x - 'A']++;

        sort(freq.rbegin(), freq.rend());

        int maxFreq = freq[0];

        int gaps = maxFreq - 1;
        int empty = gaps * n;

        for(int i = 1; i < 26; i++)
            empty -= min(freq[i], gaps);

        if(empty < 0)
            empty = 0;

        return tasks.size() + empty;
    }
};