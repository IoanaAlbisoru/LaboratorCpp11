/*
Container personalizat
template <class T>
class Container{
	public:
		Container();
		virtual ~Container();
		void Set(T input); -> container = input
		T get(void); ->return container
	private:
		container;--->std::find_if (caut in functie de elementele din container)
			  --->std::remove_if(remove fac pe un container intreg)
}

*/

#include <iostream>

using namespace std;

class IntVector{
	private:
		unsigned int size;
		int* acc;
	public:
		//typical constructor
		IntVector(){
			size = 0;
		} 
		virtual ~IntVector(){
			cout<<"MyIntVector deleted."<<endl;
		}
		//copy constructor
		IntVector(const IntVector&){} 
		//assignment operator
		IntVector& operator = (const IntVector&);
		//move constructor
		IntVector(IntVector&& oldvector){
			this.size = oldvector.size;
			this.acc = new int[this.size];
			for(unsigned int i = 0; i < this.size; i++)
				acc[i] = oldvector.acc[i];
			//reset oldvector
			oldvector.size = 0;
			oldvector.acc = nullptr;
			
		}
		//move assiggnment operator
		IntVector& operator = (IntVect&& other){
			if(this != &other){
				reset the current object's resources
				this.size = 0;
				delete[] acc;
				//pilfer other's resources
				this.size = other.size;
				this.acc = new int[this.size];
				for(unsigned int i = 0; i < this.size; i++)
				acc[i] = other.acc[i];
				//reset other
				other.size = 0;
				other.acc = nullptr;
			
			}
			
			return *this;
		}
		//implementeaza begin()

		//implementeaza end()

};

int main(){

}


