#include "delivery.h"

/* Default constructoy*/
Delivery::Delivery() : Car()
{
    setCapacity(1); //sets capacity
}// End default constructor

/* Explicit constructor*/ 
Delivery::Delivery(string id, string name, int gears, int capacity) : Car(id,name,gears)  //throw (invalid_argument)
{
    setCapacity(capacity);//update capacity
}// End Explicit constructor

/*
 * MEMBER FUNCTIONS
 */ 

/* get capacity*/
int Delivery::getCapacity()const
{
    return capacity;
}//END get capacity

/* delivery print */
void Delivery::print(ostream &out) const
{
    Car::print(out);//calls Car print

    out << "Capacity amount: " << capacity << endl; //outputs capacity with format
    out << endl;

}// end delivery print

/* delivery read */
void Delivery::read(istream &in) //throw (invalid_argument)
{
    int tempCapacity = 0; 
                          
    Car::read(in); //reads input file
    
    if(! in)
    {
        throw invalid_argument("Delivery::read in file unable to open.");
    }//if
    
    in >> tempCapacity; //reads the capacity int .
    setID(id);//sets id
    setCapacity(tempCapacity);//sets capacity

}// END delivery read

/* set capacity*/
void Delivery::setCapacity(int capacity) //throw (invalid_argument)
{
    if (capacity < 1 || capacity > 120)
    {
        throw invalid_argument ("Delivery::setCapacity found an invalid input");
    }//if
        
    this->capacity = capacity; // sets capacity

}//END set capacity

/* set id*/ 
//Sets this delivery Car's ID, which must have the format D[0-9][0-9]. 
void Delivery::setID(string id) /*throw (invalid_argument)*/
{
    Car::setID(id); //checks if the setID passes og checks.

    if(id.at(0) != 'D')
    {
        throw invalid_argument ("Delivery::setID found invalid id format.");
    }//if
    this->id = id;//sets id
}// END set id
