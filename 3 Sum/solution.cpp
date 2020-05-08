class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      
      // size of the array nums
      int total = nums.size(); 
      
      // sort the numbers
      sort(nums.begin(), nums.end());
      
      // fix the first number of the triplet
      for (int firstNumIdx = 0; firstNumIdx < total; ++firstNumIdx) {
        int firstNum = nums[firstNumIdx];
        // find pairs with sum = -firstNum in the right
        int start = firstNumIdx + 1;
        int end = total - 1;
        while (start < end) {
          // consider the current pair sum
          int current = nums[start] + nums[end];
          if (current < -firstNum) {
            // shift the start pointer to the right
            ++start;
          } else if (current > -firstNum) {
            // shift the end pointer to the left
            --end;
          } else {
            // add to the result
            res.push_back({firstNum, nums[start], nums[end]});
            int oldStart = start;
            int oldEnd = end;
            // shift the start till it matches the old value
            while (start < end && nums[start] == nums[oldStart]) {
              ++start;
            }
            // shift the end till it matches the old value
            while (end > start && nums[end] == nums[oldEnd]) {
              --end;
            }
            // the above two while loops ensure that both start/end
            // get shifted atleast once
          }
          // avoid duplicates
          while (firstNumIdx + 1 < total 
                 && nums[firstNumIdx + 1] == nums[firstNumIdx]) {
            ++firstNumIdx;
          }
        }
      }
      
      return res;
    }
};