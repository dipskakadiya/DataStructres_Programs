#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include<algorithm>
#include<ctime>
using namespace std;

//Node
template <class T1>
class node{
	public:
	T1 data;
	node<T1>*  next;
	node(){
		data=NULL;
		next=NULL;
	}
	node(T1 d){
		data=d;
		next=NULL;
	}
};

//Queue
template <class T1>
class Queue{
	node<T1> *front,*rear;
	int s;
	public:
	
	Queue(){
		front=NULL;
		rear=NULL;
		s=0;
	}   

	void Add_node(T1 d){
		node<T1>* n=new node<T1>(d);	
		n->next=NULL;		
		if(front!=NULL){
			rear->next=n;
			rear=n;			
		}else{
			rear=front=n;		
		}		
		s++;
	}

	int Getsize(){
		return s;
	} 

	T1 Del_node(){
		if(s!=0){
			node<T1>* temp=front;
			if(front==rear){
				front=NULL;
				rear=NULL;
			}else{
				front=front->next;
			}
			T1 d=temp->data;
			delete(temp);
			s--;
			return d;
		}
	}	
};


//Chaining Node 
template <class T1>
class list{
	node<T1>* head;
	int s;
	public:
	
	list(T1 d){
		head=new node<T1>(d);
		s=0;
	}

	void Add_last(T1 d){
		node<T1>* cur=head;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		node<T1>* n=new node<T1>(d);
		cur->next=n;
		s++;
	}
	
	void display(){
		node<T1>* cur=head->next;
		while(cur!=NULL){
			std::cout<<cur->data<<"|";	
			cur=cur->next;
		}
	}
	
	int getsize(){
		return s;
	}
	
	T1 peekele(int p){
		node<T1>* cur=head;
		for(int i=0;i<p;i++){
			cur=cur->next;
		}
		return cur->data;	
	}
};

//Graph
class graph{
	public:
		list<int>* list1[1000];
		Queue<int> *qu;
		vector <int> f; 
		int size;
	graph(int s){
		size=s;
		for(int i=0;i<size;i++){
			list1[i]=new list<int>(i);
			f.push_back(0);
		}
		qu=new Queue<int>();
	}
	void AddEdge(int s,int d){
		list1[s]->Add_last(d);
	}
	void display(){
		for(int i=0;i<size;i++){
			cout<<i<<" : ";			
			list1[i]->display();
			cout<<endl;
		}
	}
	void BFS(int s){
		int temp,temp2;
		qu->Add_node(s);
		f[s]=1;
		while(qu->Getsize()!=0){
				temp=qu->Del_node();
				cout<<temp<<" ";
				for(int i=1;i<=list1[temp]->getsize();i++){
					temp2=list1[temp]->peekele(i);
					if(f[temp2]==0){
						qu->Add_node(temp2);
						f[temp2]=1;
					}
				}
		}	
	}
	
	void DFS(int s){
		int temp2;
		cout<<s<<"|";
		f[s]=0;
		for(int i=1;i<=list1[s]->getsize();i++){
			temp2=list1[s]->peekele(i);
			if(f[temp2]==1){
				DFS(temp2);
			}
		}
	}
	
	int bipartite(int s){
		int temp,temp2;
		int k=1;//red
		qu->Add_node(s);
		f[s]=k;
		while(qu->Getsize()!=0){
				temp=qu->Del_node();
				k=f[temp];
				if(k==1){
					k=2;
				}else if(k==2){
					k=1;
				}
				for(int i=1;i<=list1[temp]->getsize();i++){
					temp2=list1[temp]->peekele(i);
					if(f[temp2]==0){
						qu->Add_node(temp2);
						f[temp2]=k;
					}else{
						if(f[temp2]!=k){
							return 1;
						}
					}
				}
				
		}
		return 0;	
	}
		
};

int main(int argc, char* argv[]){
	vector <int> a; 
	int size,temp,i,j=0,k=0;
	ifstream fin(argv[1]);
	 fin >> size;
	 while (fin >> temp) 
	 {                  
		a.push_back(temp);
	 }
		
	fin.close(); 
	graph *g=new graph(size);
	for(i=0;i<=a.size();i++){
		if(a[i]==1){
			g->AddEdge(k,j);
		}
		if(j==size-1){
			k++;
			j=-1;
		}
		j++;
	}
	cout<<"Adjacency List:\n";
	g->display();
	cout<<"Enter values between 0 to "<<size-1<<":\n";
	cin>>j;
	cout<<"\nBSF:\n";
	g->BFS(j);
	cout<<"\nDFS:\n";
	g->DFS(j);
	k=g->bipartite(j);
	if(k==1){
		cout<<"\nGraph is not bipartite\n";
	}else{
		cout<<"\nGraph is bipartite\n";
	}
}


