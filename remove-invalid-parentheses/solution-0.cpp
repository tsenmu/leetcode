class Solution {
public:

    void dfs(
        unordered_set<string>& results, 
        const string& s, 
        int index, 
        int open, 
        string& result, 
        int rml, 
        int rmr) {
            
    //   cout << index << " " << result << endl;

       if (index == s.length()) {
        //   printf("rml = %d, rmr = %d, open = %d\n", rml, rmr, open);
           cout << result << endl;
            if (rml == 0 && rmr == 0 && open == 0) {
                results.insert(result);
            }
            return;
       }

       if (rml < 0 || rmr < 0) {
            return; 
       }
       
       if (open < 0) {
           return;
       }

        char ch = s[index];
        if (ch == '(') {
            
            if (rml > 0) {
                dfs(results, s, index + 1, open, result, rml - 1, rmr);
            }
            
            
            result.push_back(ch);
            dfs(results, s, index + 1, open + 1, result, rml, rmr);
        } else if (ch == ')') {
            
            if (rmr > 0) {
                dfs(results, s, index + 1, open, result, rml, rmr - 1);
            }
            
            result.push_back(ch);
            dfs(results, s, index + 1, open - 1, result, rml, rmr);
        } else {
            result.push_back(ch);
            dfs(results, s, index + 1, open, result, rml, rmr);
        }
        
        result.pop_back();

    }

    vector<string> removeInvalidParentheses(string s) {
        int rml = 0;
        int rmr = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                rml++;
            } else if (s[i] == ')') {
                if (rml > 0) {
                    rml--;
                } else {
                    rmr++;
                }
            }
        }
        
        // printf("rml = %d, rmr = %d\n", rml, rmr);
        unordered_set<string> results;
        string result;
        dfs(results, s, 0, 0, result, rml, rmr);
        
        vector<string> results_vec(results.begin(), results.end());
        return results_vec;
    }

};