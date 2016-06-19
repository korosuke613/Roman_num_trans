/**
 * アラビア数字をローマ数字に変換するプログラムです。
 * roman_trans.c
 **/

#include "Roman_num_trans.h"

/**
 * メイン関数
 * main.c
 **/
int main(int argc, char* argv[])
{
    int i, num;
    char s[BUFSIZE+1];
    struct roman_arabic b[13]={
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
    };

    return 0;
}
