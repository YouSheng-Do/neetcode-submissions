class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        string s = "";

        for (string& str : strs) {
            int sz = str.size();
            s += to_string(sz);
            s += "#";
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<string> strs;

        int i = 0;
        int n = s.size();
        while (i < n) {
            int j = i;
            while (s[j] != '#') ++j;

            int sz = stoi(s.substr(i, j - i));

            // pass '#'
            j++;

            string str = s.substr(j, sz);
            strs.push_back(str);
            i = j + sz;
        }

        return strs;
    }
};
