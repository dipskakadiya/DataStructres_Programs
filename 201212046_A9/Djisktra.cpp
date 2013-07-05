#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

template <class T1>
class node{
	public:
	T1 data;
	T1 d;
	node<T1>*  next;
	node(){
		data=NULL;
		d=NULL;
		next=NULL;
	}
	node(T1 d1,T1 d2){
		data=d1;
		d=d2;
		next=NULL;
	}
};

template <class T1>
class list{
	node<T1>* head;
	int s;
	public:
	
	list(T1 d1,T1 d2){
		head=new node<T1>(d1,d2);
		s=0;
	}

	void Add_last(T1 d1,T1 d2){
		node<T1>* cur=head;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		node<T1>* n=new node<T1>(d1,d2);
		cur->next=n;
		s++;
	}
	
	void display(){
		node<T1>* cur=head->next;
		while(cur!=NULL){
			std::cout<<cur->data<<"_"<<cur->d<<"|";	
			cur=cur->next;
		}
	}
	
	int getsize(){
		return s;
	}
	
	int length(int v){
		node<T1>* cur=head;
		while(cur->data!=v){
			cur=cur->next;
		}
		return cur->d;
	}
	
	T1 peekele(int p){
		node<T1>* cur=head;
		for(int i=0;i<p;i++){
			cur=cur->next;
		}
		return cur->data;	
	}
};

class graph{
	public:
		list<int>* list1[1000];
		vector <int> dis;
		vector <int> v;  
		vector<int> str; 
		int size;
	graph(int s){
		size=s;
		for(int i=0;i<size;i++){
			list1[i]=new list<int>(i,0);
			dis.push_back(1000);
			str.push_back(-1);
		}
	}
	void addEdge(int s,int d1,int d2){
		list1[s]->Add_last(d1,d2);
	}
	void display(){
		for(int i=0;i<size;i++){
			cout<<i<<" : ";			
			list1[i]->display();
			cout<<endl;
		}
	}
	int findsmallest(vector <int> t){
		int small=0;
		for(int i=0;i<t.size();i++){
			if(dis[small]>dis[t[i]]){
					small=i;
			}
		}
		return small;
	}
	
	void djikstra(int st){
		int v1,temp_u,u,i;
		dis[st]=0;
		str[st]=-2;
		for(i=0;i<size;i++){
					v.push_back(i);
		}
		vector <int> t=v;
		while(!t.empty()){
			temp_u=findsmallest(t);
			u=t[temp_u];
			t.erase (t.begin()+temp_u);
			for(i=1;i<=list1[u]->getsize();i++){
				v1=list1[u]->peekele(i);
				if(dis[u]+list1[u]->length(v1)<dis[v1]){
					dis[v1]=dis[u]+list1[u]->length(v1);
					str[v1]=u;		
				}			
			}			
		}
		for(i=0;i<dis.size();i++){
			cout<<"shortest PAth OF "<<i<<": "<<i;
			int j=i;
			while (str[j]!=-2){
					cout<<str[j];
					j=str[j];
			}
			cout<<"   Distance="<<dis[i]<<endl;
		}
		
	}
	
};

int main(int argc, char* argv[]){
	vector <int> a; 
	int size,str;
	ifstream fin(argv[1]);
	 fin >> size;
	 while (fin >> str) 
	 {                  
		a.push_back(str);
	 }
		
	fin.close(); 
	graph *g=new graph(size);
	int i,j=0,k=0,b=0;
	for(i=0;i<a.size();i++){
		if(a[i]!=-1){
			g->addEdge(k,j,a[i]);
		}
		if(j==size-1){
			k++;
			j=-1;
		}
		j++;
	}
	cout<<"Graph Adjacency:\n";
	g->display();
	cout<<"Enter node from which you want to find shortest path( 0 to "<<size-1<<" )";
	int src;
	cin>>src; 
	g->djikstra(src);
	
}


