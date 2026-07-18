class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hDupSet;
        for(int i=0; i<nums.size(); i++)
        {
            if(hDupSet.contains(nums[i]))
            {
                return true;
            }
            hDupSet.insert(nums[i]);
        }
        return false;
    }
};