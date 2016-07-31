class ValidWordAbbr {
protected:
    unordered_map<string> m_set;
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
           const stirng& word = dictionary[i];
            m_set.insert(calculateAbbreviation(word));
        }
    }

    bool isUnique(string word) {
        return m_set.count(calculateAbbreviation(word)) == 0; 
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");