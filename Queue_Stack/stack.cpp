#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Create Template Class Structure For Node 
template <class T1>
class node{
	public:
	T1 data;
	node<T1>*  next;
	node(){
		data=NULL;
		next=NULL;
	}
};

//Create Template Class Structure For Chaining Node 
template <class T1>
class list{
	node<T1>* head;
	int s;
	public:
	
	list(){
		head=new node<T1>();
		s=0;
	}

	//Add Node At Last Postion In LinkList 
	void Push(T1 d){
		node<T1>* n=new node<T1>();
		n->data=d;
		n->next=head->next;
		head->next=n;
		s++;
	}

	//Display All Element Of The LinkList
	void display(){
		node<T1>* cur=head->next;
		while(cur!=NULL){
			std::cout<<" | "<<cur->data<<" | ";	
			cur=cur->next;
		}
	}
	
	//Srearch for perticuler position of given key
	bool find(T1 key){
		node<T1>* cur=head->next;
		int p=1;
		while(cur!=NULL){
			if(cur->data==key){
				return p;
			}
			p++;
			cur=cur->next;
		}
		return 0;
	}
	
	//Return kth Element 
	T1 display(int p){
		node<T1>* cur=head->next;
		for(int i=0;i<p-1;i++){
			cur=cur->next;
		}
		return cur->data;
	}
	
	//Return Size Of A LinkList
	int Getsize(){
		return s;
	} 

	//Delete And Return Value Of Node At First Position In LinkList
	T1 Pop(){
		node<T1>* temp=head->next;
		head->next=temp->next;
		T1 d=temp->data;
		delete(temp);
		s--;
		return d;
	}	
};
int main(){
	string str;
	std::cout<<"Enter the Prefix Expression:\n";
	std::cin>>str;
	int len=str.length();
	int d,a,b;
	list<int> *l=new list<int>(); 
	list<char> *op=new list<char>(); 
	list<int> *val=new list<int>(); 
	for(int i=len-1;i>=0;i--){
		switch(str[i]){
			case '*':
				a=l->Pop();
				b=l->Pop();
				d=a*b;
				l->Push(d);
				break;
			case '/':
				a=l->Pop();
				b=l->Pop();
				d=a/b;
				l->Push(d);
				break;
			case '+':
				a=l->Pop();
				b=l->Pop();
				d=a+b;
				l->Push(d);
				break;
			case '-':
				a=l->Pop();
				b=l->Pop();
				d=a-b;
				l->Push(d);
				break;
			case '%':
				a=l->Pop();
				b=l->Pop();
				d=a%b;
				l->Push(d);
				break;
			case '^':
				a=l->Pop();
				b=l->Pop();
				d=pow(a,b);
				l->Push(d);
				break;
			case '!':
				a=l->Pop();
				d=-a;
				l->Push(d);
				break;
			case 'a' ... 'z':
				int p=op->find(str[i]);
				if(p!=0){
					d=val->display(p);
				}else{
					std::cout<<"Enter the Value For "<<str[i]<<":";
					std::cin>>d;
					op->Push(str[i]);
					val->Push(d);
				}
				l->Push(d);	
				break;
			Default:
				std::cout<<"End:\n";
				break;		
		}
	}
	std::cout<<"Equation: \""<<str<<"\" Result= ";
	l->display();
	std::cout<<"\n";
	return 0;
}

