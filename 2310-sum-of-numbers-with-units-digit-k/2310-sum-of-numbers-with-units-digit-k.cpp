class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(num<k) return -1;
        int unit=num%10;
        for(int i=1;i<=10;i++){
            if((k*i)%10==unit){
                if(k*i>num) return -1;
                return i;
            }
        }
        return -1;
    }
};