#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

//Create Template Class Structure For Node 
template <class T1>
class node{
	public:
	T1 data;
	node<T1>  *next,*prev;
	node(){
		data=NULL;
		next=NULL;
		prev=NULL;
	}
};

//Create Template Class Structure For Chaining Node 
template <class T1>
class list{
	node<T1> *front,*rear;
	int s;
	public:
	
	list(){
		front=NULL;
		rear=NULL;
		s=0;
	}   
	//Add Node At Last Postion In LinkList 
	void Add_node(T1 d){
		node<T1>* n=new node<T1>();
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

	//Display All Element Of The LinkList
	void display(){
		node<T1>* cur=front;
		while(cur!=NULL){
			std::cout<<cur->data<<"|";	
			cur=cur->next;
		}
	}

	void display_return(){
		node<T1>* cur=rear;
		while(cur!=NULL){
			std::cout<<cur->data<<"|";	
			cur=cur->prev;
		}
	}
	
	//Return Size Of A LinkList
	int Getsize(){
		return s;
	} 

	//Delete And Return Value Of Node At First Position In LinkList
	T1 Del_node(){
		if(s!=0){
			node<T1>* temp=front;
				//front=front->next;
			if(front==rear){
				front=NULL;
				rear=NULL;
			}else{
				front=front->next;
				front->prev=NULL;
			}
			T1 d=temp->data;
			delete(temp);
			s--;
			return d;
		}
	}	
};
int main(){
	int c,d;
	list<int> *queue=new list<int>();
	do{	
		std::cout<<"Enter 1 For Add Node: \n";
		std::cout<<"Enter 2 For Delete Node: \n";
		std::cout<<"Enter 3 For Display Node: \n";
		std::cout<<"Enter 4 For Display reverse Node: \n";
		std::cout<<"Enter 0 For Exit: \n";
		std::cout<<"Enter your Choice: \n";
		std::cin>>c;
		switch(c){
			case 1:
				std::cout<<"Enter data \n";
				std::cin>>d;
				queue->Add_node(d);
				break;
			case 2:
				std::cout<<queue->Del_node()<<"\n";
				break;
			case 3:
				queue->display();
				std::cout<<"\n";
				break;
			case 4:
				queue->display_return();
				std::cout<<"\n";
		}
	}while(c!=0);
	
}

