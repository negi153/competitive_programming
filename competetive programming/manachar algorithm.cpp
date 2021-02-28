//It is used to find the Longest Palindromic Sub-string in any string. time complexity-o(n)

#include<iostream>
#include<string>
#define SIZE 100001
using namespace std;

int p[SIZE * 2];


string convertstring(string s){

string news="@";
for(int i=0;i<s.length();i++){
    news=news+"#"+s[i];
}

news=news+"#$";

return news;
}

string manachar(string s){

string q=convertstring(s);
int c=0,r=0;//current center,right limit

for(int i=1;i<q.length()-1;i++){
    int imirror=2*c-1;//find the corresponding letter in the palindrome substring

    if(r>i)
        p[i]=min(r-i,p[imirror]);


    //expanding around centre i
    while(q[i+1+p[i]]==q[i-1-p[i]])
        p[i]++;

    //updating c,r in case if the palindrome centered at i expands past r,
    if(i+p[i]>r){
        c=i; //next center =i
        r=i+p[i];
    }

}

//find the longest palindrome length in p

int maxpalindrome=0;
int centerindex=0;

for(int i=1;i<q.length()-1;i++){
    if(p[i]>maxpalindrome){
        maxpalindrome=p[i];
        centerindex=i;
    }
}

cout<<maxpalindrome<<endl;

return s.substr((centerindex-1-maxpalindrome)/2,maxpalindrome);


}

int main(){
string s="czcaba";


cout<<manachar(s);

return 0;
}
