#include <iostream>
#include <vector>
#include <map>
#include <string>
template <class T>
class i_am_class{
public:
enum ee{
	hello
};
void f(){

using ee = i_am_class<T>::ee;
ee e =hello;
std::cout<<e<<std::endl;
}



};

void f(){
i_am_class<int>().f();

}

int main(){
std::vector<int> foo;
{
//std::vector<int> tris;
}


std::map<std::vector<int>,std::string> tumen_soft {{foo, "test"}};


std::vector<int> v;
f();
}
