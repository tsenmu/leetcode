class ValidWordAbbr {
protected:
    unordered_map<string, int> m_map;
    unordered_set<string> m_set;
    string calculateAbbreviation(const string& word) {
        if (word.length() <= 2) {
            return word;
        } else {
            ostringstream oss;
            oss << word[0] << word.length() - 2 << word[word.length() - 1];
            return oss.str();
        }
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); ++i) {
           const string& word = dictionary[i];
           if (m_set.count(word) == 0) {
               m_map[calculateAbbreviation(word)]++;
               m_set.insert(word);
           } 
        }
    }

    bool isUnique(string word) {
        int countMap = m_map[calculateAbbreviation(word)];
        int countSet = m_set.count(word);
        return countMap == 0 || (countMap == 1 && countSet == 1); 
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");