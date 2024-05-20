#include <vector>
#include <map> 
using namespace std;

int solve(vector<int> &A, int B) {
    int cnt = 0;
    map<int,int> m;
    int x = 0;
    m[0]++;
    for(int i = 0; i< A.size(); i++)
    {
        x = x^A[i];
        int xr = x^B;
        cnt += m[xr];
        m[x]++;
    }
    return cnt;
}
