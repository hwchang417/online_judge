
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int i, j, k, l;
        string res, empty;
        int count[10] = {0};
        
        for(int n : A)
            count[n]++;
        
        for(i = 2;i >= 0;i--){
            if(count[i]){
                count[i]--;
                if(i == 2){
                    for(j = 3;j >= 0;j--){
                        if(count[j]){
                            count[j]--;
                            for(k = 5;k >= 0;k--){
                                if(count[k]){
                                    count[k]--;
                                    for(l = 9;l >= 0;l--){
                                        if(count[l]){
                                            res += i + '0';
                                            res += j + '0';
                                            res += ':';
                                            res += k + '0';
                                            res += l + '0';
                                            return res;
                                        }
                                    }
                                    count[k]++;
                                }
                            }
                            count[j]++;
                        }
                    }
                }else{
                    for(j = 9;j >= 0;j--){
                        if(count[j]){
                            count[j]--;
                            for(k = 5;k >= 0;k--){
                                if(count[k]){
                                    count[k]--;
                                    for(l = 9;l >= 0;l--){
                                        if(count[l]){
                                            res += i + '0';
                                            res += j + '0';
                                            res += ':';
                                            res += k + '0';
                                            res += l + '0';
                                            return res;
                                        }
                                    }
                                    count[k]++;
                                }
                            }
                            count[j]++;
                        }
                    }
                }
                count[i]++;
            }
        }
        
        return res;
    }
};