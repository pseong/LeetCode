class Trie {
public:
    struct Node {
        Node* child[26] { 0 };
        char c { 0 };
        bool end { 0 };
        
        Node() {}
        Node(char c) {
            this->c = c;
        }
    };
    Node* root;
    
    void _insert(Node* node, string& word, int idx) {
        if (idx == word.size()) {
            node->end = 1;
            return;
        }
        Node* child = node->child[word[idx]-'a'];
        if (child) {
            _insert(child, word, idx+1);
            return;
        }
        child = new Node(word[idx]);
        node->child[word[idx]-'a'] = child;
        _insert(child, word, idx+1);
    }
    
    bool _search(Node* node, string& word, int idx) {
        if (idx == word.size()) return (node->end);
        if (!node->child[word[idx]-'a']) return false;
        return _search(node->child[word[idx]-'a'], word, idx+1);
    }
    
    bool _startsWith(Node* node, string& word, int idx) {
        if (idx == word.size()) return true;
        if (!node->child[word[idx]-'a']) return false;
        return _startsWith(node->child[word[idx]-'a'], word, idx+1);
    }
    
    Trie() {
        root = new Node(0);
        root->end = 1;
    }
    
    void insert(string word) {
        _insert(root, word, 0);
    }
    
    bool search(string word) {
        return _search(root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return _startsWith(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */