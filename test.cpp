#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <immintrin.h>
using namespace std;
typedef unsigned int u32;
typedef unsigned long long u64;
void out(int x)
{
    x^=(1<<31);
    
    for (int i=0; i<=24; i+=8)
    {
    //    cout<<((x>>i)&255)<<endl;
    }
    unsigned int y = x;
    cout<<(unsigned int) y<<endl;
}
int main() {
    out(0);
    out(-1);
    out(-2147483648);
    out(2147483647);
    out(729724258^(1<<31));


    int32_t a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[8] = {2, 1, 4, 3, 6, 5, 8, 7};
    int32_t *pa = a;
    for (int i=0; i<8; i++) pa[i] = i;
    cerr<<"ok"<<endl;
    __m256i regb = _mm256_load_si256((__m256i*)a);
    return 0;
}