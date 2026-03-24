/*Fuente: https://www.geeksforgeeks.org/dsa/strassens-matrix-multiplication/#naive-approach-using-nested-loops-on-3-time-and-on-2-space*/
#include "naive.h"

std::vector<std::vector<int>> naiveMatMul(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
    int n = mat1.size();
    int m = mat1.at(0).size();
    int q = mat2.at(0).size();
    std::vector<std::vector<int>> output(n, std::vector<int>(q, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < m; k++) {
                output.at(i).at(j) += mat1.at(i).at(k) * mat2.at(k).at(j);
            }
         }
    }
    return output;
}
