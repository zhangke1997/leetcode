
#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0)
            return 0;
        if(dividend==INT_MIN && divisor == -1)
            return INT_MAX;
        
        bool flag=(dividend ^ divisor)>0;//抑或去掉符号
/*
        long D=abs(dividend);//负数的边界更大 要仔细考虑
        long M=abs(divisor);
        int final=0;
        for(int i=32;i>=0;i--)
        {
            if((D>>i)>=M)
            {
                final+=(1<<i);
                D-=M<<i;//D=D-d*(2^i)
            
            }
        }
*/
        int D,M;
        if(dividend>0) 
             D=-dividend;
            else D=dividend;
        if(divisor>0) 
             M=-divisor;
            else  M=divisor;
        int final=0;
        for(int i=31;i>=0;i--)
        {
            if(D==M)
            {
                final++;
                break;
            }
            if(D>>i<M)
            {
                final+=(1<<i);
                D-=M<<i;//D=D-d*(2^i)
            
            }
        }

        return flag?final:-final;

        
        
    }
};

int main()
{
    int a=10,b=-3;
    Solution q;
    cout<<q.divide(a,b)<<endl;


    return 0;
}