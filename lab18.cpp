/***********************************************

  COMSC 210 | Lab 18 | Skylar Robinson | IDE Used: Eclipse

***********************************************/

#include <iostream>
#include <string>
using namespace std;

struct Review {
	float rating;
	string comment;
};

struct Node {
	Review value;
	Node * next;
};

void addToHead(Node *&, Review); //Add a node to the head of a list
void addToTail(Node *&, Review); //Add a node to the end of a list
bool getReview(Node*&, int); //Gets a review, returns true if the user wants to enter another review

int main(){



	return 0;
}

void addToHead(Node *&hd, Review v) {
	Node *newVal = new Node;
	newVal->value = v;
		if (!hd) { // if this is the first node, it's the new head
		    newVal->next = nullptr;
		}
		else { // its a second or subsequent node; place at the head
		    newVal->next = hd;
		}
	hd = newVal;
}

void addToTail(Node *&hd, Review v) {
	Node *newVal = new Node;
	newVal->next = nullptr;
	newVal->value = v;
		if (!hd) { // if this is the first node, it's the new head
			hd = newVal;
		}
		else { // its a second or subsequent node; place at the end
			//traverse to the end of the list
			Node * current = hd;
			while(current->next)
				current = current->next;
			//point last node to new node
			current->next = newVal;
		}
}

bool getReview(Node *&hd, int mode) {
	Review temp;
	cout


}
