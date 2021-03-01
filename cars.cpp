#include "cars.h"

/* Default constructor */
Cars::Cars()
{
    vector<Car*>Cars; // initializes empty vector.
    
}// END Default constructor

/* Destructor */
Cars::~Cars()
{
    unsigned numDeleted = 0;
    for (unsigned n = 0; n < cars.size(); n++)
    {
        delete cars.at(n);
        
        numDeleted++;
    }//for
}// END Destructor

/*
 * MEMBER FUNCTIONS
 */ 

/* get total capacity*/
int Cars::getTotalCapacity() const
{
    int sum = 0;
    
    Car *p = NULL;
    
     for(unsigned i = 0; i < cars.size(); i++)
     {
         p = cars.at(i);//set pointer to cars vector
         if( typeid (*p) == typeid(Delivery))
         {
            sum+= dynamic_cast<Delivery *>(p)->getCapacity(); //add capacity 
         }//if
     } //for
    return sum;

}// END get total capacity

/* get total gears*/
int Cars::getTotalGears() const
{
    int totalGears = 0;

    for(unsigned i = 0; i < cars.size(); i++)
    {
        totalGears+= cars[i]->getGears(); //adds gears of Car to total
    }//for

    return totalGears; // the total sum of gears for all members of the cars vector.
}// END get total gears

/* Cars print */
void Cars::print (ostream &out)const
{
   for(unsigned i = 0; i < cars.size(); i++)
    { 
        cars.at(i)->print(out); //prints out Car vectors
    }//for

}//END print 

/* cars read */
//ifstream infile
void Cars::read(string filename) //throw (logic_error, invalid_argument)
{  
    ifstream infile; //name for file
    infile.open(filename.c_str()); //cstring to string

    Car *addMe = NULL; //pointer
    CarFactory factory;
    if(!(infile)) //if file not open
    {
        throw logic_error("cars::read filename did not open correctly.");
        //Car::read(filename); //(called elsewhere delete)
    }//if

    else
    {
        while(infile)
        {
            //Car factory checks if its D or T, we point with addMe and add it 
            //into the cars vector.    
            addMe = factory.make(infile);// calls read in factory
        
            if(addMe != NULL)//checks if null
                cars.push_back(addMe);//puts the object that factory makes into the cars vector. 
        } //while
        infile.close(); //closes infile
    }//else
}// END read

/* cars size */
unsigned Cars::size ()const
{
    return cars.size(); //size of vector of cars
}//end cars size