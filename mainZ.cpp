#include <iostream>
#include <vector>
using FI = void(int);

void Foo(int x){
std::cout<<x<<std::endl;
};
class Pro{
public:
FI &job=Foo;


};

class Чат{
//FI &fun;
public:
Чат(Pro p):rf(p.job){};
FI *rf=NULL;

};

class Team{
public:
int x;

};

//rf(42); // тоже самое, что и Foo(42);
int main(){
Pro p;
Чат *ч= new Чат(p);
ч->rf(42);
std::vector<Team> t;
t.push_back({3});

}
