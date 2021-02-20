#!/bin/bash
# hinagata.cppをコピーする
# コンパイル用シェルスクリプトも生成
# 第二引数に問題数をとる（デフォルトは６）
# atcoder にログインする
s=abcdefghijklmnopqrstuvwxyz
d=6
if [[ $# == 2 ]]; then
d=$2
fi
mkdir $1
for ((i=0 ; i<d; i++)) do
cp ../library/hinagata.cpp $1/${s:${i}:1}.cpp
done
touch $1/input
cd $1
oj login -u ${username} -p ${password} "https://atcoder.jp/"
