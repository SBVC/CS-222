#pragma once

class TST {
private:
	struct node {
		char data;
		unsigned isEndOfString : 1;
		node *left, *eq, *right;
	};

	node* root;

	node* newNode(char data);
	void insertWordPrivate(node** root, char *word);
	int searchTSTPrivate(node *root, char *word);
	void RemoveSubtree(node* Ptr);

public:
	TST();
	~TST();
	void insertWord(char *word);
	void traverseTSTUtil(node* root, char* buffer, int depth);
	void traverseTST();
	int searchTST(char *word);

};