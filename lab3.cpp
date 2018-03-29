#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;
 //---------------------LAMBDA EXPRESSIONS-------------------------

 //lambda function that sums two numbers
 
  //template <class R, class A>
 /* std::function<R(A, A)> sum = [](A a, A b) -> R
  {
    return a+b;
  } ;*/
  
  //sau
  
  std::function<int(int, int)> sum2 = [](int a, int b) -> int
  {
    return a+b;
  } ; 
  
  //lambda function that tests if a number (int) is odd
  //template <class A> -- c++14
  std::function<bool(int)> isOdd = [](int i) -> bool
  {
    return (i % 2) != 0;
  };
  
  
  //copy the last 4 entries from a vector of integers
  
int main() {
  cout << sum2(5,4)<<"\n";
  cout << isOdd(3)<<"\n";
  cout << isOdd(8)<<"\n";
  
  //---------------COPY----------COPY_IF-------------------------------------
  //copy the entries from a vector of integers
  
  vector<int>a = {1,2,3,4,5,6,7,8,9};
  vector<int>b (a.size());
  vector<int>c (a.size());
  auto it = copy_if(a.begin(), a.begin()+4, b.begin(),[](int i){return i>1;});
  b.resize(distance(b.begin(),it));
  
  for(auto i:b)
    cout<<i<<" ";
    cout<<endl;
   
  auto it2 = copy_if(a.end()-4, a.end(), c.begin(),[](int j){return j<7;});
  //c.resize(distance(c.begin(),it));
  
  for(auto i:c)
    cout<<i<<" ";
    
  //find the first element 
  vector<int>::iterator it3 = find_if(a.begin(),a.end(),[](int i){return i==5;});
    cout<<"\n";
    cout<<*it3<<"\n";
    
  
 
}