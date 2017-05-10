#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

struct node {
	node (int data):val{data},next{nullptr}{}
	~node(){}
	int val;
	node *next;

};

int lenght(node *head){
	int len = 0;
	while(head){
		len++;
		head = head->next;
	}
	return len;
}

node* addsamelen(node * a, node *b, int &c){
	node *next = nullptr;
	if(a->next){
		next = addsamelen(a->next, b->next, c);
	}
	int sum = (a->val+b->val+c)%10;
	c = (a->val+b->val+c)/10;
	node *curr = new node(sum);
	if (next) curr->next = next;
	return curr;
}

void display(node *head){
	while(head){
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

node* forward(node *head, int diff){
	while(diff > 0){
		head = head->next;
		diff--;
	}
}

node* addonelist(node *head, node* last, int &c, int diff){
	int val;
	node *tmp=nullptr;
	if(diff == 1){
		int val = (head->val+c)%10;
		c = (head->val+c)/10;
		tmp = new node(val);
		tmp->next = last;
	}
	else{
		node *next = addonelist(head->next, last, c, diff-1);
		val = (head->val+c)%10;
		c = (head->val+c)/10;
		tmp = new node(val);
		tmp->next = next;
	}
	return tmp;	
}

int main() {
	
	node *heada = new node(9);
	node *h1 = new node(9);
	node *h2 = new node(2);
	node *h3 = new node(6);
	node *h4 = new node(2);
	node *headb = new node(7);
	node *h21 = new node(8);
	node *h22= new node(9);

	//node *heada = new node(4);
	//node *heada = new node(4);
	//node *heada = new node(4);
	//node *heada = new node(4);
	//node *heada = new node(4);
	heada->next = h1;
	h1->next = h2;
	h2->next = h3;
	h3->next = h4;

	headb->next =h21;
	h21->next = h22;
	
	int lena = lenght(heada);
	int lenb = lenght(headb);

	int c = 0;
	node *head = nullptr, *th = nullptr;

	if(lena < lenb){
		int diff = lenb-lena;
		//move to diff pointer ahead in headb
		node * thb = forward(headb, diff);
		th = addsamelen(heada, thb, c);
		th = addonelist(headb, th, c, diff);
	}else if(lena == lenb){
		th = addsamelen(heada, headb, c);
	}else{
		int diff = lena-lenb;
		//move to diff pointer ahead in headb
		node * tha = forward(heada, diff);
		th = addsamelen(tha, headb, c);
		th = addonelist(heada, th, c, diff);
	}
	if(c){
		head = new node(c);
		head->next = th;
	}else{
		head = th;
	}
	cout << "first list is \n";
	display(heada);

	cout << "Second list is \n";
	display(headb);

	cout << "Added list is \n";
	display(head);
	return 0;
} 
