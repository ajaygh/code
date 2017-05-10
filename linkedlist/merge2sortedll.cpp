//Merge two sorted (increasing order) linked list
//
#include <iostream>
using namespace std;

//node for single linked list
struct node{
	node(int _data): data(_data),next(NULL){}
	int data;
	node *next;
};

void display(node* root){
	while(root){
		cout <<root->data<<"  ";
		root = root->next;
	}
	cout<<endl;
}

//Sort using recursion
node* sortTwoSortedLL_Recur(node* root1, node* root2){
	if(root1 && root2){
		if(root1->data < root2->data){
			if(root1->next){
				root1->next = sortTwoSortedLL_Recur(root1->next, root2);
				return root1;
			}else{
				root1->next = root2;
				return root1;
			}
		}else{
			if(root2->next){
				root2->next = sortTwoSortedLL_Recur(root1, root2->next);
				return root2;
			}else{
				root2->next = root1;
				return root2;
			}
		}
	}else if(root1){
		return root1;	
	}else if(root2){
		return root2;	
	}else{
		cout << "Both linkedlist are empty.Nothing to sort.\n";
		return NULL;
	}
}

//sort two sorted linked list in linear manner
node* sortTwoSortedLL_Linear(node* root1, node* root2){
	if(root1 && root2){
		node *curr1 = root1;
	    node *curr2 = root2;
		node *res = NULL;
	    node *tmp = NULL;

		if(curr1->data < curr2->data){
			res = curr1;
			curr1 = curr1->next;
		}else{
			res = curr2;
			curr2 = curr2->next;
		}

		tmp = res;
		while(curr1 && curr2){
			if(curr1->data < curr2->data){
				tmp->next = curr1;
				tmp = curr1;
				curr1 = curr1->next;
			}else{
				tmp->next = curr2;
				tmp = curr2;
				curr2 = curr2->next;
			}
			
			if(!curr1){
				while(curr2){
					tmp->next = curr2;
					tmp = curr2;
					curr2 = curr2->next;
				}
			}
			if(!curr2){
				while(curr1){
					tmp->next = curr1;
					tmp = curr1;
					curr1 = curr1->next;
				}
			}
		}
		return res;	
	}else if(root1){
		return root1;	
	}else if(root2){
		return root2;	
	}else{
		cout << "Both linkedlist are empty.Nothing to sort.\n";
		return NULL;
	}
}
/*
//Reverse sort two sorted linked list
node* sortTwoSortedLL(node* root1, node* root2, node *curr){
	if(!root1 && !root2)
		return NULL;
	else if(!root1)
		return root2;
	else if(!root2)
		return root1;
	else{
		if(!root1->next && !root2->next){
			if(root1->data > root2->data)
				head=root2;
				head->next=root1;
			else
				head=root1;
				head->next=root2;
		}else if(!root1->next){
			sortTwoSortedLL(root1, root2->next);
		}else if(!root2->next){
			sortTwoSortedLL(root1-next, root2);
		}else{
			sortTwoSortedLL(root1->next, root2->next);

		}
	}
}
*/
//Driver program
int main() {
	node* root1 = new node(2);	
	node* l11 = new node(4);	
	node* l12 = new node(10);	
	root1->next  = l11;
	l11->next = l12;

	node* root2 = new node(1);	
	node* l21 = new node(3);	
	node* l22 = new node(5);	
	node* l23 = new node(7);	
	node* l24 = new node(9);	
	node* l25 = new node(12);	
	node* l26 = new node(14);	
	root2->next  = l21;
	l21->next = l22;
	l22->next = l23;
	l23->next = l24;
	l24->next = l25;
	l25->next = l26;

	cout <<"first linked list is \n";
	display(root1);
	cout <<"second linked list is \n";
	display(root2);
//	node * res = sortTwoSortedLL_Linear(root1, root2);
	node * res = sortTwoSortedLL_Recur(root1, root2);
	cout <<"sorted ll using recursion is\n";
	display(res);
	node * res1 = sortTwoSortedLL_Linear(NULL, root2);
	cout <<"sorted ll is \n";
	display(res1);
	cout <<"second linked list is \n";
	display(root2);
	node * res2 = sortTwoSortedLL_Linear(root1, NULL);
	cout <<"sorted ll is \n";
	display(res2);
	cout <<"first linked list is \n";
	display(root1);
	node * res3 = sortTwoSortedLL_Linear(NULL, NULL);
	display(res3);
	return 0;
} 
