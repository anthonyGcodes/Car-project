#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include "main.h"

int main(int argc, char *argv[])
{
    try
    {
        string filename = "cars.dta";//sets to cars dta test file
        ifstream infile;

        infile.open(filename.c_str());

        Cars c1;
        c1.read(filename); //set infile
        c1.print();
        c1.getTotalCapacity();
        c1.getTotalGears();

    } // END of try
    catch (invalid_argument& b)
    {
        cout << "Invalid_argument";
        cout << b.what() << endl;
    }//invalid argls
    catch (logic_error& b)
    {
        cout << "Logic_error";
        cout << b.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Exception" << endl;
    }
    return 0;
}//main