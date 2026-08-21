class TrieNode {
public:
    TrieNode* childNode[26];
    string word;

    TrieNode() {
        word = "";

        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> ans;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr) {

        // Boundary check
        if(r < 0 || r >= board.size() ||
           c < 0 || c >= board[0].size()) {
            return;
        }

        // Already visited
        if(board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];

        // Character Trie mein nahi hai
        if(curr->childNode[ch - 'a'] == nullptr) {
            return;
        }

        // Trie mein aage badho
        curr = curr->childNode[ch - 'a'];

        // Complete word mil gaya
        if(curr->word != "") {
            ans.push_back(curr->word);

            // Duplicate avoid karne ke liye
            curr->word = "";
        }

        // Mark visited
        board[r][c] = '#';

        // 4 directions
        dfs(board, r + 1, c, curr); // down
        dfs(board, r - 1, c, curr); // up
        dfs(board, r, c + 1, curr); // right
        dfs(board, r, c - 1, curr); // left

        // Backtracking
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new TrieNode();

        // 1. Saare words Trie mein daalo
        for(string word : words) {

            TrieNode* curr = root;

            for(char ch : word) {

                int index = ch - 'a';

                if(curr->childNode[index] == nullptr) {
                    curr->childNode[index] = new TrieNode();
                }

                curr = curr->childNode[index];
            }

            curr->word = word;
        }

        // 2. Board ke har cell se DFS
        for(int r = 0; r < board.size(); r++) {

            for(int c = 0; c < board[0].size(); c++) {

                dfs(board, r, c, root);
            }
        }

        return ans;
    }
};