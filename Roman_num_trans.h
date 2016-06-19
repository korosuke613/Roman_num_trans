/*--
 * Roman_num_transのヘッダファイルです。
 * Roman_num_trans.h
 --*/

#ifndef _ROMAN_NUM_TRANS_H_
#define _ROMAN_NUM_TRANS_H_

//プリプロセッサ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256 //文字列の最大値
#define MAX 3999 //ローマ数字の最大値
#define MIN 1 //ローマ数字の最小値

#define ER_NO_INT "ERR:数字以外が入力されました\n"
#define ER_REMITES_OVER "ERR:ローマ数字は1~3999までの数字しか扱えません\n"

//scanfの第一引数にプリプロセッサを適用するための設定
#define  STR(s)  #s
#define  XSTR(s)  STR(s)

//構造体宣言
struct roman_arabic { //ローマ数字とアラビア数字の変換表の構造体
    char roman[3];  /* ローマ数字 */
        int arabic;  /* アラビア数字 */
};

//プロトタイプ宣言
int rcheck(char* str);
void rtrans_print(int num, struct roman_arabic* a);

#endif //_ROMAN_NUM_TRANS_H_
