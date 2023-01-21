#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace Vector
{
    class vector
    {
        public:
            /*Default constructor.
            Initialize sz to 0, space to 0, and arr to nullptr*/
            vector();
            /*Overloaded constructor.
            Initialize sz to n, space to n, and arr to a new array of size n
            initialize each element to 0*/
            vector(int n);
            //destructor.  Delete the array.  Nothing needs to be done here.
            ~vector(){delete[] arr;}
            //Return the value of the array element at the given index
            int get(int i) const;
            //Set the value of the array at the given index
            void set(int i, int x);
            //Return the number of elements
            int size();
            //Return the space allocated for the array
            int capacity();
            /*Push an element to the end of the array:
            if sz == 0, reserve 1
            else if sz == space, reserve 2 * space
            assign x to the end of the array.
            increment sz*/
            void push_back(int x);

            /*Increase the allocated memory space for the array:
            allocate a temporary int array of size n
            copy the values of arr into temp with a loop
            deallocate arr.  This prevents a memory leak.
            assign temp to arr.
            assign n to space*/
            void reserve(int n);
        private:
            int sz;
            int space;
            int *arr;
    };
}

#endif // VECTOR_H_INCLUDED
