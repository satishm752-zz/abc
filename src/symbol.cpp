#include <bits/stdc++.h>
using namespace std;

struct symbolTable
{
	/* data */
	string name;
	int type;
	int scope;
	string dim;
	int proc_def;
};

multimap<string,symbolTable> st;
typedef multimap<string, symbolTable>::iterator stit;
typedef pair< stit, stit > rangeit;

void insert(char *n, int type, int scope,char* d, int proc_def)
{
	string name(n);
    string dim(d);
	struct symbolTable sym;
	sym.name = name;
	sym.type = type;
	sym.scope = scope;
	sym.dim = dim;
	sym.proc_def = proc_def;
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
		cout<<"  "<<s.name<<"  ";
		if(s.type==266)
			cout<<"int";
		else
			if(s.type==267)
				cout<<"float";
			else
				if(s.type==265)
					cout<<"struct";
		
		cout<<"  "<<s.scope<<"  "<<s.dim<<" "<<s.proc_def;
		cout<<endl;
	}
	return;
}
