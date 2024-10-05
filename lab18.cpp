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
bool getReview(Node *&, int); //Gets a review, returns true if the user wants to enter another review
void dispList(Node *); //displays all reviews
float calcAvg(Node *); //calculates the average rating of a list

int main(){
	Node * head = nullptr;
	int mode;

	cout << "Which linked list method should we use?\n"
	     << "\t[1] New nodes are added at the head of the linked list\n"
		 << "\t[2] New nodes are added at the tail of the linked list\n"
		 << "Choice: ";
	cin >> mode;

	while (getReview(head, mode));

	cout << "Outputting all reviews:\n";
	dispList(head);

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
	//get the review
	Review temp;
	cout << "Enter review rating 0-5: ";
	cin >> temp.rating;
	cin.ignore();
	cout << "Enter review comments: ";
	getline(cin, temp.comment);
	//add the review to the list
	if (mode==1)
		addToHead(hd, temp);
	else
		addToTail(hd, temp);
	//new review or not
	char inp;
	cout << "Enter another review? y/n: ";
	cin >> inp;
	if (inp=='y')
		return true;
	else
		return false;
}

void dispList(Node * hd) {
	Node * current = hd;
	int count = 1;
	while (current) {
		cout << "\t[" << count++ << "] " << current->value.rating << ": "
			 << current->value.comment << endl;
		current = current->next;
	}
}

float calcAvg(Node * hd) {
	Node * current = hd;
	int count = 0;
	float sum = 0;
	while (current) {
		count++;
		sum = sum + current->value.rating;
		current = current->next;
	}
	return sum / count;
}
