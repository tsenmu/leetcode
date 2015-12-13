class Solution {
public:
    vector<int> convert_to_list(string version) {
        vector<int> ans;
        string num; 
        for (int i = 0; i < version.length(); ++i) {
            if (version[i] == '.')  {
                ans.push_back(atoi(num.c_str()));
                num.clear();
            } else {
                num += version[i];
            }
        }
        if (num.length()) {
            ans.push_back(atoi(num.c_str()));
        } 
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = convert_to_list(version1);
        vector<int> v2 = convert_to_list(version2);

        while (v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while (v2.size() < v1.size()) {
            v2.push_back(0);
        }

        for (int i = 0; i < min(v1.size(), v2.size()); ++i) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        return 0;
    }
};