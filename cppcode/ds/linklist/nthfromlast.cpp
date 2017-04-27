#include <iostream>

using namespace std;

struct node {
	node(int val): val{val}, next{nullptr}{}
	int val;
	node *next;
};

void appendList(node* &head, int val){
	node *tmp = head;
	if(tmp){
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new node(val);
	}else{
		head = new node(val);
	}
}

void display(node *head){
	while(head){
		cout << head->val << ' ';
		head = head->next;
	}
	cout <<endl;
}

int findKthFromLast(node *head, int k){
	node *curr = head, *prev = head;
	for(int i = 0; i < k-1;i++){
		if(curr->next)
			curr = curr->next;
		else
			return -1;
	}
	while(curr->next){
		curr = curr->next;
		prev = prev->next;
	}
	return prev->val;
}


int main() {
	int n;
	cin >> n;
	node *head;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		appendList(head, tmp);
	}
	int k;
	cin >> k;
	cout << findKthFromLast(head,k)<< endl;
	//display(head);
	return 0;
} 
