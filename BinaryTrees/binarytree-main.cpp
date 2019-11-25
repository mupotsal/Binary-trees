
/* Binary Tree guessing game
FIXME: Expand this with names and purpose!
NAMES: ANTHONY W WAFULA &LIBERTY MUPOTSA
CLASS: CSC 236
REQUIREMENTS: Ask the user to gues animals acording to the value in the text file 
answers picked are yes or false as they try to figure out the animal in there mind
*/

#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <sys/stat.h>
#include <windows.h>


class Node {
private:
	string answer;
	Node *noData;
	Node* yesData;

public:
	Node(string quest) {
		answer = quest;
		noData = NULL;
		yesData = NULL;
	}
	void setQuestion(string newQuestion)	{
		answer = newQuestion;

	}
	string getQuestion()	{
		return answer;

	}
	void setNoData(Node *node)
	{
		noData= node;
	}
	Node *getNoData()
	{
		return noData;
	}
	void setYesData(Node *node)
	{
		yesData= node;
	}
	Node *getYesNode()
	{
		return yesData;
	}


	 bool isQuestion()	{ // is leaf
		 if (noData == NULL && yesData == NULL) {
			 return false;
		 }
		 else {
			 return true;
		 }
	}

	 void traverse() { // query
		 if (this->isQuestion()) {
			 cout << this->answer;
			 string answer;
			 cout << "Enter yes or no" << endl;
			 cin >> answer;
			 if (answer == "yes") {
				 yesData->traverse();
			 }
			 else {
				 noData->traverse();
			 }
			 			 					  
		 }

		 else {
			 this->onTraverseObject();
		 }
	 }


	 void onTraverseObject() {
		 cout << "I guess you are thinking of" << this->answer << "?" << endl;
		 string answer;
		 cout << "enter yes or no" << endl;
		 if (answer == "yes") {
			 cout << "The Computer Wins" << endl;
		 }
		 else {
			 updateTree();
		 }
	 }

	 void updateTree() {
		 cout << "You won, what animal were you thinking of ?";
		 string useranimal;
		 string userqsn;
		 cout << "Write a question to distinguish " << useranimal << " to " << this->answer << endl;
		 cin >> userqsn;
		 cout << "What would be the answer if you were thinking  of " << useranimal << endl;
		 string answer;
		 cin >>answer;
		 if (answer == "yes") {
			 this->noData = new Node(this->answer);
			 this->yesData = new Node(useranimal);
		 }
		 else {
			 this->yesData = new Node(this->answer);
			 this->noData = new Node(useranimal);
		 }


	 }

	
	 
};






class BTTree {
private:
	Node* rootNode;
public:
	BTTree(string question, string yes_guess, string no_guess) {
		rootNode = new Node(question);
		rootNode->setYesData(new Node(yes_guess));
		rootNode->setNoData(new Node(no_guess));
	}

	void query() {
		rootNode->traverse();
	}

	void readfile(string fileName) {
		string line;
		ifstream readFile(fileName);
		int lineCount = 0;
		if (!readFile.is_open()) {// Checking for errors opening the file
			cout << ("Error opening file.");
			return;
		}
		while (getline(readFile, line)) {// Reading file until the end is reached or an error occurs
			Node tree();
			for (unsigned int i = 0; i < line.length(); ++i) {
				// thisLine.push_back(line[i]);
				if (line[i] == 'Q') {
					//this->
					cout << "What is this" << endl;

				}
			}

		}
		if (readFile.bad()) { // More error checking
			cout << ("Error reading file.");
			return;
		}
		readFile.close();

		return;
	}
};


void newGame() {

	string question;
	string yesGuess;
	string noGuess;
	cout << "what is the queston" << endl;
	cin >> question;
	cout << "what is the answer" << endl;
	cin >> yesGuess;
	cout << "what is the no answer" << endl;
	cin >> noGuess;
	BTTree tree(question, yesGuess, noGuess);
	


}

























/*class BinaryTree{
private:
	string guess;
	BinaryTree* leftChild;
	BinaryTree* rightChild;
public:
	BinaryTree(string rootObj) {
		this->guess = rootObj;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}

	void insertLeft(string  newNode) {
		if (this->leftChild == NULL) {
			this->leftChild = new BinaryTree(newNode);
		}
		else {
			BinaryTree* t = new BinaryTree(newNode);
			t->leftChild = this->leftChild;
			this->leftChild = t;
		}
	}

	void insertRight(string newNode) {
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

	void setRootVal(string obj) {
		this->guess = obj;
	}

	string getRootVal() {
		return this->guess;
	}

	void replace(string qsn, string = "yes", string = "no") {

	}

};
*/


void parse(Node*& root, fstream& file) {
	string str;
	if (!file.eof()) {
		getline(file, str);
		cin.clear();
	}
}




int play_game() {
	string line;
	ifstream myfile("animalguessing.txt");
	if (myfile.is_open())

	{
		int i = 0;
		while(getline(myfile, line))		{
			
			if (line[i] == '#') {

				cout << line << endl;
				
				string sln;
				cin >> sln;
				if (sln == "yes") {
					cout << "Is the animal" << "dog"<< endl;
					
				}
				
				else{
					string newsln;
					cout << "what is the animal" << endl;
					cin >> newsln;
				}
			}
			//cout << line << '\n';
			
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	return 0;
}



int main() {
	fstream file;
	file.open("animalguessing.txt");
	cout << "You are going to play the animal guessing game" << endl;
	play_game();


	
	

	return 0;
}