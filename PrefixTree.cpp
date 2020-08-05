class TrieNode{
    public:
        char val;
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
        TrieNode(){}
        TrieNode(char v){val = v;}
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        for(char ch:word) {
            if(current->children.find(ch) == current->children.end()){
                current->children[ch] = new TrieNode(ch);
            }
               current = current->children[ch];
        }
               current->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;
        for(char ch:word) {
            if(current->children.find(ch) == current->children.end()){
                return false;
            }
               current = current->children[ch];
        }
              return current->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(char ch:prefix){
            if(current->children.find(ch) == current->children.end()){
                return false;
            }
            current = current->children[ch];
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