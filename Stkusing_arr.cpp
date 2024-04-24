#include<iostream>
#include<stack>
using namespace std;
class stack
{
    // properties
    public:
  int size;
  int top;
  int*arr;
//   Behaviour
stack(int size) //constructor
{
    this->size=size;
    arr=new int [size];
    top=-1;
}
// to insert the elements in the stack
void push(int x)
{
  if(size-top>1)
  {
   top++;
   arr[top]=x;
  }
  else
  {
   cout<<"stack over flow"<<endl;
  }
}
//  to delete the elements from the stack
int pop()
{
 int x=-1;
 if(top==-1)
 {
    return x;
 }
 else
 {
   x=arr[top--]; 
 }
 return x;
}
//  to find the top view element in the stack
int top()
{
  if(top>=0)
  return arr[top];
}
//  to search an element fron the stack
int peek(int pos)
{
 int x=-1;
 if((top-pos+1)<0)
 {
    return -1;
 }
 else
 {
   x=arr[top-pos+1];
 }
 return x;
}
// to check whether the stack is empty or not
bool isempty()
{
  if(top==-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
};
int main
{
  // incomplete
    stack  s(10);
    s.push(5);
    s.push(7);
    s.push(6);
    cout<<s.pop()<<endl;
    return 0;
}