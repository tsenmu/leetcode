class Solution {
protected:
    vector<string> helper(int n, int m) {
        vector<string> ans;
        if (m == 0) {
            return ans;
        }

        if (m == 1) {
            ans.push_back("0");
            ans.push_back("1");
            ans.push_back("8");
            return ans;
        }


        vector<string> last = helper(n, m - 2);
        if (last.empty()) {
            last.push_back("");
        }
        for (int i = 0; i < last.size(); ++i) {
            if (n != m) ans.push_back("0" + last[i] + "0");
            ans.push_back("1" + last[i] + "1");
            ans.push_back("6" + last[i] + "9");
            ans.push_back("8" + last[i] + "8");
            ans.push_back("9" + last[i] + "6");
        } 

        return ans;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};