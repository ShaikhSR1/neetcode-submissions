class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Fixed-size array for 26 lowercase English letters
        int count[26] = {0}; 

        for (int i = 0; i < s.length(); i++) {
            // 's[i] - 'a'' maps 'a'->0, 'b'->1, ..., 'z'->25
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // Check if all letter counts returned to 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};