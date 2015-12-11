class Solution {
public:

    void process_token(vector<string>& buf, string& token) {
        if (token.length() != 0) {
            if (token == ".") {
                // ignore 
            } else if (token == "..") {
                if (buf.size() > 0)  {
                    buf.pop_back();
                }
            } else {
                buf.push_back(token);
            }
        }
        token.clear();
    }

    string simplifyPath(string path) {

        vector<string> buf;

        string token;
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') {
                process_token(buf, token);
            } else {
                token += path[i];
            }
        }

        process_token(buf, token);

        string ans;
        for (int i = 0; i < buf.size(); ++i) {
            ans += "/" + buf[i];
        }

        if (ans.empty()) {
            ans = "/" ;
        }

        return ans;
    }
};