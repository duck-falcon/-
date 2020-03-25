# hinagata.cppをコピーする
# コンパイル用シェルスクリプトも生成
# 第二引数に問題数をとる（デフォルトは６）
s=abcdefghijklmnopqrstuvwxyz
d=6
if [[ $# == 2 ]]; then
d=$2
fi
mkdir ../$1
for ((i=0 ; i<d; i++)) do
cp hinagata.cpp ../$1/${s:${i}:1}.cpp
done
