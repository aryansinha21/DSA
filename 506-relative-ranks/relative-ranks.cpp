class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.rbegin(), temp.rend());

        vector<string> ans;

        for(int x : score) {
            int r = find(temp.begin(), temp.end(), x) - temp.begin() + 1;

            if(r == 1)
                ans.push_back("Gold Medal");
            else if(r == 2)
                ans.push_back("Silver Medal");
            else if(r == 3)
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(r));
        }

        return ans;
    }
};