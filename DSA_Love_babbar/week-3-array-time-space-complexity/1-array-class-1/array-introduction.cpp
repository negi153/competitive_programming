#include <iostream>
using namespace std;

void printArray(int a[], int size){
  for(int i=0;i<size;i++) cout<<a[i]<<" ";
  cout<<endl;
}

void increment(int a[],int size){
  a[0]=a[0]+10;
  cout<<"Array inside function -";
  printArray(a,size);
}

int main() {

  // array declaration
  int a[5]; // create a continuous block of memory -> total memory 5*4 = 20 bytes
  cout<<"memory of array -"<<a<<endl;
  cout<<"memory of array -"<<&a<<endl;
  
  // it will have garbage value
  for(int i=0;i<5;i++) cout<<a[i]<<" ";

  //array initialisation
  int b[4]={4,5,6,3};
  cout<<b[0]<<endl;
  cout<<b[2]<<endl;

  char c[]={'a','c','d'};
  cout<<c[0]<<" "<<c[2]<<endl;

  int d[4]={1,2}; // array size is 4, but initialised only 2 elements, then other elements will be zero
  cout<<d[3]<<endl;

  // int e[2]={1,2,3,4}; // it will fail as we have given size only 2 and elemntes are more

  // BAD PRACTICE - below might work in some compiler and might not in some. 
  // int n=4;
  // int k[n]; 

  // int arr[]={4,3,5,6};

  // find address of any element -> base_address + index * datatype_size
  // arr[2] = value at (arr + 2*4) --> it gives the address where index 2 element is present

  int n;
  cin>>n;
  int arr[1000];
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<"double of numbers - ";
  for(int i=0;i<n;i++) cout<<2*a[i]<<" ";
  cout<<endl;


  /// Array and function->

  int p[]={3,4,2,5};

  cout<<"Array before increment -";
  printArray(p,4);
  increment(p,4); // this funciton made changes in main array, so array follows pass by reference

  cout<<"Array after increment, in main function -";
  printArray(p,4); 

  return 0;
}