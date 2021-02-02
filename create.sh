#!/bin/bash
# hinagata.cppをコピーする
# コンパイル用シェルスクリプトも生成
# 第二引数に問題数をとる（デフォルトは６）
s=abcdefghijklmnopqrstuvwxyz
d=6
if [[ $# == 2 ]]; then
d=$2
fi
mkdir ../real/$1
for ((i=0 ; i<d; i++)) do
cp hinagata.cpp ../real/$1/${s:${i}:1}.cpp
done
cd ../real/$1
