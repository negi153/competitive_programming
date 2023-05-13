#include <iostream>
using namespace std;

void solve(int arr[]) {
        cout <<"Size inside solve function " << sizeof(arr) << endl;
        cout <<"arr: " << arr << endl;
        cout << "&arr: " << & arr << endl;

        arr[0] = 50;
}

void update(int *p) {
        cout << "Address stored inside p is: " << p << endl;
        cout << "Address of p  is:" << &p << endl;
        *p = *p + 10;
}

int main() {

        //int arr[4] = {12,44,66,18};

        // cout << arr << endl; // base address of array
        // cout << arr[0] << endl;  // 12
        // cout << &arr << endl; //base address of array --> exception in array
        // cout << &arr[0] << endl; // // base address of array
        
        // ------------------------------------------
        // int* p = arr;
        // cout << p << endl; // gives address stored in pointer
        // cout << &p << endl; // gives address of pointer 
        // ------------------------------------------

        // cout << *arr << endl; // gives a[0] --> dereference operator
        // cout << arr[0] << endl; // a[0]
        // cout << *arr + 1 << endl; // a[0] + 1
        // cout << *(arr) + 1 << endl; // a[0] + 1
        // cout << *(arr + 1) << endl; // gives a[1]
        // cout << arr[1] << endl; // a[1]
        // cout << *(arr + 2) << endl; // a[2]
        // cout << arr[2] << endl; // a[2]
        // cout << *(arr + 3) << endl; // a[3]
        // cout << arr[3] << endl; // a[3]
        // ------------------------------------------

        // int i = 0;
        // cout << arr[i] << endl; // gives a[i] --> resolve --> *(arr + i)
        // cout << i[arr] << endl; // also gives a[1] --> *(i + arr)
        // cout << *(arr + i) << endl; // a[i]
        // cout << *(i + arr) << endl; // a[i]


        // NOTE --> arr is the pointer to the first location of the array
        // NOTE --> Array expression arr[i] --> gets converted into *(arr + i)
        // NOTE --> array expression i[arr] --> gets converted into *(i + arr)
        // ------------------------------------------

        // //arr = arr + 2; //--> ERROR --> we are trying to update the array base address 
        //which will not happen because we can not change entry present in symbol table and will give error .
        // in case of array, symbol table contains a mapping between arr and base address

        // ------------------------------------------


        // // int* p = arr;
        // // p = p + 2; // this we can do with pointer, because p contains the address 

        // ------------------------------------------

        // // int arr[10];
        // // cout << sizeof(arr) << endl; //gives total size of array or space take by array -->  array has 10 elements of integer type. integer takes 4 bytes-> so size of array will be 40 bytes

        // // int* p = arr; // pointer p stores the base address of array 
        // // cout << sizeof(p) << endl; // size of pointer is always 8 bytes in 64 bit system and 4 bytes in 32 bit system.

        // // cout << sizeof(*p) << endl; // size of arr[0] --> that is an integer whieh is 4 bytes
        // ------------------------------------------

        // // char ch[10] = "Babbar";
        // // char* c = ch;

        // cout << ch << endl; // technically it should give base address of ch, but it prints "Babbar", because cout implementation is different for characters
        // cout << &ch << endl;
        // cout << ch[0] << endl;

        // // cout << &c << endl;
        // // cout << *c << endl;
        // // cout << c << endl;

        // char name[9] = "SherBano";
        // char* c = &name[0];

        // cout << name << endl;
        // cout << &name << endl;
        // cout << *(name + 3) << endl;
        // cout << c << endl;
        // cout << &c << endl;
        // cout << *(c + 3) << endl;
        // cout << c+2 << endl;
        // cout << *c << endl;
        // cout << c+8 << endl; 

        // char ch = 'k';
        // // char* cptr = &ch;

        // // cout << cptr << endl;

        // // char name[10] = "babbar";
        // // cout << name << endl;

        // // char* c = "babbar";
        // // cout << c << endl;


        // int arr[10] = {1,2,3,4};
        // cout << "Size inside main function. " << sizeof(arr) << endl;
        // cout << arr << endl;
        // cout << &arr << endl;

        // //printing array inside main
        // for(int i=0; i<10; i++) {
        //         cout << arr[i] << " ";
        // }cout << endl;
        // cout << endl << endl << "Now calling solve function" << endl;

        // solve(arr);

        // cout << "Wapas main function me aagye h " << endl;

        // for(int i=0; i<10; i++) {
        //         cout << arr[i] << " ";
        // }cout << endl;

        int a = 5;
        cout << "Address of a is: " << &a << endl;
        int* ptr = &a;
        cout << "address stored in ptr is: " << ptr << endl;
        cout << "Address of ptr is: " << &ptr << endl;
        update(ptr);
        cout<<"value of a is: " << a << endl;



        return 0;
}