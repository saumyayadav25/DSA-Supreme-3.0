#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    // protected:
    //     string name;

    protected:
        string name;
        string model;
        int noOfTyres;
        // string getName(){
        //     return this->name;
        // }

    public:
        Vehicle(string _name, string _model, int _noOfTyres){
            cout<<"I am inside Vehicle ctor"<<endl;
            this-> name = _name;
            this-> model = _model;
            this-> noOfTyres = _noOfTyres;
        }
    public:
        void start_engine(){
            cout<<"engine is starting " << name <<" " << model << endl;
        }
        void stop_engine(){
            cout<<"engine is stopping " << name <<" " << model << endl;
        }

    ~Vehicle(){
        cout<<"inside vehicle dtor"<<endl;
    }
};

class Car : public Vehicle{
    protected:
        int noOfDoors;
        string transmissionType;

    public:
        Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType): Vehicle(_name,_model, _noOfTyres){
            cout<<"I am inside Class ctor"<<endl;
            this->noOfDoors = _noOfDoors;
            this->transmissionType = _transmissionType;
        }
        void startAC(){
            cout<< "AC has started of " << name << endl;
        }

        ~Car(){
        cout<<"inside car dtor"<<endl;
    }
};

class MotorCycle: public Vehicle{
    protected:
        string handleBarStyle;
        string suspensionType;
    public:
        
        MotorCycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType): Vehicle(_name, _model, _noOfTyres){
            cout << "Motorcycle ctor called"<<endl;
            this->handleBarStyle = _handleBarStyle;
            this->suspensionType = _suspensionType;
        }
        
        void wheelie(){
            cout<<"Wheelie " << name << endl;
        }

        ~MotorCycle(){
        cout<<"inside motorcycle dtor"<<endl;
    }
};

int main(){
    Car A("Maruti 800", "LXI", 4, 4, "Manual");
    A.start_engine();
    A.startAC();
    A.stop_engine();
    
    MotorCycle M("BMW","VXI",2,"U","hard");
    M.start_engine();
    M.wheelie();
    M.stop_engine();
    return 0;
}