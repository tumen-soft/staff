#include <iostream>
struct Test{
int* i;

};
int main(){
Test t1;
t1.i=new int(1);
Test t2 = t1;
*t2.i=3;
std::cout << *t1.i << std::endl;


}
