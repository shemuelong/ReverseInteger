#include <iostream>
#include "LStack.h"
using namespace std;


int main(){

    int y, counter = 0;
    LStack<int> number;
    LStack<int> finalNumber;

    std::cout << "Type in your number: ";
    std::cin >> y;
    while (y > 0){
        number.push(y%10); //We store each digit of the integer y inside the Stack with the name number.
                           //(Side Note) If we were to cout << "y%10"; it would actually be the reverse of our integer y.
                           //But to utilize the LStack and pop() function we will declare two stacks.
        y /= 10;           //As we store one digit of y, we make it smaller by a factor of 10.
        counter++;         //This counter tells us how many digits were stored in the stack
    }

    for(int i = 0; i < counter; i++){
        //Currently, the numbers are stored in the stack in reverse order of the original y. If we were to pop() from the Stack "number," the digits would come out as originally typed
        finalNumber.push(number.pop()); //We store the digits in "number" in reverse order.
                                        //First we pop() the digit from "number"
                                        //Then we push() the output to "finalNumber"
    }

    for(int i = 0; i < counter; i++){
        //At this point, the digits of the initial number are stored in original order in the Stack "finalNumber."
        std::cout << finalNumber.pop(); //Simply using the pop() function will output the number in reversed order
    }
    
    return 0;
}
