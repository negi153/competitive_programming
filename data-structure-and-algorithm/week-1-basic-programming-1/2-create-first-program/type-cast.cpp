#include<iostream>

using namespace std;

int main(){


    char ch = 97; // implicit type conversion
    cout<<ch<<endl; // it will print alphabet "a". as it typecasted integer to character

    int num = 'b';// implicit type conversion
    cout<<num<<endl; //it will print 98 as it has converted character b to ASCII 98

    float a = (float) 2; // explicit type conversion. converting integer to float

    cout<<3/5; // gives integer
    cout<<3.0/5; // gives float
    cout<<5/2.0; //gives float

    return 0;
}