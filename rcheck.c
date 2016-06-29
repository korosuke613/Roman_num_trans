#include "Roman_num_trans.h"

/**
 * ローマ数字に変換できるかチェックして、警告する関数
 * rcheck
 * 返り値 正常:0, 異常:1
 * 引数 評価する文字列, 最大値, 最小値
 **/
int rcheck(char* str, int max, int min){
    int i=0, frag = 0;

    while (*(str+i) != '\0') {
        if(*(str+i) < '0' || *(str+i) > '9')frag = 1;
        i++;
    }
    if(frag) {
        ER_NO_INT; // エラーを標準出力する。
        return 1;
    }
    if(atoi(str) > max || atoi(str) < min){
        ER_REMITES_OVER(min, max); // エラーを標準出力する。
        return 1;
    }
    return 0;
}

/**
 * アラビア数字をローマ数字に変換する手続き
 * rtrans_print
 * 返り値 なし
 * 引数 変換するアラビア数字、変換表
 *_print
 * 返り値 なし
 * 引数 変換するアラビア数字、変換表
 **/
void rtrans_print(int num, Roman_arabic* a){
    int i=0;
    char str[BUFSIZE]="0";

    while(num != 0){
        if(num / a[i].arabic >= 1){
            strcat(str, a[i].roman);
            num -= a[i].arabic;
        }else i++;
    }
    printf("%s\n",str+1);
}
