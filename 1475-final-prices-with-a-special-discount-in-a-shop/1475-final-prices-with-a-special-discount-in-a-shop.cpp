class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> ans;
        int n=p.size();
        bool f=false;
        int minn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(p[j]<=p[i]){
                    minn=p[j];
                    f=true;
                    break;
                }
            }
            if(f){
                ans.push_back(p[i]-minn);
            }
            else{
                ans.push_back(p[i]);
            }
            f=false;
            minn=0;
        }
        return ans;
    }
};