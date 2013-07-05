#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include<algorithm>
#include<ctime>
using namespace std;
class MinHeap{
        public:
        vector <int> a;
        int i;
        MinHeap(){
        }
        MinHeap(vector <int> b){
                a=b;
        }
        int isempty(){
                return (a.size()<=0);
        }
        void BuidHeap(){
                for(i=(a.size()/2)-1;i>=0;i--){
	                Hepify(i);	 
	        }
        }
        //Implementing MinHeap 
        void Hepify(int i){
                int l=2*i+1,r=l+1,s,t;
                if(l>a.size())
                        return;
                else if(r>a.size()){
                        s=l;       
                }else{
                        if(a[l]<a[i]&&a[l]<a[r]){
                                s=l;
                        }else if(a[r]<a[i]&&a[r]<a[l]){
                                s=r;
                        }else if(a[i]<a[l]&&a[i]<a[r]){
                                s=i;
                        }
                }
                if(i!=s){
                        t=a[i];
                        a[i]=a[s];
                        a[s]=t;
                        Hepify(s);
                }
                return;
        }        
        void delete_Min(){
                if(isempty()){
                        return;
                }
                cout<<"\nSmallest Element: "<<a[0]<<"\n";
                a[0]=a[a.size()-1];
                a.erase(a.begin()+a.size()-1);
                percolate_down(0);
        }
        void percolate_down(int h){
                int child,temp;
                temp=a[h];
                for(h;h*2<a.size()-1;h=child){
                        if(h==0){child=1;}else{child=2*h;}
                        if(a[child+1]<a[child]){
                                child++;
                        }
                         if(a[child]<temp){
                                a[h]=a[child];
                         }else{
                                break;
                         }
                }
                 a[h]=temp;
        }
        void Display(){
                cout<<"\n";
	        for(i=0;i<a.size();i++){
	                cout<<a[i]<<" | ";
	        }
                cout<<"\n\n";
        }
        //Implementing MinHeap is over 

        
        //Implementing MaxHeap 
        int parent(int c){
               return c/2;
        }
        void insert(int x){
                int tcurr;
                a.push_back(0);
                for(tcurr=a.size()-1;tcurr>1 && x>a[parent(tcurr)];tcurr=parent(tcurr)){
                         a[tcurr]=a[parent(tcurr)];
                }
                a[tcurr]=x;
        } 
        void replace_root(int k){
                if(a[0]>k){
                        a[0]=k; 
                }
                percolate_up(0);  
        }
        void Delete_Max(){
                if(isempty()){
                        return;
                }
                cout<<"\n"<<a.size()<<"-Smallest Element: "<<a[0]<<"\n";
                a[0]=a[a.size()-1];
                a.erase(a.begin()+a.size()-1);
                percolate_up(0);
        }
        void percolate_up(int h){
                int child,temp;
                temp=a[h];
                for(h;h*2<a.size()-1;h=child){
                        if(h==0){child=1;}else{child=2*h;}
                        if(a[child+1]>=a[child]){
                                child++;
                        }
                         if(a[child]>=temp){
                                a[h]=a[child];
                         }else{
                                break;
                         }
                }
                 a[h]=temp;
        }
        void kth_smallest(int k){
                if(k<a.size()){
                        MinHeap *tmh=new MinHeap();
                        for(i=0;i<k;i++){
                                tmh->insert(a[i]);                   
                        } 
                        tmh->percolate_up(0);
                        for(i=k;i<a.size();i++){
                                tmh->replace_root(a[i]);  
                        }
                        tmh->Delete_Max();
                        delete(tmh);
               }else{
                        cout<<"Enter Correct Index\n";
               }        
        }
        //Implementing MaxHeap is over 
};


int main(int argc, char* argv[]){
	vector <int> a; 
	int str,i,ch,k; 
	ifstream fin(argv[1]);
	 fin >> str;
	 while (fin >> str) 
	 {                  
		a.push_back(str);
	 }
	 fin.close(); 
	 srand(unsigned (time(0)));
	 random_shuffle ( a.begin(), a.end());
	 MinHeap *mh=new MinHeap(a);
	 cout<<"Heap OF Given Array Before hepify Operation: ";
	 mh->Display();
	 mh->BuidHeap();
	 cout<<"Heap OF Given Array after hepify Operation: ";
	 mh->Display();
	 do{
	         cout<<"\nPress 1 For Find & Delete smallest Element";
	         cout<<"\nPress 2 For Find K'th Smallest Element";
	         cout<<"\nPress 0 For exit";
	         cout<<"\nEnter the Choice:";
	         cin>>ch;
	         switch(ch){
	                case 1:
	                        cout<<"Heap OF Given Array after Smallest element Delete: ";
	                        mh->delete_Min();
	                        mh->Display();  
	                        break;
	                case 2:
	                        cout<<"\nEnter No(#) For Smalles Element:";
	                        cin>>k;
	                        mh->kth_smallest(k);
	                        break;
	         }	         
	 }while(ch!=0);	 
	 return 0;
}




