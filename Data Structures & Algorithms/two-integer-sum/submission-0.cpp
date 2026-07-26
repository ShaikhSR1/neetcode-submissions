/**
 * In this problem we use a hashmap to store the checked item with its index value
 * When we iterate through each item we check if the different exists or not
 * This is because the compliment of each item is another item in the given list
 * This approach works even if the item is not sorted
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Declare a hash map to store the current number with index
        std::unordered_map<int, int>hasDiff;
        for (int i=0; i<nums.size(); i++)
        {
            // Find the current difference
            int diff = target - nums[i];
            
            // Check in the hash map if the difference exist or not
            if(hasDiff.find(diff) != hasDiff.end())
            {
                // If found return the current iterating index in 2nd as in this approach we actually check the previously checked item
                return {hasDiff[diff], i};
            }

            // Store the current number and its index
            hasDiff[nums[i]] = i;
        }

        // return empty string
        return {};
    }
};
