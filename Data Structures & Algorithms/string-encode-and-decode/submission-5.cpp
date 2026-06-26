class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string s = "";

        for (auto str : strs) {
            s += to_string(str.size());
            s += ',';
        }
        
        s += '#';

        for (auto str : strs) {
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        if (s == "") return strs;

        int pos = s.find('#');

        string sizes = s.substr(0, pos);
        // cout << sizes << endl;
        
        vector<string> ans;
        int i = 0;
        pos++;
        while (sizes.find(',', i) != string::npos) {
            auto find = sizes.find(',', i);
            // cout << find << endl;
            string size = sizes.substr(i, find - i);
            // cout << size << endl;
            int sz = stoi(size);
            i = find + 1;
            string seg = s.substr(pos, sz);
            // cout << seg << endl;
            ans.push_back(seg);
            pos += sz;
        }

        return ans;
    }
};
