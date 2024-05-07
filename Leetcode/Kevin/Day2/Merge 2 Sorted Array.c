// Link: https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    vector<int> ans;
    int f=0, s=0;
    while(f < a.size() && s < b.size())
    {

      if (ans.size()&&ans.back() == a[f]) {
        f++;
        continue;
      }
      if (ans.size() && ans.back() == b[s]) {
        s++;
        continue;
      }

        if(a[f] < b[s] ){
            ans.push_back(a[f++]);
        }
        else   
            ans.push_back(b[s++]);
    }

    while (f < a.size()) {
         if (ans.size()&&ans.back() == a[f]) {
        f++;
        continue;
      }
      

        ans.push_back(a[f++]);
    }
    while (s < b.size()) {
        
      if (ans.size() && ans.back() == b[s]) {
        s++;
        continue;
      }

        ans.push_back(b[s++]);
    }
    return ans;

}