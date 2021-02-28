//it is used to find all the occurence of pattern in a string with o(n) complexity

#include<iostream>
#include<string>
#include<vector>

using namespace std;


void zalgo(string txt,string pat){

string s=pat+'$'+txt;
int n=s.length();

//important part start
vector<int> z(n);
z[0]=0;

int l=0,r=0;

for(int i=1;i<n;i++){
    if(i>r){
        l=r=i;
        while(r<n && s[r-l]==s[r])
            r++;

        z[i]=r-l;
        r--;
    }
    else{
        int k=i-l;

        if(z[k]<r-i+1) //or if(z[k]+i<r)
            z[i]=z[k];
        else{
            l=i;
            while(r<n && s[r-l]==s[r])
                r++;

            z[i]=r-l;
            r--;
        }
    }
}

//important part end


for(int i=0;i<z.size();i++){
    if(z[i]==pat.length())
        cout<<"pattern found at "<<i-pat.length()-1<<endl;
        }

}

int main(){
string txt,pat;
cout<<"enter text : ";
cin>>txt;
cout<<"enter pattern :";
cin>>pat;

zalgo(txt,pat);

return 0;
}
