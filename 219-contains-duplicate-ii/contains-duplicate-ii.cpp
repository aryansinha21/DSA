class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> Seen;
        for (int i = 0; i < nums.size(); i++) {
            if (Seen.find(nums[i]) != Seen.end()) {
                if (i - Seen[nums[i]] <= k) {
                    return true;
                }
            }
            Seen[nums[i]] = i; 
        }
        return false;
    }
};