#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()

using namespace std;

struct node{
	node(int _data):data{_data}{}
	int data;
	node *next{NULL};
};

node* insertback(node* &head, int data){
	if(head){
		node *tmp = head;
		while(tmp->next)
			tmp=tmp->next;
		node *tmp1 = new node(data);
		tmp->next = tmp1;
		
	}else{
		head=new node(data);
	}
	return head;
}

void modifyFront(node* &head, int i, int j){
	int ii=0,jj=0;
	node *tmp1=head,*tmp2;
	for(;ii<i-1;ii++){
		tmp1=tmp1->next;
	}
	tmp2=tmp1;
	int j2=j-ii;
	for(;jj<j2;jj++)
		tmp2 = tmp2->next;
	node *head1 = head;
	head=tmp1->next;
	tmp1->next=tmp2->next;
	tmp2->next=head1;
}

void modifyBack(node* &head, int i, int j, int size){
	int ii=0,jj=0;
	node *tmp1=head,*tmp2;
	for(;ii<i-1;ii++){
		tmp1=tmp1->next;
	}
	tmp2=tmp1;
	int j2=j-ii;
	for(;jj<j2;jj++)
		tmp2 = tmp2->next;
	node *back=tmp2;
	for(int ed = size-j-1,jj=0;jj<ed;jj++)
		back = back->next;
	
	if(i==0){
		back->next = head;
		head=tmp2->next;
	}else{
		back->next=tmp1->next;
		tmp1->next=tmp2->next;
	}
	tmp2->next=NULL;
}
void print(node *head){
	node *tmp=head;
	while(tmp){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}
int size(node *head){
	node *tmp=head;
	int res=0;
	while(tmp){
		res++;
		tmp = tmp->next;
	}
	return res;
}

int findBack(node *head){
	node *tmp=head;
	while(tmp->next){
		tmp = tmp->next;
	}
	return tmp->data;
}


int main() {
	int n,m,type,i,j,tmp;
	cin>>n>>m;
	node *head =NULL;
	for(int i11=0;i11<n;i11++){
		cin>>tmp;
		insertback(head,tmp);
	}
	//print(head);
	int len=size(head);
	for(int i1=0;i1<m;i1++){
		cin>>type>>i>>j;
		if(type == 1){
			if(i != 1) modifyFront(head,i-1,j-1);
			if(i1==m-1){
				int back = findBack(head);
				int res = head->data-back;
				if(res<0) res = -res;
				cout<<res<<endl;
			   	print(head);
			}
		}else{
			if(j!= len) modifyBack(head,i-1,j-1,len);
			if(i1==m-1){
				int back = findBack(head);
				int res = head->data-back;
				if(res<0) res = -res;
				cout<<res<<endl;
			   	print(head);
			}
		}
	}
	
	return 0;
}
