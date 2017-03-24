#include <iostream>
#include <unordered_set>

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
	unordered_set<node*> snode;
	while(head && (snode.find(head) == snode.end())){
		snode.insert(head);
		head = head->next;
	}
	if(head)
		return head->data;
	else 
		return -1;
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
	printll(head);	
	cout << findCycleStart(head);
	return 0;
} 
