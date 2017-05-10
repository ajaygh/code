#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* Delete(Node *head, int position)
{
	if(head){
        if(position == 0){
			Node* tmp = head->next;
		    delete head;
		    return tmp;
		}else{
			int i = 0;
			Node *tmp = head;
			while(i < position-1)
			{
				tmp = tmp->next;
				i++;
			}
			Node *del = tmp->next;
			tmp->next = tmp->next->next;
			delete del;
			return head;
		}
	}
	return head;
};

Node* Insert(Node *head, int data){
	Node *tmp1 = new Node;
	tmp1->data = data;
	tmp1->next = NULL;
	if(head){
		Node *tmp = head;
		while(tmp->next)
			tmp=tmp->next;
		tmp->next = tmp1;
		return head;
	}else{
		return tmp1;	
	}
}

void Display(Node *head){
	Node *tmp = head;
	while(tmp){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout <<endl;
}

Node* Reverse(Node *head){
	static Node* rhead = NULL;
	static Node* chead = head;
	if(head){
		if(head->next){
			Reverse(head->next)->next = head;
		}else{
			rhead = head;
			return head;
		}
		if(head == chead){
			head->next = NULL;
			return rhead;
		}
	}

	return head;
}

Node* ReverseUtil(Node *head, Node* &rhead)
{
    if(head){
		if(head->next){
			ReverseUtil(head->next, rhead)->next = head;
		}else{
			rhead = head;
		} 
    } 
    return head;
}

Node* Reverse1(Node* head){
    Node* rhead = NULL;
    Node* tmp = ReverseUtil(head, rhead);
    if(tmp) tmp->next= NULL;
    return rhead;
}
int CompareLists(Node *headA, Node* headB)
{
	int res=0;
	if(headA && headB){
		Node* tmp1 = headA, *tmp2 = headB;
		while((tmp1 && tmp2)&&(tmp1->data == tmp2->data)){
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
		}
		if(!tmp1 && !tmp2) res=1;
	}else if(!headA && !headB)
		res = 1;
    return res;
}

Node* MergeLists(Node *headA, Node* headB)
{
	if(headA && headB){
		Node* tmp1 = headA, *tmp2 = headB;
		Node* mhead, *ntmp;
		if(tmp1->data <= tmp2->data){
			mhead = tmp1;
			tmp1 = tmp1->next;
		}else{
			mhead = tmp2;
			tmp2 = tmp2->next;
		}
		ntmp = mhead;
		while((tmp1 && tmp2)){
			if(tmp1->data <= tmp2->data){
				ntmp->next = tmp1;
				tmp1 = tmp1->next;
			}else{
				ntmp->next = tmp2;
				tmp2 = tmp2->next;
			}
		}
		if(tmp1) ntmp->next = tmp1;
		else if(tmp2) ntmp->next = tmp2;
		return mhead;
	}else if(headA && !headB) return headA;
	else if(!headA && headB) return headB;
	else if(!headA && !headB) return NULL;
	return NULL;
}

int GetNode(Node *head,int positionFromTail)
{
	int fp = 0,num= 0;
	Node *tmp = head;
	while(tmp){
		num++;
		tmp = tmp->next;
	}
	fp = num - 1 - positionFromTail;
	tmp = head;
	int p = 0;
	while(p != fp){
		p++;
		tmp = tmp->next;
	}
  return tmp->data;
}

void DisplayReverse(Node *head){
	Node *tmp = head;
	stack<int> sl;
	while(tmp){
		sl.push(tmp->data);
		tmp = tmp->next;
	}
	while(!sl.empty()){
		cout<<sl.top()<<endl;
		sl.pop();
	}
}

int main() {
	int t, num, data, pos;
	cin>>t;
	for(int i = 0;i<t;i++){
		cin >>num;
		Node *head = NULL;
		for(int j = 0;j<num;j++){
			cin>>data;
			head = Insert(head, data);
		}
		//cin>>pos;
		//head = Delete(head, pos);
		Display(head);
		//DisplayReverse(head);
		head = Reverse1(head);
		Display(head);
		cout<<GetNode(head, 3)<<endl;
	}
	return 0;
}
