#include <iostream>
#include <vector>

using namespace std;
float dot_product(vector<float> vec1, vector<float> vec2)
{
    if(vec1.size() != vec2.size()) {return 0;}
    else{
        float result = 0;
        for(int i=0;i<vec2.size();++i)
        {
            result=result + vec1[i] * vec2[i];
        }
        return result;
    }
}
auto main() -> int
{
    vector<float> a={1,2,3};
    vector<float> b={4,5,6};
    cout << dot_product(a,b) << endl;
    return 0;
}
