#!/bin/bash

# sample が通るかを確認するスクリプト、問題取得からやってくれる
# ./ac.sh a などのように使う(a問題の場合)
# atcoder にログインできていない場合は oj login -u username -p password "https://atcoder.jp/" をたたく
# online-judge-tools(https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md)を使用

# カレントディレクトリからatcoderのどのコンテストかを取得
contestName=`pwd | awk -F "/" '{ print $NF }'`
# 問題URLを生成
url=`python3 ../../library/get-atcoder-url.py ${contestName} ${1}`

# 問題を取得
if [ ! -e test/${1} ]; then
  oj dl -d test/${1} ${url} > /dev/null
fi

g++ ${1}.cpp -o ${1}
# sample case 確認
oj test -c "./${1}" -d test/${1}