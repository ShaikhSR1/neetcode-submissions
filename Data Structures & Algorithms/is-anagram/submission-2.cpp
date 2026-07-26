class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();

        // Check both string length. If not same length then not anagram
        // Can be written as if(s.length() != t.length())
        if(lenS != lenT)
        {
            return false;
        }

        // Create an unorder map (hash map) to store each character frequency
        std::unordered_map<char, int> count;

        // Iterate using any of the string lenght (At this stage both are same)
        for (int i=0; i<lenS; i++)
        {
            // increase for char from s
            count[s[i]]++;

            // decrease for char from t
            count[t[i]]--;
        }

        // iterate over the unordered hash map and check if any frequency is not 0
        for (const auto& i : count)
        {
            if(i.second != 0)
            {
                // not anagram
                return false;
            }
        }

        // anagram found
        return true;
    }
};
