#include <iostream>

using namespace std;

 /*template<class T>
  void print(T& input){
     
       cout<<input<<"\n";
  }*/
  
  template<class T=int, class U, class V>
  //am sageata T pentru ca fortez ca return-ul sa fie T 
  //vreau sa fortez parametrii b si c sa aiba acelasi tip ca si a
  auto min (T a, U b, V c) -> T{
    string inTypeb = typeid(b).name();
    string inTypec = typeid(c).name();
    
    int min = a;
    
    if(inTypeb[0] != 'i' || inTypec[0] != 'i'){
        cout<<"Tipul numerelor nu e int !"<<"\n";
        
        return 0;
    }
    else{    
      if( b < a )
          return b;
      else if( c < a)
          return c;
    }
  }
  
int main() {
  
  cout<<min<int,int,float>(3,1,2.4)<<"\n";
  cout<<min<int,int,int>(3,1,2)<<"\n";

  
  
  //print<int>(3);
  
}