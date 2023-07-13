
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
#define MOD int(1e9 + 7)
class Solution {

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>twoPow(n, 0);
        twoPow[0] = 1;
        for(int i=1; i<n; i++) twoPow[i] = (twoPow[i-1] * 2) % MOD;
        int ans = 0;
        int start=0, end=nums.size()-1;
        while(start <= end) {
            int sum = nums[start] + nums[end];
            if(sum > target) {
                end--;
            }
            else {
                ans = (ans + twoPow[end - start]) % MOD;
                start++;
            }
        }
        return ans;
    }
};
