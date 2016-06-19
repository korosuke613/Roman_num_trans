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

    if(!isatty(fileno(stdin))){
        //標準入力がある場合
        while(1){
            fscanf(stdin, "%s", s); //標準入力を文字列sに代入する
            if(feof(stdin)) break; //標準入力が終了したらループを抜ける
            if(rcheck(s))continue; // 入力値が異常だと、ループを初めからにする
            num = atoi(s);
            rtrans_print(num, b);
        }
        return 0;

    }else{
        //標準入力がない場合

        //プログラム実行時に引数があった場合
        if(argc >= 2){
            for(i=1; i<argc; i++){
                if(rcheck(argv[i]))continue; //入力値が異常だと、ループを初めからにする
                    num = atoi(argv[i]);
                rtrans_print(num, b);  //与えた整数をローマ数字に変換し、標準出力する
            }
            return 0;
        }

        //プログラム実行時に引数がなかった場合
        while(1){
            printf("---------------\n" );
            printf("アラビア数字を入力してください(qで終了)\n");
            scanf("%" XSTR(MAX) "s%*[^\n]%*c", s);  //バッファオーバーランを防ぐ
            if(s[0]=='q')exit(0);  //'q'で終了
            if(rcheck(s))continue; //入力値が異常だと、ループを初めからにする
            num = atoi(s);
            rtrans_print(num, b);  //与えた整数をローマ数字に変換し、標準出力する
        }

        return 0;
    }

    return 0;
}
