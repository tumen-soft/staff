#include <iostream>
#include <algorithm>
#include <string>
struct node{
char data;
node *next;
};
node *head=new node();
node *P=head;
void reverse()
    {
        int i = 1;
        int n = 6; //can get n from countnodes();
        int p=n;
        node *current = head;
        node *cur = head;
      
        
        while (current->next != nullptr)
        {
            current = current->next;
            i++;
            if (i == n)
            {
                std::swap(cur->data, current->data);
                current = head;
                cur = cur->next;
                i = 1;
                n = n - 1;
                
            }
   if (n==p/2) break; 
  
   
        }
    }


void printlist(){


//todo::for loop linked
while(P){
std::cout<<P->data<<" ";
P=P->next;
}
std::cout<<std::endl;


}






int main(){

//todo  init list elements
head->data='A';
head->next=new node();
head->next->data='B';
head->next->next=new node();
head->next->next->data='C';


printlist();



reverse();
P=head;

printlist();





}

