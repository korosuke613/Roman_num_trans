/**
 * Roman_num_transのヘッダファイルです。
 * Roman_num_trans.h
 **/

#ifndef _ROMAN_NUM_TRANS_H_
#define _ROMAN_NUM_TRANS_H_

/* プリプロセッサ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 128 //文字列の最大値
#define MAX 39999 //ローマ数字の最大値
#define MAX94 49999
#define MAX5 99999
#define MIN 1 //ローマ数字の最小値

//メッセージ関連
#define ER_NO_INT printf("ERR:数字以外が入力されました\n");
#define ER_REMITES_OVER(min,max) printf("ERR:ローマ数字は%d~%dまでの数字しか扱えません\n", min, max);
#define VERMSG printf("Roman_num_trans ver.2.0\n");
#define USAGE(program_name) printf("usage: %s [-f] [-g]\n", program_name);

//scanfの第一引数にプリプロセッサを適用するための設定
#define  STR(s)  #s
#define  XSTR(s)  STR(s)


/* 構造体宣言 */
typedef struct { //ローマ数字とアラビア数字の変換表の構造体
    char roman[5];  /* ローマ数字 */
    int arabic;  /* アラビア数字 */
}Roman_arabic;


/* プロトタイプ宣言 */
int rcheck(char* str, int max, int min);
void rtrans_print(int num, Roman_arabic* a);

#endif //_ROMAN_NUM_TRANS_H_
