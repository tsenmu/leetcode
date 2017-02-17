class TrieNode {
public:
    TrieNode() : children_(26, nullptr) {}
    vector<string> words;
    vector<TrieNode*> children;
};

class Trie {
public: 
    Trie(const vector<string>& words) : root(nullptr) {
        root = new TrieNode();

        for (const string& word : words) {

        }
    }

    void insert(const string& word) {
        TrieNode* current_node = root;
        for (char c : word) {
            int index = static_cast<int>(c - 'a');
            if (current_node->children[index] == nullptr) {
                current_node->children[index] = new TrieNode();
                current_node->children[index].words.push_back(word);
            }
        }
    }
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {

    }
};