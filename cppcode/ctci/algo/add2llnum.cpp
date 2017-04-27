#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

struct node{
	node(int val): val(val), next(NULL){}
	int val;
	node *next;
};

void append(node * head, int val){
	node *tmp = head, *nd = new node(val);
	if(head){
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nd;
	}else
		head = nd;
}

void len(node *head){
	int len = 0;
	for(node *tmp = head; tmp != NULL; tmp = tmp->next)
		len++;
	return len;
}

node* add(node *h1, node *h2){
	int sum = 0, carry = 0;
	int l1 = len(h1), l2 = len(h2);
	int diff = l1-l2;
	if(diff < 0) diff = -diff;
	if(l1 >=  l2){
		for(int i = 0; i < diff; i++)
			h1 = h1->next;
		addnext(h1->next, h2->next, carry);
		sum = h1->val + h2->val + carry;
	}else{
		for(int i = 0; i < diff; i++)
			h2 = h2->next;
		addnext(h1->next, h2->next, carry);
		sum = h1->val + h2->val + carry;
	}

}

int main() {
	
	return 0;
} 
