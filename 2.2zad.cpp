#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool filter_palindromes(string s)
{
    string temp;
for(int i=s.size()-1;i>=0;--i)
{
    temp=temp+s[i];
}
if(s==temp) return true;
else return false;
}
vector<string>palfil(vector<string> slowy, int minLength){
    minLength=3;
    vector<string>result;
    for(auto i : slowy)
    {
        if(i.size()>=minLength)
        {
            if(filter_palindromes(i))
                result.push_back(i);
        }
    }
    return result;
}
int main()
{
    vector<string>vec={"idoodi","asdsf","safqrwqf","asdasdasfq","tattat","bba"};
    vector<string>a;
    a= palfil(vec,1);
    for(auto i:a){
        cout << i << endl;
    }
}
    
    
