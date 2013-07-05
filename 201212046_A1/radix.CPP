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
	void Add_last(T1 d){
		node<T1>* cur=head;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		node<T1>* n=new node<T1>();
		n->data=d;
		cur->next=n;
		s++;
	}

	//Display All Element Of The LinkList
	void display(){
		node<T1>* cur=head->next;
		while(cur!=NULL){
			std::cout<<cur->data<<"|";	
			cur=cur->next;
		}
	}
	
	//Return Size Of A LinkList
	int Getsize(){
		return s;
	} 

	//Delete And Return Value Of Node At First Position In LinkList
	T1 Del_node(){
		node<T1>* temp=head->next;
		head->next=temp->next;
		T1 d=temp->data;
		delete(temp);
		s--;
		return d;
	}	
};

void RadixSort(list<int>* a,int f){

	//Create Array Of LinkList
	list<int>* list1[10];
	for(int i=0;i<10;i++)
		list1[i]=new list<int>();

	int r,t,s=a->Getsize();//S->Size and r,t->Temp variable  		
	for(int i=0;i<3;i++){		

		//Radix Sort		
		for(int j=0;j<s;j++){			
			r=t=a->Del_node();
			for(int k=0;k<i;k++)
				r=int (floor(r/10));
		 	r=abs(int (floor(r%10)));//Take Digit From Input 
			list1[r]->Add_last(t);//Add Into The LinkList
		}
		
		//Conver Maltiple LinkLists Into One LinkList 
		if (f==0){
			for(int j=9;j>=0;j--)
				while(list1[j]->Getsize()!=0)				
					a->Add_last(list1[j]->Del_node());
		}else{		
			for(int j=0;j<10;j++)
				while(list1[j]->Getsize()!=0)				
					a->Add_last(list1[j]->Del_node());
							
		}	
		//Display Sorted LinkList		
		std::cout<<"Sorted List Accoding to Digit :"<<i<<"\n";
		a->display();
		std::cout<<"\n";		
	}	
}

int main(int argc, char* argv[]){
	
	//Create LinkList For Input And Output
	list<int>* a[2];	
	a[0]=new list<int>();
	a[1]=new list<int>();
	int d;

	//Take Input From File 
	ifstream myfile;
	myfile.open(argv[1]);
  	if (myfile.is_open())
  	{
    		while ( myfile.good())
    		{
      			myfile>>d;
			if(d<0){
				a[0]->Add_last(d);
			}else{
				a[1]->Add_last(d);
			}
			
    		}
    	myfile.close();
  	}
	
	//Radix Sort 
	std::cout<<"Sort For Negativee No:\n";
	RadixSort(a[0],0);
	std::cout<<"Sort For Positive No:\n";
	RadixSort(a[1],1);

	//Marge Two LinkList Into One 
	while(a[1]->Getsize()!=0){
		a[0]->Add_last(a[1]->Del_node());
	}	
	
	//Final Output
	std::cout<<"Final Sorted Array :\n";
	a[0]->display();
	std::cout<<"\n";
	return 0;
}
