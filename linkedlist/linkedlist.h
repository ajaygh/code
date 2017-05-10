#ifndef _LINKED_LIST_
#define _LINKED_LIST_

using namespace std;

struct node{
	node(int _data): data(_data),next(NULL){}

	int data;
	node *next;
};

struct linkelists{
	linkelists():head(NULL){}
	
	void display(){
		node *tmp = head;
		while(tmp){
			cout << tmp->data<<"\t";
			tmp = tmp->next;
		}
		cout <<endl;
	}

	void append(int data){
		if(head){
			node *tmp = head;
			while(tmp->next)
				tmp = tmp->next;
			tmp->next = new node(data);
		}else{
			head = new node(data);
		}
	}

	node* reverse(node *curr){
		if(curr){
			if(curr->next){
				(reverse(curr->next))->next = curr;
				curr->next = NULL;
			}else{
				head = curr;
				return curr;
			}
		}else{
			return NULL;
		}
	}

	node *head;
};

#endif
