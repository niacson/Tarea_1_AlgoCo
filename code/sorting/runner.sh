DIR_SCRIPT=$(dirname "$0")

for algo in q m s; do
    for input in "$DIR_SCRIPT/data/easy"/*.txt; do
        ./sorting $algo $input
    done
done
