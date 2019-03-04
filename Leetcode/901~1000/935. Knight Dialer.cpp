class Solution {
public:
    int knightDialer(int N) {
        const long long int modulo = 1000000007;
        int i, j, flag;
        long long int count;
        int *p1, *p2, buf1[10], buf2[10];
        int table[10][4] = {{4, 6, -1},
                            {6, 8, -1},
                            {7, 9, -1},
                            {4, 8, -1},
                            {0, 3, 9, -1},
                            {-1},
                            {0, 1, 7, -1},
                            {2, 6, -1},
                            {1, 3, -1},
                            {2, 4, -1}};
        
        //initialize buf1 and buf2 with all ones and zeros
        p1 = buf2; p2 = buf1;
        for(i = 0;i < 10;i++)
            buf1[i] = 1, buf2[i] = 0;
        
        flag = 0;
        while(N-- > 1){
            if(flag == 0) p1 = buf1, p2 = buf2;
            else p1 = buf2, p2 = buf1;
            flag ^= 1;
            for(i = 0;i < 10;i++)
                for(j = 0;table[i][j] != -1;j++)
                    p2[table[i][j]] = (p2[table[i][j]] + p1[i]) % modulo;
            memset(p1, 0, sizeof(int) * 10);
        }
        
        count = 0;
        for(i = 0;i < 10;i++)
            count += p2[i] % modulo;
        
        return count % modulo;
    }
};