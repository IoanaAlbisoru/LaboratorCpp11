/*
- o clasa de baza -> abstracta
- minim 2 derivate
- virtual deconstructors
- public, protected, private
- constructor ( default si copy )
- Baza b = new Derivata() -> 10 obiecte
- print ceva specific
*/

#include <iostream>

class Plane{
	protected:
		std::string planeID;
		std::string type;
		int engine_power;

	public:
		//normal constructor
		Plane(std::string id, int ep){ 
			planeID = id;
			type = "plane";
			engine_power = ep;
		}
		//copy constructor
		Plane(const Plane &p){
			planeID = p.planeID;
			type = p.type;
			engine_power = p.engine_power;
		}
		//deconstructor
		virtual ~Plane(){
			std::cout<<this->planeID<<" deleted...\n";
		}

		std::string getPlaneID(){
			return planeID;
		}

		int getEnginePower(){
			return engine_power;
		}

		void takeOff(){
			std::cout<<this->planeID<<" ("<<this->type<<") - initiating takeoff procedure...\n";
		}
	
		void land(){
			std::cout<<this->planeID<<" ("<<this->type<<") - initiating landing procedure...\n";
		}

		void fly(){
			std::cout<<this->planeID<<" ("<<this->type<<") - flying...\n";
		}
	
		virtual int price() = 0;
};

class FighterPlane : public Plane{

	public:
		FighterPlane(std::string id, int ep):Plane(id,ep){
			type = "fighter plane";
		}
		FighterPlane(const FighterPlane &p):Plane(p){}

		void launchMissile(){
			std::cout<<this->planeID<<" - initiating launching missile procedure...\n";
		}
		
};

class Mig : public FighterPlane{
	
	public:
		Mig(std::string id, int ep):FighterPlane(id,ep){
			type = "Mig fighter plane";
		}
		Mig(const Mig &p):FighterPlane(p){}

		void highSpeedGeometry(){
			std::cout<<this->planeID<<" - high speed geometry selected...\n";
		}

		void normalGeometry(){
			std::cout<<this->planeID<<" - normal geometry selected...\n";
		}

		int price(){
			return 100000;
		}
};

class TomCat : public FighterPlane{

	public:
		TomCat(std::string id, int ep):FighterPlane(id,ep){
			type = "TomCat fighter plane";
		}
		TomCat(const TomCat &p):FighterPlane(p){}

		void refuel(){
			std::cout<<this->planeID<<" - initiating refueling procedure...\n";
		}
		int price(){
			return 200000;
		}
};

class PassengerPlane : public Plane{
	private:
		int max_passengers;
	public:
		PassengerPlane(std::string id, int ep):Plane(id,ep){
			type = "passenger plane";
		}
		PassengerPlane(const FighterPlane &p):Plane(p){}

		void setMaxPassengers(int mp){
			max_passengers = mp;
		}

		int getMaxPassengers(){
			return max_passengers;
		}

}; 

class Boeing : public PassengerPlane{

	public:
		Boeing(std::string id, int ep):PassengerPlane(id,ep){
			type = "Boeing passenger plane";
		}
		Boeing(const Boeing &p):PassengerPlane(p){}

		int price(){
			return 300000;
		}
};

class Concorde : public PassengerPlane{

	public:
		Concorde(std::string id, int ep):PassengerPlane(id,ep){
			type = "Concorde passenger plane";
		}
		Concorde(const Concorde &p):PassengerPlane(p){}

		void goSuperSonic(){
			std::cout<<this->planeID<<" - supersonic mode activated...\n";
		}

		void goSubSonic(){
			std::cout<<this->planeID<<" - subsonic mode activated...\n";
		}

		int price(){
			return 400000;
		}
};

int main(){
	Concorde *p1 = new Concorde("1", 2343);
	Boeing *p2 = new Boeing("2", 1200);
	p1->setMaxPassengers(500);
	p2->setMaxPassengers(300);
	Mig *f1 = new Mig("101", 100);
	TomCat *f2 = new TomCat("102", 101);
	TomCat *f3 = f2;
	Concorde *p3 = new Concorde("3", 2343);
	Boeing *p4 = new Boeing("4", 1200);
	p3->setMaxPassengers(1200);
	p4->setMaxPassengers(600);
	Mig *f4 = new Mig("103", 4324);
	TomCat *f5 = new TomCat("104", 2000);
	Concorde *p5 = p1;

	std::cout<<"The price for a Concorde plane is: "<<p1->price()<<"\n";
	std::cout<<"The price for a Boeing plane is: "<<p2->price()<<"\n";
	std::cout<<"The price for a Mig plane is: "<<f1->price()<<"\n";
	std::cout<<"The price for a TomCat plane is: "<<f2->price()<<"\n";
	
	p1->getMaxPassengers();	
	p1->takeOff();
	p1->goSuperSonic();	
	p1->fly();
	p2->land();
	p3->takeOff();
	p3->goSubSonic();
	p4->fly();
	p5->land();
	
	f1->takeOff();
	f1->launchMissile();
	f1->highSpeedGeometry();
	f2->takeOff();
	f2->fly();
	f2->refuel();
	f3->land();
	f4->takeOff();
	f4->normalGeometry();
	f4->land();
	f5->takeOff();
	f5->refuel();
	delete(f5);

	
	
}
