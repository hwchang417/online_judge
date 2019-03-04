class Solution {
public:
    void splitComplex(string in, int* real, int* imag){
        int index = 0, neg_real = 1, neg_imag = 1, size;
        size = in.size();
        
        if(in[index] == '-') neg_real = -1, index++;
        //for real part
        while(in[index] != '+')
            *real = (*real << 3) + (*real << 1) + in[index++] - '0';
        
        if(in[++index] == '-') neg_imag = -1, index++;
        
        while(in[index] != 'i')
            *imag = (*imag << 3) + (*imag << 1) + in[index++] - '0';
        
        *real = neg_real * *real;
        *imag = neg_imag * *imag;
    }
    
    string complexNumberMultiply(string a, string b) {
        int real, imag, real1, real2, imag1, imag2;
        string res;
        char buf[32];
            
        real1 = real2 = imag1 = imag2 = 0;
        
        splitComplex(a, &real1, &imag1);
        splitComplex(b, &real2, &imag2);
        
        real = real1 * real2 - imag1 * imag2;
        imag = real1 * imag2 + real2 * imag1;
        
        sprintf(buf, "%d+%di", real, imag);
        res = buf;
        return res;
    }
};