#include <iostream>
#include <vector>
class Чат{




};

int create(){};
void Foo(int){};
void(&rf)(int) = Foo;
//rf(42); // тоже самое, что и Foo(42);
int main(){
int x = 1;
using RI = int&;
RI rx = x;
std::cout<<rx<<std::endl;
int *c[]={&rx};
//c.push_back(rx);
std::cout<<*(c[0])<<std::endl;
x = 2;
std::cout<<rx<<std::endl;
//std::vector<int> c;
//c.push_back(rx);
std::cout<<*(c[0])<<std::endl;


}
