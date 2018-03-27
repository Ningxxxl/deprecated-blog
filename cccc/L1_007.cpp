#include<iostream>
#include<map>
#include<string>
using namespace std;

string s;
map <char, string> m;

int main(void)
{
    cin>>s;

    m['0'] = "ling";
    m['1'] = "yi";
    m['2'] = "er";
    m['3'] = "san";
    m['4'] = "si";
    m['5'] = "wu";
    m['6'] = "liu";
    m['7'] = "qi";
    m['8'] = "ba";
    m['9'] = "jiu";
    m['-'] = "fu";
    

    int len = s.length();

    for(int i = 0; i < len; i++)
    {
        if(i) cout<<" ";
        cout<<m[s[i]];
    }
    cout<<endl;
}