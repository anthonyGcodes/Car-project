#include "car.h"

/* Default Constructor*/
Car::Car()
{
    id = "A00";
    name = "defaultName";
    gears = 1;    
    //default values that pass the check.
}// END Default Constructor	

/* Explicit Constructor*/
Car::Car(string id, string name, int gears) 
{
    setID(id);
    setName(name);
    setGears(gears);
}// END Explicitt Constructor	

/* Destructor*/
Car::~Car()
{

}// End Destructor	

/*
 * MEMBER FUNCTIONS
 */ 

/* get Gears */
int Car::getGears() const
{
    return gears;
}// END get gears

/* get ID */
string Car::getID() const
{
    return id;
}// END get ID

/* get Name */
string Car::getName() const
{
    return name;
}// END get name

/* ostream */
void Car::print (ostream &out) const
{
    if(!out)
        {
            throw invalid_argument("Car::print output stream in failed state.");
        }//if
    
    out << "Name: "  << name << endl;
    out << "Gears: " << gears << endl; //for formatting

}//end ostream

/* read */
void Car::read (istream &in) 
{
   char quoMark = '?';
   int tempGears;
   string tempID, tempName;


    if (!in) //checks if file opens or not.
    {
        throw invalid_argument("Car::read file not able to open.");
    }//if
    
   in >> tempID >> quoMark; //grabs first "/"
   getline(in,tempName,'\"'); //stops at second '\'

        if(quoMark != '\"')
        {
            throw invalid_argument("Car::read invalid_argument, quotation mark not found.");
        }//if

   in >> tempGears;

   setID(tempID);
   setName(tempName);
   setGears(tempGears);

}//end ostream

/* set Gears */
void Car::setGears(int gears) 
{
    if( gears < 1 || gears > 72)
    {
        throw invalid_argument("Car::setGears invalid argument for gears value.");
    }//if
    else
    {
        this->gears = gears;
    }//else
}// END set gears

/* set ID */
void Car::setID(string id)
{   
    if (id.length() < 3)
    {
        throw invalid_argument("Car::setID id is less than 3 characters.");
    }//if
    
    if (id.length() > 3)
    {
        throw invalid_argument("Car::setID id is greater than 3 characters.");
    }//if
    if (islower(id.at(0)))
    {
        throw invalid_argument("Car::setID input invalid, first character is lowercase");
    }//if
    
    if ( ! (isalpha(id.at(0))) ) //if its not an alphabat char, throw invalid argument.
        {
        throw invalid_argument("Car::setID input invalid in the first char of id");
        }//if 

    if ( ! (isdigit(id.at(1))) ) //if it is not a digit ranging from 0-9, throw inv arg.
        {   
        throw invalid_argument ("Car::setID found invalid id input, first int.");
        }//if
    if ( ! (isdigit(id.at(2))) ) //if it is not a digit ranging from 0-9, throw inv arg.
        {   
        throw invalid_argument ("Car::setID found invalid id input, second int.");
         }//if    
    
    this->id = id;

}// End set ID

/* set name */
void Car::setName(string name) 
{
     this->name = name; 
}// End set ID
