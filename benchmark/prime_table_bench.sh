filename=prime_table
N=8
/c/MinGW/bin/g++ ${filename}_bench.cpp -o ${filename}

k=1
for ((i=1 ; i<N+1 ; i++)) do
echo $((k=k*10))
./${filename} ${k}
done
