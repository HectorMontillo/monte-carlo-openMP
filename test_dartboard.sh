#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "ndarts\ttime(seq)\tpi(seq)\terr(seq)\ttime(omp)\tpi(omp)\terr(omp)\n"
    for i in 1000000 10000000 100000000 200000000 300000000 400000000 500000000 600000000 700000000 800000000 900000000 1000000000 
      do 
        ./dartboard_seq $i
        ./dartboard_omp $i
done
done