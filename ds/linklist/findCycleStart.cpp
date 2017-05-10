#include <iostream>

using namespace std;

struct node{
	node(int _data):data{_data},next{NULL}{}
	int data;
	node *next;
};

void printll(node *head){
	while(head){
		cout << head->data << ' ';
		head = head->next;
	}
	cout <<endl;
}

int findCycleStart(node *head){
	node *slow = head->next, *fast = head->next->next;
	//find the node where they first meet
	
	while(slow != fast){
		slow = slow->next;
		fast = fast->next->next;
	}
	//move one of them to head
	fast = head;
	//now the meeting point of fast and slow will the cycle start point
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}

int main() {
	node *head = new node(1);
	node *h1  = new node(2);	
	node *h2  = new node(3);	
	node *h3  = new node(4);	
	node *h4  = new node(5);	
	node *h5  = new node(6);
	head->next = h1;
	h1->next = h2;	
	h2->next = h3;	
	h3->next = h4;	
	h4->next = h5;
	h5->next = h3;
//	printll(head);	
	cout << findCycleStart(head) << endl;
	return 0;
} 
