class Trie {
public:
    struct Node {
        Node* children[26];
        bool end;
    };
    
    Node* root;
    
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

class Solution {
public:
    int dx[4] {-1, 0, 0, 1};
    int dy[4] {0, -1, 1, 0};
    int n, m;
    vector<vector<bool>> chk;
    vector<string> ans;
    Trie trie;
    string now;
    
    void dfs(int i, int j, Trie::Node* node, Trie::Node* par, vector<vector<char>>& board) {
        for (int d=0; d<4; d++) {
            int x = i+dx[d];
            int y = j+dy[d];
            if (x<0 || x>=n || y<0 || y>=m) continue;
            if (chk[x][y]) continue;
            if (node->children[board[x][y]-'a']) {
                chk[x][y] = 1;
                now.push_back(board[x][y]);
                if (node->children[board[x][y]-'a']->end) {
                    ans.push_back(now);
                    node->children[board[x][y]-'a']->end = 0;
                }
                dfs(x, y, node->children[board[x][y]-'a'], node, board);
                now.pop_back();
                chk[x][y] = 0;
            }
        }
        
        int cnt = 0;
        for (int i=0; i<26; i++) {
            if (node->children[i]) cnt++;
        }
        if (!cnt) {
            for (int i=0; i<26; i++) {
                if (par->children[i] == node) {
                    par->children[i] = nullptr;
                    break;
                }
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        chk.assign(n, vector<bool>(m, 0));
        
        for (int k=0; k<words.size(); k++) {
            trie.insert(words[k]);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (trie.root->children[board[i][j]-'a']) {
                    chk[i][j] = 1;
                    now.push_back(board[i][j]);
                    if (trie.root->children[board[i][j]-'a']->end) {
                        ans.push_back(now);
                        trie.root->children[board[i][j]-'a']->end = 0;
                    }
                    dfs(i, j, trie.root->children[board[i][j]-'a'], trie.root, board);
                    now.pop_back();
                    chk[i][j] = 0;
                }
            }
        }
        return ans;
    }
};