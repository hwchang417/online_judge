class TrieNode{
public:    
    TrieNode* table[128];
    bool isWord;
        
    TrieNode(){
        memset(table, 0, sizeof(TrieNode*) * 128);
        isWord = false;
    }
    
};

class Trie {
public:
    TrieNode* head;
    
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int idx, size;
        TrieNode* pnode = head;
        
        size = word.size();
        for(idx = 0;idx < size;idx++){
            if(!pnode->table[word[idx]])
                pnode->table[word[idx]] = new TrieNode();
            pnode = pnode->table[word[idx]];
        }
        pnode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int idx, size;
        TrieNode* pnode = head;
        size = word.size();
        for(idx = 0;idx < size;idx++){
            if(!pnode->table[word[idx]])
                return false;
            pnode = pnode->table[word[idx]];
        }
        
        return pnode->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int idx, size;
        TrieNode* pnode = head;
        size = prefix.size();
        for(idx = 0;idx < size;idx++){
            if(!pnode->table[prefix[idx]])
                return false;
            pnode = pnode->table[prefix[idx]];
        }
        return true;
    }
    
    void deleteNode(TrieNode* pnode){
        int idx;
        if(!pnode) return;
        for(idx = 0;idx < 128;idx++){
            if(!pnode->table[idx]){
                deleteNode(pnode->table[idx]);
                delete pnode->table[idx];
            }
        }
    }
    
    ~Trie(){
        deleteNode(head);
        delete head;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */