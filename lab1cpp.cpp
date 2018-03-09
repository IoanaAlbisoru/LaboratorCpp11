#include <iostream>

class Human{
  public:
          Human(){};
          ~Human();
          void setName(std::string n){
              name = n;  
          }
          void setAge(int a){
              age = a;
          }
          std::string getName(){
              return name;  
          }
          int getAge(){
              return age;
          }

  private:
          std::string name;
          int age;
};

class Car{
  
  protected:
      int viteza;
  public:
     Car(){};
      virtual int move() = 0;
      virtual std::string getTip() = 0;
  
};

class Combi:public Car{
  private:
          std::string tip;
  public:
          Combi(){
              tip = "Combi";
          }
          
          int move(){
            return 120;
          }
          
          std::string getTip(){
            return tip;
          }
};

class Decap:public Car{
  private:
          std::string tip;
  public:
          Decap(){
              tip = "Decap";
          }
          
          int move(){
            return 180;
          }
          
          std::string getTip(){
            return tip;
          }
};

int main() {
  /*std::cout << "Hello World!\n";
  
  h1->name = "Oana";
  h1->age = 19;
  
  h2->name = "Alexandra";
  h2->age = 20;
  
  h3->name = "Diana";
  h3->age = 14;
  
  h4->name = "Alex";
  h4->age = 23;
  
  if(h1->age < h2->age && h1->age < h3->age && h1->age < h4->age )
        std::cout << h1->age;
  if(h2->age < h1->age && h2->age < h3->age && h2->age < h4->age )
        std::cout << h2->age;
  if(h3->age < h1->age && h3->age < h2->age && h3->age < h4->age )
        std::cout << h3->age;
  if(h4->age < h2->age && h4->age < h1->age && h4->age < h3->age )
        std::cout << h4->age;      
  */
  Car *c1 = new Combi();
  
  std::cout<<"Masina este de tipul:"<<c1->getTip()<<", si atinge: "<< c1->move()<<" kph."<<std::endl;
}
