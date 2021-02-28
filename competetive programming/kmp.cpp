//this algo is used to find the pattern in text with worst case complexlity o(n+m)

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix_function(string z){

    int n=z.length();
    vector<int> f(n);
    f[0]=0;

    for(int i=1;i<n;i++){
        int j=f[i-1];
        while(j>0 && z[i]!=z[j])
            j=f[j-1];

        if(z[i]==z[j])
            j++;

        f[i]=j;

    }
return f;
}

void kmp(string txt,string pat){

vector<int> f=prefix_function(pat);

int n=txt.length();
int m=pat.length();
int i=0;//index for txt
int j=0;//index for pat
while(i<n){
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }

        if(j==m){
            cout<<"pattern found at "<<i-j<<endl;
            j=f[j-1];
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0)
                j=f[j-1];
            else
                i++;
        }


}

}

int main(){
string txt,pat;
cout<<"enter string :";
cin>>txt;
cout<<"enter pattern :";
cin>>pat;

kmp(txt,pat);

return 0;
}
