atCoderUrlPrefix="https://atcoder.jp"
import sys

#形式エラー
if len(sys.argv) != 3:
    print("you shoud retry below forms")
    print("python3 get-test.py contestName mondaiName")
    print("------------ for example ---------------")
    print("python3 get-test.py abc165 e")
    sys.exit()

def zerotuika(contestName,n):
    flag=False
    if "abc" in contestName:
        flag=True
    if "arc" in contestName:
        flag=True
    if "agc" in contestName:
        flag=True
    if flag:
        #abc,arc,agc
        prefix=contestName[0:3]
        num=contestName[3:]
        # 9 -> 009, 35 -> 035 0を n桁になるまで追加する
        while len(num) < n:
            num=str(0)+num
        return prefix+num
    return contestName

# コマンドライン引数設定
contestName = zerotuika(sys.argv[1],3)
mondaiName=sys.argv[2]

atCoderMondaiUrl=atCoderUrlPrefix+"/contests/"+contestName+"/tasks/"+contestName+"_"+mondaiName
print(atCoderMondaiUrl)