#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int res = 0;
    while(x != 0){
        int temp = x % 10;
        x /= 10;
        if(res > 2147483647 / 10 || (res == 2147483647 / 10 && temp > 7)) return 0;
        if(res < -2147483648 / 10 || (res == -2147483648 / 10 && temp < -8)) return 0;
        res = res * 10 + temp;
    }
    return res;
}