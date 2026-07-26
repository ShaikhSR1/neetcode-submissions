#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;

        std::unordered_map<char32_t, int> count;
        int s_chars = 0, t_chars = 0;

        // Decode UTF-8 multi-byte sequences into 32-bit code points
        auto decode_and_count = [](const std::string& str, std::unordered_map<char32_t, int>& map, int delta) {
            int charCount = 0;
            size_t i = 0;
            while (i < str.length()) {
                unsigned char c = str[i];
                char32_t cp = 0;
                int bytes = 1;

                if ((c & 0x80) == 0) {
                    cp = c;
                } else if ((c & 0xE0) == 0xC0) {
                    cp = c & 0x1F; bytes = 2;
                } else if ((c & 0xF0) == 0xE0) {
                    cp = c & 0x0F; bytes = 3;
                } else if ((c & 0xF8) == 0xF0) {
                    cp = c & 0x07; bytes = 4;
                }

                for (int j = 1; j < bytes && (i + j) < str.length(); j++) {
                    cp = (cp << 6) | (str[i + j] & 0x3F);
                }

                map[cp] += delta;
                i += bytes;
                charCount++;
            }
            return charCount;
        };

        s_chars = decode_and_count(s, count, 1);
        t_chars = decode_and_count(t, count, -1);

        // If actual character count differs (e.g. byte length matched but code point count didn't)
        if (s_chars != t_chars) return false;

        for (const auto& [code_point, freq] : count) {
            if (freq != 0) return false;
        }

        return true;
    }
};