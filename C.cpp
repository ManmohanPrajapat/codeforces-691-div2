#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define int long long int
#define float long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX_SIZE = 1000001; 
set<int>sect;
vector<int>vect;
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
}  
int findGCD() 
{ 
	int result = vect[0];
    int n=vect.size(); 
	for (int i = 1; i < n; i++) 
	{ 
		result = gcd(vect[i], result); 

		if(result == 1) 
		{ 
		return 1; 
		} 
	} 
	return result; 
}
void myfun()
{
    int n,m,x;
    cin>>n>>m;
    int arr[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sect.insert(x);
    }
    for(int i=1;i<=m;i++)
    cin>>arr2[i];
    auto it=sect.begin();
    int val=*it;
    if(sect.size()==1)
    {
        for(int i=1;i<=m;i++)
        cout<<arr2[i]+val<<" ";
        return;
    }
    it++;
    while(it!=sect.end())
    {
        int z=*it;
        vect.push_back(z);
        it++;
    }
    for(int i=0;i<vect.size();i++)
    {
        vect[i]=vect[i]-val;
    }
    int z=findGCD();
    for(int i=1;i<=m;i++)
    {
        int b=arr2[i];
        cout<<gcd(z,b+val)<<" ";
    }
} 
signed main()
{
   fastio
    int t=1;
    // cin>>t;
    while(t--)
        myfun();
}
