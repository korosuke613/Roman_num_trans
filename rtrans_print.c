#include "Roman_num_trans.h"

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
