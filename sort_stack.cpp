#include <bits/stdc++.h>
using namespace std;
void sortedinsert(stack<int>&s,int num)
{
    // base case
    if(s.empty() || (!s.empty()&&(s.top()<num)))
    {
        s.push(num);
        return ;
    }
    int n=s.top();
    s.pop();
    sortedinsert(s,num);
    s.push(n);
}
void sortedstack(stack<int>&s)
{
    if(s.empty())
    return;
    int num=s.top();
    s.pop();
    sortedstack(s);
    sortedinsert(s,num);
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
    sortedstack(s);
    display(s);
    return 0;
}