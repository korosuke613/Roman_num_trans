#Makefile

# プログラム名とオブジェクトファイル名
program = roman
obj = main.o rcheck.o rtrans_print.o

# 定義済マクロの再定義
CC = gcc
CFLAGS = -g -W -Wall

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

# プライマリターゲット
$(program): $(obj)
	$(CC) -o $(program) $^
	$(RM) $(obj)

# サフィックスルール
.c.o:
	$(CC) $(CFLAGS) -c $<

# ファイル削除用ターゲット
.PHONY: clean
clean:
	$(RM) $(program) $(obj)

# ヘッダーファイルの依存関係
main.o: Roman_num_trans.h
rcheck.o: Roman_num_trans.h
rtrans_print.o: Roman_num_trans.h