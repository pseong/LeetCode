class Trie {
public:
    struct Node {
        Node* children[26];
        bool end;
    };
    
    Node* root = nullptr;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (int i=0; i<word.size(); i++) {
            if (!cur->children[word[i]-'a']) {
                Node* n = new Node();
                cur->children[word[i]-'a'] = n;
            }
            cur = cur->children[word[i]-'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (int i=0; i<word.size(); i++) {
            if (!cur->children[word[i]-'a']) return false;
            cur = cur->children[word[i]-'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i=0; i<prefix.size(); i++) {
            if (!cur->children[prefix[i]-'a']) return false;
            cur = cur->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */