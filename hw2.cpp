#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <algorithm>

//sortarea unui vector de pairs dupa primul element; daca al doilea element din pair e impar, se inlocuieste cu 0

using namespace std;

int main() {
  
  pair<int,int> p0 = make_pair(12,2);
  pair<int,int> p1 = make_pair(3,3);
  pair<int,int> p2 = make_pair(6,8);
  pair<int,int> p3 = make_pair(4,0);
  pair<int,int> p4 = make_pair(11,1);
  pair<int,int> p5 = make_pair(5,8);
  pair<int,int> p6 = make_pair(7,15);
  pair<int,int> p7 = make_pair(1,3);
  pair<int,int> p8 = make_pair(0,4);
  pair<int,int> p9 = make_pair(9,2);
  
  vector< pair<int, int> > v= {p0, p1, p2, p3, p4, p5, p6, p7, p8, p9};
  
  sort(v.begin(),v.end(), [] (pair<int,int> &l, pair<int,int> &r) ->bool{
      return l.first < r.first;
    });
    
  for(auto i:v){
      if(i.second % 2 != 0)
          i.second = 0;  
      cout<<endl<<i.first<<" "<<i.second<<endl;
  }
}
