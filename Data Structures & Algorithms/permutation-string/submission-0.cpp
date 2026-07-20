class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1 = "abc", s2 = "lecabee"
        //                    ^ *
        
        unordered_map<char, int> diff; // O(26)


        int i = 0, j = s1.size() - 1;

        for(int k = i; k <= j; ++k) {
            diff[s1[k]]++;
            diff[s2[k]]--;
        }

        while (j < s2.size()) {
            if (i != 0) {
                diff[s2[i - 1]]++;
                diff[s2[j]]--;
            }
            bool flag = true;
            for (auto& [_, count] : diff) {
                if (count != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
            ++i; ++j;
        }

        return false;
    }
};
