#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    struct TrieNode *children[26];
    bool endOfWord;
};

struct TrieNode *getNode(){
    struct TrieNode *tmp = new TrieNode;
    tmp->endOfWord = false;
    for (int i = 0; i < 26; i++)
        tmp->children[i] = NULL;
    return tmp;                    
}

void insert(struct TrieNode *root, string word)
{
    struct TrieNode *tmp = root;
     for (int i = 0; i < word.length(); i++)
     {
        int index = word[i]-'a';
        if(!tmp->children[index])
            tmp->children[index] = getNode();
        tmp = tmp->children[index];            
     }
     tmp->endOfWord = true;
};
bool search(struct TrieNode *root,string word)
{
   struct TrieNode *tmp=root;
   for(int i=0; i<word.length();i++)
   {
       int index=word[i]-'a';
       if(!tmp->children[index])
          return false;
        tmp=tmp->children[index] ; 
   }
   return (tmp != NULL && tmp->endOfWord);
}
