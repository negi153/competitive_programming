#include <iostream>
using namespace std;

int main() {
//   int a = 5;
//   int b = 5;

//   cout << a << endl;

//   cout << &a << endl;
//   cout << &b << endl;

        // int a = 5;
        // //pointer create
        // int* ptr = &a;

        // //access the value ptr is pointing to
        // cout << "Address of a is: " << &a << endl;
        // cout <<"value stored at ptr is: " << ptr << endl;
        // cout <<"value ptr is pointing to is: " << *ptr << endl;
        // cout << &ptr << endl;

        // int a = 5;
        // int* p = &a ;

        // cout <<sizeof(p) << endl;

        // char ch = 'b';
        // char* c = &ch ;

        // cout <<sizeof(c) << endl;

        // double dtr = 5.03;
        // double* d = &dtr ;

        // cout <<sizeof(d) << endl;  // always will be fix for int/double etc...

        //-------------------------
        //BAD PRACTICE
        // int* ptr;

        // cout << *ptr << endl; // ptr will contain garbage, and we are trying to access the garbage memory which doesn't exits or which is not alloted to program, so it will give segmentation fault.
        // we can't compare above as we don't know the garbage value 
        //-------------------------

        //NULL POINTER
        // int* ptr = 0; /// it will create a null pointer

        // cout << *ptr << endl; // will give error
        
        // if(ptr == 0) cout<<"yes";  // but now we know what is present inside ptr, so we can compare
        
        //-------------------------
        
        // int a = 5;
       // int* ptr = a; //error-- cant convert int to int*
        // int* ptr = &a;

        // //copy pointer
        // int* dusraPtr = ptr;

        // cout << *ptr << endl;
        // cout << *dusraPtr << endl;
 

        int a = 10;
        int* p = &a;
        int* q = p;
        int* r = q;

        cout << a << endl; //10
        cout << &a << endl; //address of a 
        cout << p << endl; //address of a 
        cout << &p << endl; //address of p
        cout << *p << endl; //10
        cout << q << endl; //address of a
        cout << &q << endl; //address of q
        cout << *q << endl; //10
        cout << r << endl; //address of a
        cout << &r << endl; //address of r
        cout << *r << endl; //10
        cout << (*p + *q + *r) << endl; //30
        cout << (*p)*2 + (*r)*3 << endl; //50
        cout << (*p/2) - (*q)/2 << endl; //0


  




  return 0;
}