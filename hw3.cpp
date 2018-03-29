#include <iostream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

//template <class T>
class MyContainer{
	private:
		int container;
	public:
		MyContainer(){
			container = 0;
		}

		virtual ~ MyContainer(){
			cout<<"MyContainer deleted."<<endl;
		}
		//copy constructor
		MyContainer(const MyContainer& cont){
			container = cont.container; 
		}		
		//assignment operator
		MyContainer& operator = (const MyContainer&);
		//move constructor
		MyContainer(MyContainer&& oldcontainer){
			container = oldcontainer.container;
			oldcontainer.container = 0;
		}
		//move assignment operator
		MyContainer& operator = (MyContainer&& other){
			if(this != &other){
				//reset the current object's resources
				container = 0;
				//pilfer other's resources
				container = other.container;
				//reset other
				other.container = 0;
			
			}
			
			return *this;
		}
		void setContainer(int in){
			container = in;
		}
		
		int getContainer(){
			return container;
		}

};

int main(){

	MyContainer *c1 = new MyContainer();
	c1->setContainer(25);
	MyContainer *c2 = new MyContainer();
	c2->setContainer(8);
	MyContainer *c3 = new MyContainer();
	c3->setContainer(17);
	MyContainer *c4 = new MyContainer();
	c4->setContainer(4);
	MyContainer *c5 = c4;
	MyContainer *c6 = c3;

	vector<MyContainer>  v = {c1, c2, c3, c4, c5, c6}; 

	vector<MyContainer>::iterator it = find_if(v.begin(), v.end(),[]( ?? ){
		return it->getContainer() > 10;	
	});

	//fa remove if

	cout<<*it<<endl;
	
	
}
