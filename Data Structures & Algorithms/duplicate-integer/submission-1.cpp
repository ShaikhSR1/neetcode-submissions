class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hSeen;
        for(int num : nums)
        {
            if(hSeen.count(num) > 0)
            {
                return true;
            }
            hSeen.insert(num);
        }
        return false;
    }
};