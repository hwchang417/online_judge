int maxArea(int* height, int heightSize) {
    int w;
    int max_area = 0, tmp;
    int l = 0, r = heightSize - 1;
    int lh = height[l], rh = height[r];
    
    while(l < r){
        //calculate area
        tmp = (lh > rh ? rh : lh) * (r - l);
        if(tmp > max_area){
            max_area = tmp;
        }
        if(lh > rh){
            r--;
            rh = height[r];
        }else{
            l++;
            lh = height[l];
        }
    }

    return max_area;
}