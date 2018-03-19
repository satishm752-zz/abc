#include <bits/stdc++.h>
using namespace std;

struct symbolTable
{
	/* data */
	string name;
	int type;
	int scope;
	int dim;
	int other;
};

multimap<string,symbolTable> st;
typedef multimap<string, symbolTable>::iterator stit;
typedef pair< stit, stit > rangeit;

void insert(char *n, int type, int scope,int dim, int other)
{
	string name(n);
	struct symbolTable sym;
	sym.name = name;
	sym.type = type;
	sym.scope = scope;
	sym.dim = dim;
	sym.other = other;
	st.insert(make_pair(name, sym));
	return;
}


void delete1(char *n)
{
	string name(n);
	map<string,symbolTable>::iterator it;
	if(st.find(n)!=st.end())
	{	
		it=st.find(n);
		st.erase(it);
	}
	return;
}

void clearsym()
{
	st.clear();
	return;
}

void printsym()
{
	stit it;
	struct symbolTable s;
	for(it=st.begin();it!=st.end();++it)
	{
		s=it->second;
		cout<<"  "<<s.name<<"  "<<s.type<<"  "<<s.scope<<"  "<<s.dim<<" "<<s.other;
		cout<<endl;
	}
	return;
}
