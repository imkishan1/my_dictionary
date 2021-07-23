#include "TrieNode.h"

class Trie{
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode('\0');
	}

private:
	void insertWord(TrieNode* root, string word){
		if(word.size() == 0){
			root -> isTerminal = true;
			return;
		}
		TrieNode* child;
		if(root->children[(word[0]-'a')] != NULL){
			child = root->children[(word[0]-'a')];
		}else{
			child = new TrieNode(word[0]);
			root->children[(word[0]-'a')] = child;
		}
		insertWord(child, word.substr(1));
	}
public:
	void insert(string word){
		return insertWord(root, word);
	}


private:
	bool searchWord(TrieNode* root, string word){
		if(word.size() == 0){
			return root->isTerminal;
		}
		if(root->children[(word[0]-'a')] == NULL){
			return false;
		}
		return searchWord(root->children[(word[0]-'a')], word.substr(1));
	}
public:
	bool search(string word){
		return searchWord(root, word);
	}

private:
	void removeWord(TrieNode* root, string word){
		if(word.size() == 0){
			root->isTerminal = false;		
			return;
		}

		if(root->children[(word[0]-'a')] == NULL){
			return;
		}

		removeWord(root->children[(word[0]-'a')], word.substr(1));
		
		TrieNode* child = root->children[(word[0]-'a')];
		if(child->isTerminal == false){
		for(int i=0; i<26; i++){
		    if(child->children[i] != NULL){
		      return;
		    }
		}
			delete child;
			root->children[(word[0]-'a')] = NULL;
		}
	}
public:
	void remove(string word){
		removeWord(root, word);
	}
};