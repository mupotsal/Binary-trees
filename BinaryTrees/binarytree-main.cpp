
/* Binary Tree guessing game
FIXME: Expand this with names and purpose!
NAMES: ANTHONY W WAFULA &LIBERTY MUPOTSA
CLASS: CSC 236
REQUIREMENTS: Ask the user to gues animals acording to the value in the text file 
          answers picked are yes or false as they try to figure out the animal in there mind
*/

#include <iostream>
using namespace std;

class BinaryTree{
private:
	char key;
	BinaryTree* leftChild;
	BinaryTree* rightChild;
public:
	BinaryTree(char rootObj) {
		this->key = rootObj;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}

	void insertLeft(char newNode) {
		if (this->leftChild == NULL) {
			this->leftChild = new BinaryTree(newNode);
		}
		else {
			BinaryTree* t = new BinaryTree(newNode);
			t->leftChild = this->leftChild;
			this->leftChild = t;
		}
	}

	void insertRight(char newNode) {
		if (this->rightChild == NULL) {
			this->rightChild = new BinaryTree(newNode);
		}
		else {
			BinaryTree* t = new BinaryTree(newNode);
			t->rightChild = this->rightChild;
			this->rightChild = t;
		}
	}

	BinaryTree* getRightChild() {
		return this->rightChild;
	}

	BinaryTree* getLeftChild() {
		return this->leftChild;
	}

	void setRootVal(char obj) {
		this->key = obj;
	}

	char getRootVal() {
		return this->key;
	}


	   	 
};








int main() {

	char readchar;

	//FIXME: Code needed here

	// we need to find out what we are reading from the files



	cin >> readchar; //This is to keep screen open in some situations.
	return 0;
}