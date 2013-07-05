#include<iostream>
#include<fstream>
#include <math.h>
#include <vector>
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
		data="";
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
	
	
	
	int Search(T1 d){
	        int s=0;
	        node<T1>* cur=head->next;
		while(cur!=NULL){
			s++;
			if(cur->data.compare(0, d.length(), d) == 0){
			        break;
			}
			cur=cur->next;
		}
		return s;
	}

};

class Hashtable{
	public:
	list<string>* list1[1000];
	string *list2;
	int d,size,f;
	Hashtable(int s){
		d=0;
		f=0;
		size=s*0.75;
		list2=new string[size];
		for(int i=0;i<size;i++){
			list1[i]=new list<string>();
			list2[i]="0";
		}
	}
	void Hashtable_SC(string data)
	{	
		list1[getAscii(data)%size]->Add_last(data);		
	}
	int search_SC(string data){
	        return list1[getAscii(data)%size]->Search(data);
	}
	int search_OA(string data){
	        int s=0,i,index=getAscii(data)%size;
	                if(list2[index].compare(0, data.length(), data) == 0){ 
	                       s=getAscii(data)%size+1;     
	                }	        
	                for(i=index;i<size;i++){
	                        if(list2[i].compare(0, data.length(), data) == 0){
	                                s=i+1;
	                                break;
	                        }
	                }
	                if(i==size){
	                        for(i=0;i<index;i++){
	                                if(list2[i].compare(0, data.length(), data) == 0){
	                                        s=i+1;
	                                        break;
	                                }
	                        }
	                }
	        
	        return s;
	}
	int getAscii(string data){
	        d=0;
		for(int i=0;data[i]!='\0';i++)
		{
		        d=d+((int)data[i]);
		}
		return d;
	}
	int gerindex(string data){
	        return getAscii(data)%size;
	}
	void display_OA(){
		for(int j=0;j<size;j++){
		        if(list2[j]!="0"){
		                cout<<list2[j]<<" | ";
		        }else{
		                cout<<"  | ";
		        }
		        			
		}
		cout<<"\n";
	}
	void Open_Addressing(string data){
		if(f<size){
		        StoreData(data,getAscii(data)%size);
		        display_OA();
		}else{
		        cout<<"Array Full \t";
		}
		
	}
	void StoreData(string data,int index){
	int i;
	        if(list2[index]=="0"){
	                list2[index]=data; 
	                f++; 
	        }else{
                        if(index!=getAscii(list2[index])%size){ 
	                        string temp=list2[index];
	                        list2[index]=data;
	                        data=temp;     
	                }	        
	                for(i=index;i<size;i++){
	                        if(list2[i]=="0"){
	                                break;
	                        }
	                }
	                if(i!=size){
	                        list2[i]=data; 
	                        f++;   
	                }else{
	                        for(i=0;i<index;i++){
	                                if(list2[i]=="0"){
	                                        break;
	                                }
	                        }
	                        if(i!=index+1){
	                                list2[i]=data; 
	                                f++;
	                        }	                
	                }
	        }       
	       
	}
	void display(){
		for(int j=0;j<size;j++){
		        cout<<j<<" : ";
			list1[j]->display();
			std::cout<<"\n";
		}
	}
};

int main(int argc, char* argv[]){
	string temp;
	vector<string> input; 
	int size=0,i;
	ifstream fin(argv[1]);
	while (fin >> temp) 
	{                  
		input.push_back(temp+'\0');
	}
	size=input.size();
	fin.close();
	Hashtable *ht=new Hashtable(size);
	cout<<"\n\nHash Table With Oper Addressing:\n\n";
	for(i=0;i<size;i++){
	        ht->Hashtable_SC(input[i]);
		ht->Open_Addressing(input[i]); 
	}
	cout<<"\n\nHash Table With Seprate Chaining:\n\n";
	ht->display();
	cout<<"\n\nDispaly Index of Seprate Chaining and Open Addressing:\n\n";
	for(i=0;i<size;i++){
	        cout<<input[i]<<": Separate Chaining Index: \t"<<ht->gerindex(input[i])<<" : "<<ht->search_SC(input[i])<<" | Open Addressing Index: ";
	        int temp=ht->search_OA(input[i]);
	        if(temp!=0){
	                cout<<temp<<"\n";
	        }else{
	                cout<<"Not Fount\n";
	        }
	}
	return 0;
}




