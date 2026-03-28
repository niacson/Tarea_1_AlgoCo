DIR_SCRIPT=$(dirname "$0")

for algo in q m s; do
    for input in "$DIR_SCRIPT/data/array_input"/*.txt; do
        echo "Sorting $input"
        ./sorting $algo $input
        echo "Sorted"
    done
done
