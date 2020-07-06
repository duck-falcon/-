import requests
from bs4 import BeautifulSoup
import re
import sys
import os

atCoderUrlPrefix="https://atcoder.jp/contests/"

#形式エラー
if len(sys.argv) != 3:
    print("you shoud retry below forms")
    print("python get-test.py contestName mondaiName")
    print("------------ for example ---------------")
    print("python get-test.py abc165 e")
    sys.exit()

# コマンドライン引数設定
contestName=sys.argv[1]
mondaiName=sys.argv[2]

if(not os.path.exists(mondaiName+"in")) and (not os.path.exists(mondaiName+"out")):
    os.mkdir(mondaiName+"in")
    os.mkdir(mondaiName+"out")

if os.path.exists(mondaiName+"in/"+mondaiName+"in0.txt") or os.path.exists(mondaiName+"out/"+mondaiName+"out0.txt"):
    j = 0
    while os.path.exists(mondaiName+"in/"+mondaiName+"in"+str(j)+".txt") or os.path.exists(mondaiName+"out/"+mondaiName+"out"+str(j)+".txt"):
        j+=1
    print(j)
    sys.exit()

#接続URL作成 html取得
atCoderUrl=atCoderUrlPrefix+contestName+"/tasks/"+contestName+"_"+mondaiName
url = requests.get(atCoderUrl)

#httpステータス確認
if not "200" in str(url):
    print(url)
    print("your specified URL is" + atCoderUrl)
    print("try again")
    sys.exit()

#パーサー
soup = BeautifulSoup(url.content, "html.parser")

pretags = soup.find_all("pre")
i=0
#同じデータが来たときにbreakする用
inSaisyo = True
eigoKaihiIn="eigoKaihiIn"
ini = 0
for p in pretags:
    if p.string != None and i % 2 == 0:
        if eigoKaihiIn == p.string.replace("\n",""):
            break
        if inSaisyo:
            eigoKaihiIn = p.string.replace("\n","")
            inSaisyo = False
        inFile=open(mondaiName+"in/"+mondaiName+"in"+ str(ini) + ".txt",mode="w")
        inFile.write(p.string.replace("\n",""))
        ini+=1
        i+=1
        inFile.close()
    elif p.string != None and i % 2 == 1:
        outFile=open(mondaiName+"out/"+mondaiName+"out"+ str(ini-1) + ".txt",mode="w")
        outFile.write(p.string.replace("\n",""))
        i+=1
        outFile.close()
print(ini)
