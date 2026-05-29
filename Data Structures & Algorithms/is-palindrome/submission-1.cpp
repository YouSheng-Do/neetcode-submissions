class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        while (start < end) {
            if (!isalnum(s[start])) {
                ++start;
            }
            else if (!isalnum(s[end])) {
                --end;
            }
            else {
                char a = s[start], b = s[end];

                if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
                if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';
                if (a != b) return false;
                ++start;
                --end;
            }
        }

        return true;
    }
};
