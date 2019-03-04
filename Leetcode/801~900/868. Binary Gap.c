#define max(a, b) (a > b ? a : b)

int binaryGap(int N) {
    int dis, max_dis;
    int count;
    max_dis = 0;
    dis = 32;
    
    for(count = 0;count < 32 && N != 0;count++){
        if(N & 0x01 == 1){
            max_dis = max(max_dis, count - dis);
            dis = count;
        }
        N >>= 1;
    }
    
    return max_dis;
}