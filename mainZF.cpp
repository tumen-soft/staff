#include <iostream>
int main(){

int var_len=3;
int *ptr;
ptr = (int*) malloc(sizeof(int)*var_len);
	
for(int i=0;i<var_len;i++){
	std::cout<<"Введите число: ";
	std::cin>>*(ptr+i);
	
   }
for(int j=0;j<var_len;j++)
        std::cout<<*(ptr+j)<<std::endl;



}
