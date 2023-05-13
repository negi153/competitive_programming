#include<bits/stdc++.h>
using namespace std;


int prec(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}

void infixToPostfix(int &n,string &s)
{
	stack<char> st;
	st.push('N');

	string ns;
	for(int i = 0; i < n; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		ns+=s[i];

		else if(s[i] == '(')

		st.push('(');


		else if(s[i] == ')')
		{
			while(st.top() != 'N' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
			ns += c;
			}
			if(st.top() == '(')
			{
				st.pop();
			}
		}

		else{
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}

	}
	while(st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns += c;
	}

	cout << ns << endl;

}

int main()
{
	int t,n;
	string s;
	cin>>t;
	while(t--){
        cin>>n;
        cin>>s;
        infixToPostfix(n,s);
	}

	return 0;
}

