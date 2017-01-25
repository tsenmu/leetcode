class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) {
            return 0;
        }

        if (input[input.length() - 1] != '\n') {
            input.push_back('\n');
        }

        const int n = input.length();

        stack<int> path_len;

        int ans = 0;
        int current_len = 0;
        int current_depth = 1;
        bool contains_dot = false;
        bool has_extension = false;

        for (int i = 0; i < n; ++i) {
            const char ch = input[i];
            if (ch == '\n') {

                while (path_len.size() >= current_depth) {
                    path_len.pop();
                }
                
                const int new_len = current_len + (path_len.empty() ? 0 : (path_len.top() + 1));

                if (has_extension) {
                    ans = max(new_len, ans);
                } else {
                    path_len.push(new_len);
                }
                
                current_len = 0;
                current_depth = 1;
                contains_dot = false;
                has_extension = false;

            } else if (ch == '\t') {
                current_depth++;
            } else if (ch == '.') {
                current_len++; 
                contains_dot = true;
            } else {
                current_len++;
                if (contains_dot) {
                    has_extension = true;
                }
            }
        }

        return ans;
    }
};