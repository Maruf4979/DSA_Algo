#include <bits/stdc++.h>
using namespace std;
void  insert_at_Bottom(stack<int>&s,int ele)
{
//    base case
if(s.empty())
{
    s.push(ele);
    return ;
}
int num=s.top();
s.pop();
insert_at_Bottom(s,ele);
s.push(num);

}
void reverse_stack(stack<int>&s)
{
    //base case
    if(s.empty())
    return;
    int num=s.top();
    s.pop();
    reverse_stack(s);
    insert_at_Bottom(s,num); 
}
void display(stack<int>s)
{
    vector<int>v;
while(!s.empty())
{
  v.push_back(s.top());
  s.pop();
}
for(auto i:v)
{
    cout<<i<<" ";
}
}
int main()
{
    stack<int>s;
    int ele;
    cout<<"enter ele"<<endl;
    for(int i=0;i<5;i++)
    {
      cin>>ele;
      s.push(ele);
    }
    reverse_stack(s);
    display(s);
    return 0;
}