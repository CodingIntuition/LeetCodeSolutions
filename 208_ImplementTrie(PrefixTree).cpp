class Trie {
  struct TrieNode{
      char val;
      bool endsWith;
      TrieNode* childs[26];
  };
public:

    TrieNode* getNode(char ch ) {
        TrieNode* currNode = new TrieNode;
        for (int i = 0; i<26; i++ ){
            currNode->childs[i] = NULL;
        }
        currNode->val = ch;
        currNode->endsWith = false;

        return currNode;
    }
    TrieNode* root;

    Trie() {
        root = getNode('/');
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for (char &ch : word){
            if (currNode->childs[ch-'a']!=NULL){
                currNode = currNode->childs[ch-'a'];
            }
            else {
                currNode->childs[ch-'a'] = getNode(ch);
                currNode = currNode->childs[ch-'a'];
            }
        }
        currNode->endsWith = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for (char &ch : word){
            if (currNode->childs[ch-'a'] == NULL) return false;
            currNode = currNode->childs[ch-'a'];
        }
        return currNode->endsWith;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (char &ch : prefix){
            if (currNode->childs[ch-'a'] == NULL) return false;
            currNode = currNode->childs[ch-'a'];
        }
        return currNode?true:false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */