#include <cmath>
#include <vector>
using namespace std;

int nextPowerOfTwo(int n);

vector<vector<int>> resizeMatrix(vector<vector<int>> &mat, int newR, int newC);

vector<vector<int>> add(const vector<vector<int>> &a, const vector<vector<int>> &b,
                        int size, int sign);

vector<vector<int>> strassen(const vector<vector<int>> &mat1,
                             const vector<vector<int>> &mat2);

vector<vector<int>> multiply(vector<vector<int>> &mat1,
                             vector<vector<int>> &mat2);
