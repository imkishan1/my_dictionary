class TrieNode{
public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data){
		this->data = data;
		this->children = new TrieNode*[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		this->isTerminal = false;
	}
};