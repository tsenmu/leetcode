class Solution {
private:
    string getOriginalString(const string& word) {
        if (word.empty()) {
            return "";
        }
        int diff = word[0] - 'a';
        string result = word;
        for (int i = 0; i < result.length(); ++i) {
            result[i] = shift(result[i], 26 - diff);
        }
        return result;
    }

    char shift(char ch, int diff) {
        if (diff > 0) {
            return 'a' + (((int)(ch - 'a') + diff) % 26);
        }

        return shift(ch, 26 - (diff % 26));
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dict;
        for (int i = 0; i < strings.size(); ++i) {
            const string& str = strings[i];
            dict[getOriginalString(str)].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};