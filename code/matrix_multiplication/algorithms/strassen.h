#include <vector>
#include <cmath>
using namespace std;

int nextPowerOfTwo(int n);

vector<vector<int>> resizeMatrix(vector<vector<int>> &mat, int newR, int newC);

vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b, int size, int sign);

vector<vector<int>> strassen(vector<vector<int>> mat1, vector<vector<int>> mat2);

vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2);
