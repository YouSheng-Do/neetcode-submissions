class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        while (start < end) {
            while (!isalnum(s[start]) && start < end) {
                ++start;
            }
            while (!isalnum(s[end]) && start < end) {
                --end;
            }
            char a = s[start], b = s[end];

            if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
            if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';
            if (a != b) return false;
            ++start;
            --end;
        }

        return true;
    }
};
