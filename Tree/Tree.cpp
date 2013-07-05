#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;
//Create Template Class Structure For BSTNode 
class TNode{
	public:
	int data,flag;
	TNode  *left,*right;
	TNode(){
		data=NULL;
		flag=0;	
		left=NULL;
		right=NULL;
	}
};
//Create Template Class Structure For Node 
class node{
	public:
	TNode *data;
	node  *next,*prev;
	node(){
		data=NULL;
		next=NULL;
		prev=NULL;
	}
};
//Create Template Class Structure For Chaining Node 
class list{
	node *front,*rear;
	int s;
	public:
	
	list(){
		front=NULL;
		rear=NULL;
		s=0;
	}   
	//Add Node At Last Postion In LinkList (Queue & Stack)
	void push(TNode *d){
		node* n=new node();
		n->data=d;
		n->prev=rear;		
		n->next=NULL;		
		if(front!=NULL){
			rear->next=n;
			rear=n;			
		}else{
			rear=front=n;		
		}		
		s++;
	}
	//Return Size Of A LinkList
	int Getsize(){
		return s;
	} 
	//Pop in stack Or Delete Node At Last position
	void pop(TNode **d){
			if (s!=0){
				node *temp=rear;
				rear=rear->prev;
				if(s==1){
					rear=front=NULL;
				}else{					
					rear->next=NULL;
				}
				*d=temp->data;
				delete(temp);
				s--;
				return;				
			}else{
				*d=NULL;return;	
			}			
	}
	//Delete And Return Value Of Node At First Position In LinkList(Queue)
	void pop_q(TNode **d){
		if(s!=0){
			node* temp=front;
			if(front==rear){
				front=NULL;
				rear=NULL;
			}else{
				front=front->next;
				front->prev=NULL;
			}
			*d=temp->data;
			delete(temp);
			s--;
			return;
		}else{
			*d=NULL;return;	
		}
	}	
};

//Create Template Class Structure For BST 
class Tree{
	TNode *root;
	list *qu;
	int s;
	public:
	
	Tree(){
		root=NULL;
		qu=new list();
	}
	
	void Create_Tree(int D_root,int f_left,int D_left,int f_right,int D_right){
	        TNode *T_root;
	        if(D_root!=-1){
	                root=new TNode();
		        root->data=D_root;
		        T_root=root;
		}else{
		        qu->pop_q(&T_root);     
		}
		if(f_left!=0){
			TNode *temp=new TNode();
			temp->data=D_left;
			T_root->left=temp;
			qu->push(T_root->left);				
		}
		if(f_right!=0){
			TNode *temp=new TNode();
			temp->data=D_right;
			T_root->right=temp;
			qu->push(T_root->right);								
		}		
	}
	
	void Level_wise(){  /*  root-child-child */
		list *Lq=new list();//queue
		TNode *temp=NULL;
		int i=1,j=0;
		Lq->push(root);	
		while(Lq->Getsize()!=0){
			Lq->pop_q(&temp);
			i--;
			cout<<temp->data<<"|";
			if(temp->left!=NULL){
				Lq->push(temp->left);								
				j++;
			}
			if(temp->right!=NULL){
				Lq->push(temp->right);								
				j++;
			}
			if(i==0){
				cout<<"\n";
				i=j;j=0;
			}
		}	
	}
	
	void In_order(){  /* left-root-right  */
		list *Iq=new list();//stack
		TNode *temp=root;
		while(temp!=NULL||Iq->Getsize()!=0){
			if(temp!=NULL){
				Iq->push(temp);	
				temp=temp->left;	
			}else{
				Iq->pop(&temp);
				cout<<temp->data<<"|";
				temp=temp->right;
			}
		}
	}

	void Pre_order(){ /* root-left-right  */
		list *Pq=new list();//stack
		TNode *temp=root;
		Pq->push(temp);
		while(Pq->Getsize()!=0){
			Pq->pop(&temp);
			cout<<temp->data<<"|";
			if(temp->right){
				Pq->push(temp->right);
			}
			if(temp->left){
				Pq->push(temp->left);
			}
		}
	}	
};

int main(int argc, char* argv[]){
	Tree *t=new Tree();
	vector <int> a; 
	int str,i,siz; 
	ifstream fin(argv[1]);
	 
	 while (fin >> str) 
	 {                  
		a.push_back(str);
	 }
	 fin.close();
	 siz=a.size();  
	 t->Create_Tree(a[0],a[1],a[2],a[3],a[4]);
	 for(i=5;i<siz;i=i+4){
	        t->Create_Tree(-1,a[i],a[i+1],a[i+2],a[i+3]);
	 }
	 
	cout<<"Level-Wise Tree"<<"\n";
	t->Level_wise();
	cout<<"\n\nIn-Order Tree"<<"\n";
	t->In_order();
	cout<<"\n\nPre-Order Tree"<<"\n";
	t->Pre_order();
	cout<<"\n\n";
	return 0;
}




