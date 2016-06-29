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
    int i, num, argc_start, max, min;
    char s[BUFSIZE+1];
    Roman_arabic* pRoman;

    Roman_arabic standard[17]={
        {"ↂ ", 10000},
        {"Mↂ ", 9000},
        {"ↁ", 5000},
        {"Mↁ", 4000},
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

    Roman_arabic not_94[9]={
        {"ↂ ", 10000},
        {"ↁ", 5000},
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1}
    };

    Roman_arabic not_5[5]={
        {"ↂ ", 10000},
        {"M", 1000},
        {"C", 100},
        {"X", 10},
        {"I", 1}
    }; 


    pRoman = standard;
    argc_start = 2;
    max = MAX;
    min = MIN;
    if(argc >= 2){
    if(!strcmp(argv[1], "-n94")){
        pRoman = not_94;
        argc_start = 3;
        max = MAX94;
    }
    if(!strcmp(argv[1], "-n5")){
        pRoman = not_5;
        argc_start = 3;
        max = MAX5;
    }
    }


    if(!isatty(fileno(stdin))){
        //標準入力がある場合
        while(1){
            fscanf(stdin, "%s", s); //標準入力を文字列sに代入する
            if(feof(stdin)) break; //標準入力が終了したらループを抜ける
            if(rcheck(s, max, min))continue; // 入力値が異常だと、ループを初めからにする
            num = atoi(s);
            rtrans_print(num, pRoman);
        }
        return 0;

    }else{
        //標準入力がない場合

        //プログラム実行時に引数があった場合
        if(argc >= argc_start){
            for(i=argc_start-1; i<argc; i++){
                if(rcheck(argv[i], max, min))continue; //入力値が異常だと、ループを初めからにする
                num = atoi(argv[i]);
                rtrans_print(num, pRoman);  //与えた整数をローマ数字に変換し、標準出力する
            }
            return 0;
        }

        //プログラム実行時に引数がなかった場合
        while(1){
            printf("---------------\n" );
            printf("アラビア数字を入力してください(qで終了)\n");
            scanf("%" XSTR(MAX) "s%*[^\n]%*c", s);  //バッファオーバーランを防ぐ
            if(s[0]=='q')exit(0);  //'q'で終了
            if(rcheck(s, max, min))continue; //入力値が異常だと、ループを初めからにする
            num = atoi(s);
            rtrans_print(num, pRoman);  //与えた整数をローマ数字に変換し、標準出力する
        }

        return 0;
    }

    return 0;
}
