#include<iostream>
#include<fstream>
using namespace std;
void sort(int a[],int i,int temp)
{
	int j;
	for(j=i-1;j>=0;j--){
		if(a[j]<temp)
			break;
		a[j+1]=a[j];		
	}
	a[++j]=temp;	
	std::cout<<"output array \n";	
	for(j=0;j<i;j++){
		std::cout<<a[j]<<" | ";
	}
	std::cout<<"\n";

}

int main(int argc, char* argv[]){
	int size=10,temp,i,max;
	ifstream fin(argv[1]);
	if(!fin.eof()){	
		fin>>size;
	}	
	int a[size];
	i=0;
	while(i!=size && !fin.eof()){
		fin>>temp;
		sort(a,i,temp);
		i++;
	}		
	return 0;
}




