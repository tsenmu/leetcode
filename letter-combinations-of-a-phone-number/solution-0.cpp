class Solution {
public:

    void dfs(vector<string>& results, int index, string& result, string& digits, vector<string>& records) {
        if (index == digits.length()) {
            if (!result.empty()) {
                results.push_back(result);
            }
            return;
        }

        string& alphas = records[digits[index] - '0'];
        if (alphas.length() == 0) {
            dfs(results, index + 1, result, digits, records);
        } else {
            for (int i = 0; i < alphas.length(); ++i)  {
                result.push_back(alphas[i]);
                dfs(results, index + 1, result, digits, records);
                result.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> records;       
        records.push_back("");
        records.push_back("");
        records.push_back("abc");
        records.push_back("def");
        records.push_back("ghi");
        records.push_back("jkl");
        records.push_back("mno");
        records.push_back("pqrs");
        records.push_back("tuv");
        records.push_back("wxyz");
        
        vector<string> results;
        
        string result;
        dfs(results, 0, result, digits, records);
        return results;
    }
};