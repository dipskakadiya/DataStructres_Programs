#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include<algorithm>
#include<ctime>
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
	TNode(int d){
		data=d;
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
	TNode *root,*T_Root;
	list *st;
	int s;
	public:
	
	Tree(){
		root=NULL;
		st=new list();
		T_Root=new TNode();
	}
	
	void Create_Tree(vector <int> a){
	        TNode *T_root;
                root=new TNode();
 		root->data=a[0];
		for(int i=1;i<a.size();i++){
			T_root=root;
			while(T_root!=NULL){
				if(T_root->data>a[i]){
					if(T_root->left==NULL){
						TNode *temp=new TNode();
						temp->data=a[i];
						T_root->left=temp;
						break;					
					}	
					T_root=T_root->left;						
				}else{
					if(T_root->right==NULL){
						TNode *temp=new TNode();
						temp->data=a[i];
						T_root->right=temp;
						break;					
					}	
					T_root=T_root->right;
				}
			}
		}
	       
				
	}

	void inorder_successor(){
		TNode *temp1=NULL,*temp2=NULL;
		temp2=root->right;
		if(temp2!=NULL){
		        while(temp2->left!=NULL){
			        temp1=temp2;			
			        temp2=temp2->left;
		        }
		        if(temp1!=NULL){
		                temp1->left=temp2->right;
		                 temp2->right=root->right;
		        }
		        temp2->left=root->left;
		        T_Root->data=root->data;
		        st->push(T_Root);
		        st->push(temp1);
		        st->push(temp2);
		        delete(root);
		        root=temp2;
		        In_order();
		        cout<<"\n";
		        Rollback();
		}else{
		        cout<<"Error: inorder_successor is not possiable \n";
		}
	}
	
	void Rollback(){
	      TNode *t1,*t2,*tr;
	       st->pop(&t2); 	 
	       st->pop(&t1);
	       st->pop(&tr);
	       tr->left=t2->left;
	       tr->right=t2->right;
	       t2->left=NULL;
	       if(t1!=NULL){
	                t2->right=t1->left;
	                t1->left=t2;
	       }else{
	                t2->right=t2;
	       } 
	       root=tr; 
	}

	void inorder_predecessor(){
		TNode *temp1=NULL,*temp2=NULL;
		temp2=root->left;
		if(temp2!=NULL){
		        while(temp2->right!=NULL){
			        temp1=temp2;			
			        temp2=temp2->right;
		        }
		        if(temp1!=NULL){
		                 temp1->right=temp2->left;
		                  temp2->left=root->left;
		        }
		        temp2->right=root->right;
		        delete(root);
		        root=temp2;
		        In_order();
		        cout<<"\n";
		}else{
		        cout<<"Error: inorder_predecessor is not possiable\n";
		}
	}

        void In_order(){  /* left-root-right  */
		list *Iq=new list();//stack
		TNode *temp=root;
		cout<<"Root Is : "<<temp->data<<"\n";
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
	 srand(unsigned (time(0)));
	 random_shuffle ( a.begin(), a.end());
	 for(int i=0;i<a.size();i++){
	        cout<<a[i]<<"|";
	 }
	 t->Create_Tree(a);
	 cout<<"\nAfter Created Tree: \n";
	 t->In_order();
	 
	 cout<<"\n\nAfter inorder Successor: \n";
	 t->inorder_successor();
	 
	 cout<<"\nAfter inorder Predecessor: \n";
	 t->inorder_predecessor();
	 
	 cout<<"\n";
	return 0;
}




