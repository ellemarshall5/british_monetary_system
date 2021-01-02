#include <iostream>
using namespace std;
#include "sterling.h"

int main()
{
    Sterling amount1; //create object
    Sterling amount2(12,8,9); //create object

    cout << "Constructor with no arguments gives you: " << endl; //print statement
    cout << "Pounds: " << amount1.get_pounds() <<  " Shilling: "
         << amount1.get_shills() << " Pence: " << amount1.get_pence() << endl; //print statement that gets amounts

    cout << "Constructor with three arguments gives you: " << endl;//print statement
    cout << "Pounds: " << amount2.get_pounds() << "Shilling: "
         << amount2.get_shills() << "Pence: " << amount2.get_pence() << endl; //print statement that gets amounts


    cout << "Constructor with one argument (12,8,9) gives you: " << endl;//print statement
    Sterling amount5("12.8.9");//create object
    cout << "Using get_old_system() method: " << amount5.get_old_system() << endl; //print statement that gets amounts

    cout << "Constructor with one argument(45.67) gives you: " << endl;//print statement
    Sterling amount3(45.67);//create object
    cout << "Pounds: " << amount3.get_pounds() << "Shilling: "
         << amount3.get_shills() << "Pence: " << amount3.get_pence() << endl; //print statement that gets amounts


    cout << "Constructor with one argument (45.67) and using << operator" << endl; //print statement
    Sterling amount6(45.67);//create object
    cout << amount6; //prints out object in proper format


    cout << "Constructor with one argument (42.27)" << endl;
    Sterling amount7(42.27);//create object
    cout <<  amount7 << endl; //prints out object in proper format
    cout << "Update pounds to 23" << endl;
    amount7.set_pounds(23); //updates pounds_
    cout << amount7 << endl; //prints out object in proper format


    cout << "Constructor with one argument (42.27)" << endl;
    Sterling amount8(42.27);//create object
    cout << amount8 << endl; //prints out object in proper format
    cout << "Update shills to 67 and adjust numbers" << endl;
    amount8.set_shills(67); //updates shills_
    cout << amount8 << endl;//prints out object in proper format


    cout << "Constructor with one argument (42.27)" << endl; //print statement
    Sterling amount9(42.27);//create object
    cout << amount9 << endl; //prints out object in proper format
    cout << "Update pence to 31, and adjust numbers" << endl;
    amount9.set_pence(31); //updates pence
    cout << amount9 << endl; //prints out object in proper format


    //Testing == operator
    Sterling amount10(9, 4, 7);//create object
    Sterling amount11(9, 4, 7);//create object
    cout << "Create two objects: " << endl;  //print statement
    cout << amount10 << endl; //prints out object in proper format
    cout << amount11 << endl; //prints out object in proper format

    //compares two objects
    if(amount10 == amount11){
        cout << "object1 and object2 are equal." << endl;
    }
    else{
        cout << "object1 and object2 are not equal." << endl;
    }

    //testing != operator
    Sterling amount12(9, 4, 7);//create object
    Sterling amount13(12, 4, 2);//create object
    cout << "Create two objects: " << endl; //print statement
    cout << amount12 << endl; //prints out object in proper format
    cout << amount13 << endl;//prints out object in proper format

    //compares two objects
    if(amount12 != amount13){
        cout << "object1 and object2 are not equal." << endl;
    }
    else{
        cout << "object1 and object2 are equal." << endl;
    }

    cout << "Constructor with one argument (12.27)" << endl; //print statement
    Sterling amount14(12.27);//create object
    cout << amount14 << endl; //prints out object in proper format
    cout << "Using decimal_pound() operator " << amount14.decimal_pound() << endl; //converts decimal to pounds

    //Testing + operator
    cout << "\nCreate two objects:" << endl; //print statement
    Sterling amount15(33.15);//create object
    Sterling amount16(6.21);//create object
    cout << amount15 << endl; //prints out object in proper format
    cout << amount16 << endl; //prints out object in proper format
    Sterling amount17 = amount15 + amount16; //adds two objects
    cout << "The sum of object1 + object2 = " << amount17.decimal_pound() << endl; //converts sum to decimal

    //Testing - operator
    cout << endl << endl;
    cout << amount15 << endl; //prints out object in proper format
    cout << amount16 << endl; //prints out object in proper format
    Sterling amount18 = amount15 - amount16; //subtracts two objects
    cout << "The difference of obj1 - obj2 = " << amount18.decimal_pound() << endl; //converts difference to decimal



    return 0;
}
