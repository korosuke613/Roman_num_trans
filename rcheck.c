#include "Roman_num_trans.h"

/**
 * ローマ数字に変換できるかチェックして、警告する関数
 * rcheck
 * 返り値 正常:0, 異常:1
 * 引数 評価する文字列
 **/
int rcheck(char* str){
    int i=0, frag = 0;

    while (*(str+i) != '\0') {
        if(*(str+i) < '0' || *(str+i) > '9')frag = 1;
        i++;
    }
    if(frag) {
        printf(ER_NO_INT);
        return 1;
    }
    if(atoi(str) > MAX || atoi(str) < MIN){
        printf(ER_REMITES_OVER);
        return 1;
    }
    return 0;
}
