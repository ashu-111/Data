#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    struct TrieNode *children[26];
    bool endOfWord;
};

struct Trie *getNode(){
    struct Trie *tmp = new Trie;
    tmp->endOfWord = false;
    for (int i = 0; i < 26; i++)
        tmp->children[i] = NULL;
    return tmp;                    
}

void insert(struct Trie *root, string word)
{
    struct Trie *tmp = root;
     for (int i = 0; i < word.length(); i++)
     {
        int index = key[i]-'a';
        if(!tmp->children[index])
            tmp->children[index] = getNode();
        tmp = tmp->children[index];            
     }
     tmp->endOfWord = true;
}
bool search(stuct Trie *root,string word)
{
   stuct Trie *tmp=root;
   for(int i=0; t<word.length;i++)
   {
       int index=key[i]-'a';
       if(!tmp->children[index])
          return False
        tmp=tmp->children[index] ; 
   }
   return (temp != NULL && temp->isEndOfWord);
}
