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

        for (int i=0; i<lenS; i++)
        {
            char cS = s[i];
            char cT = t[i];

            count[cS]++;
            count[cT]--;
        }

        for (const auto& i : count)
        {
            if(i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
