#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        
        // Step 1: Compute prefixGcd using a running maximum
        int current_max = 0;
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], current_max);
        }
        
        // Step 2: Sort prefixGcd in non-decreasing order
        sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3 & 4: Form pairs using two pointers from the outside in
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            totalSum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        // Note: If n is odd, left == right at the end, 
        // which naturally skips the middle unpaired element.
        
        return totalSum;
    }
};