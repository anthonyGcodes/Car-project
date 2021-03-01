#include "truck.h"

//DEFAULT
Truck::Truck() : Car()
{
   
}//default constructor

//Explicit constructor
Truck::Truck(string id, string name, int gears) : Car(id,name,gears)  //throw invalid arg
{
 
}//explicit constructor

/*
 * MEMBER FUNCTIONS
 */ 

void Truck::print(ostream &out)const
{
    Car::print(out);
    out << endl << endl; //extra space format
}//print

void Truck::read(istream &in) //throw (invalid_argument)
{
    Car::read(in);

    setID(id);//overrides read file

}// END Truck read

void Truck::setID(string id) /*throw (invalid_argument)*/
{
 
    Car::setID(id); // checks original case for id setup.
 
    if(id.at(0) != 'T')//checks if it is type Truck.
        {
            throw invalid_argument ("Truck::setid found invalid id format. No U.");
        }// if
    this->id = id; 
}//setID