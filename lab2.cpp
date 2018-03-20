#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <forward_list>
#include <queue>
#include <functional> //pentru greater si less

using namespace std;

struct S{
  
};

void foo(int a){
  std::cout<<"foo"<<std::endl;
}

void foo(const char*a){
  std::cout<<"bar"<<std::endl;  
}

  
int main() {
  
  int i;
  const int ci = 6;
  const int& cri = i;
  const S* p = new S();

  //auto poate sa infereze orice tip, mai putin const sau  referinta la orice tip
  
  auto var1 = i;   // tip int
  auto var2 = ci;  // int
  auto var3 = cri; // int
  auto var4 = p;   //pointer la S
  
  decltype(i) v1;
  decltype(ci) v2 = 8;
  decltype(cri) v3 = i; //e constanta de tip intreg, referinta la intreg => trebuie initializata cu o adresa
  decltype(p) v4; //decltype poate sa interfereze si const si referinta
  
  decltype((i)) v = var1; //ia adresa la tipul inferat, chiar daca nu am dat adresa (da eroare pentru ca am adresa neinitializata) => trebuie initializat cu o valoare intreaga (numele unei variabile intregi)

  //-------------------------------------------------------------
  
  foo(0);
  //foo(NULL);   // in functie de compilator, NULL va fi considerat fie int , fie ambiguu => uita ca exista NULL
  foo(nullptr);  // in loc de NULL, folosesc nullptr -> nu considera variabila ca fiind int sau double, ci merge pe pointeri

  //------------------------VECTOR---------------------------------
  
  vector<int> array {2, 5, 8, 3, 1};
 
  for(auto a : array)
      cout<<a<<" ";
      
  //begin() pointeaza spre primul element; begin returneaza iterator => ca sa il afisez trebuie dereferentiat
  //end() pointeaza catre terminator -> end()-1 pointeaza spre ultimul element => trebuie dereferentiat
  //front() - la fel ca begin(), doar ca afiseaza direct valoarea
  //back() - la fel ca end(), doar ca afiseaza direct valoarea
  //altbegin() returneaza pointer spre ultimul element din container
  
  array.front() = 10;
  array.back() = 2;
  
  cout<<endl;
  for(auto a : array)
      cout<<a<<" ";
      
  *array.begin() = 20;
  *(array.end()-1) = 3;
  
  cout<<endl;
  for(auto a : array)
      cout<<a<<" ";
      
  //-----------------------TUPLU---------------------------------
  //-----------------------PAIR - tuplu cu 2 caracteristici -----
    
  auto t = make_tuple(23, 54 , 1, "laborator", 'X');
  cout<<endl<<get<2>(t);
  
  tuple<int,char> tup (12, 'O');
  auto variab = get<1>(tup);
  cout<<endl<<variab;
  
  //********   HW: slide 13   **********
  
  //----------------------FORWARD_LIST---------------------------
  //-> lista simplu inlantuita (nu pot accesa elemente anterioare)
      
  forward_list<int> lst = {17, 25, 4, 2, 6};
  lst.resize(4); //elimina ultimul element
  lst.resize(7); //adauga 0-uri pana ajunge lungimea listei la 7
  
  cout<<endl;
  auto last = lst.begin();
  for(auto it = lst.begin(); it != lst.end() ; it++){
      last = it; //asa procedez cand vreau sa iau ultimul element (pentru ca nu pot face end()--)
       cout<<*it<<" ";
  }
  lst.insert_after(last,2);
  //pot sa afisez si cu foreach (ca mai sus)
  //pentru parcurgere, folosesc iterator cand am nevoie de pozitia elementului din lista
  
  //---------------------PRIORITY_QUEUE--------------------------
  //-> queue in care noi stabilim tipul de prioritate
  //-> greater, elementul n+1 trebuie sa fie mai mare decat elementul n
  //-> less, elementul n-1 trebuie sa fiie mai mare decat elementul n
  
  cout<<endl;  
  int b[] = {17, 43, 11, 21, 45};
  priority_queue<int, vector<int>, greater<int>> pq(b, b+5);
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  
  cout<<endl;
  priority_queue<int, vector<int>, less<int>> pq1(b, b+5);
  while(!pq1.empty()){
    cout<<pq1.top()<<" ";
    pq1.pop();
  }
  cout<<endl;

  //********   optional HW   *********
  //implementarea propriului container -nu folosesc map si vector
  //folosesc template-uri
  //trebuie sa defineasca ce inseamna begin si end(ca sa mearga iteratorul)
  //poate fi modelat ca oricare dintre containerele existente 
  
}
