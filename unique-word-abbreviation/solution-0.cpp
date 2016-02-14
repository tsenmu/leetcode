class ValidWordAbbr {
protected:
    unordered_map<string, int> m_count;
    unordered_set<string> m_dict;
    string calculateAbbreviation(const string& str) {
        const int n = str.length();
        if (n <= 2) {
            return str; 
        } 
        return str[0] + to_string(n - 2) + str[n - 1];
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        const int n = dictionary.size();
        for (int i = 0; i < n; ++i) {
            m_dict.insert(dictionary[i]);
            
        }
        
        for (auto it = m_dict.begin(); it != m_dict.end(); ++it) {
            m_count[calculateAbbreviation(*it)]++;
        }
    }

    bool isUnique(string word) {
        string abbr = calculateAbbreviation(word);
        if (m_dict.count(word) == 1) {
            return m_count[abbr] == 1;
        }
        return m_count[abbr] == 0;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");