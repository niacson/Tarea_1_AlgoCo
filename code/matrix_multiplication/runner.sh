DIR_SCRIPT=$(dirname "$0")

for algo in n s; do
    for input1 in "$DIR_SCRIPT/data/matrix_input"/*_1.txt; do
        input2="${input1/_1.txt/_2.txt}"
        if [[ -f "$input2" ]]; then
            echo "Multiplicando matrices: $input1 X $input2. Metodo: $algo"
            ./matmul $algo $input1 $input2
            echo "Multiplicacion finalizada"
        fi
    done
done
shutdown 10
