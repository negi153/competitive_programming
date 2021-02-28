
#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define clr(a,b) memset(a,b,sizeof(a))// a is vector,array and b can be only 0 and -1
#define fd(i,a,b) for(ll i=a;i<=b;i++)
#define fs(i,n) for(ll i=0;i<n;i++)
#define se second
#define fi first
#define vi vector<ll>
#define pb push_back
#define pi pair<ll,ll>
#define umap unordered_map<ll,ll>
#define uset unordered_set<ll>
#define mset multiset<ll>
#define mmap multimap<ll,ll>
#define all(v) v.begin(),v.end()
#define MOD int(1e9+7)
#define maxx int(1e7+1)
#define tr(it,a) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define largest(a,b,c) (a>b?(a>c? a:c):(b>c? b:c))
#define smallest(a,b,c) (a<b?(a<c? a:c):(b<c? b:c))

using namespace std;

ll power(ll a,ll b){ // a^b in log n -- binary exponantiation

ll ans=1;
while(b>0){
    if(b&1==1)
        ans=ans*a;

    a=a*a;
    b=b>>1;
}

return ans;
}


ll powerMod(ll a,ll b){ //(a^b)%MOD in log n

ll ans=1;
a=a%MOD;

while(b>0){
    if(b&1==1)
        ans=(ans*a)%MOD;

    a=(a*a)%MOD;
    b=b>>1;
}

return ans;
}


ll p[maxx];
vi prime;

void soe(){//sieve of eratosthene in nlog log n

for(ll i=2;i<maxx;i++){

    if(p[i]==0){
        p[i]=i;
        prime.push_back(i);
        for(ll j=2*i;j<maxx;j+=i)
            p[j]=i;
    }
}

}


ll EulerTotientFunction(ll n){//it will give count of numbers which are less than N and >=1 and gcd(N,x)=1 
//or count of numbers which are co prime to N 
        ll ans=n;
        fd(i,2,int(sqrt(n))){
            
            if(n%i==0){
                ans/=i;
                ans*=(i-1);
                while(n%i==0){
                    n/=i;
                }
            }

        }
        if(n>1){
            ans/=n;
            ans*=(n-1);
        }
        return ans;
}

ll countFactors(ll n){

    ll c=0;
    fd(i,1,int(sqrt(n))){
        if(n%i==0){
            if(i*i==n)
                c++;
            else
                c+=2;
        }
    }

    return c;
}

ll phi[4000001];

void EulerUptoN(){//euler totient function upto N by sieve of eratosthene
        
        ll maxy=4000000;

        fd(i,1,maxy){
            phi[i]=i;
        }


        fd(i,2,maxy){
            if(phi[i]==i){//i is prime 
                phi[i]=i-1;
                for(ll j=2*i;j<=maxy;j+=i){
                    phi[j]=(phi[j]*(i-1))/i;
                }
            }
        }
}


int main(){

    fastio;

    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif


    ll t;
    cin>>t;

    while(t--){
        
            
        
    }



return 0;
}

