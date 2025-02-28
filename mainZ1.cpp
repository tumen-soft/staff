#include <iostream>
#include <set>
#include <string>
struct Test{
int* i;

};
int main(){
std::set<Test*> m;
//Test t=Test();
m.insert(new Test({new int(1)}));
//m.begin().i=new int(1);
//Test t2 = t1;
//*t2.i=3;
for(auto& e : m)std::cout << *e->i << std::endl;


}
