#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<fstream>
using namespace std;
void swap(int *i,int *j){
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
int arrange(int *a,int l,int r,int p){
	int key=a[p];	
	swap(&a[p],&a[r]);
	int t=l;
	for(int i=l;i<=r;i++){
		if(a[i]<key){
			swap(&a[i],&a[t]);
			t++;
		}	
	}
	swap(&a[t],&a[r]);
	return t;
}
void quicksort(int *a,int l,int r){
	if(l<=r){
		int pindex=floor((l+r)/2);
		pindex=arrange(a,l,r,pindex);
		quicksort(a,l,pindex-1);
		quicksort(a,pindex+1,r);
	}
}	
int main(int argc, char* argv[]){
	int size=0,temp,i;
	ifstream fin(argv[1]);
	if(fin){	
		fin>>size;
	}	
	int a[size];
	i=0;
	while(fin){
		fin>>temp;
		a[i++]=temp;	
	}
	
	std::cout<<"inputed array \n";	
	for(i=0;i<size;i++){
		std::cout<<a[i]<<" | ";
	}
	std::cout<<"\n";
	
	// Sorting Logic
	quicksort(a,0,i-1);
	
	
	std::cout<<"output array \n";	
	for(i=0;i<size;i++){
		std::cout<<a[i]<<" | ";
	}
	std::cout<<"\n";
	return 0;
}
