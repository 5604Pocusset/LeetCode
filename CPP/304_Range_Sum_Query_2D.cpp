#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int> > sum_matrix;
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) {
            this->sum_matrix = vector<vector<int> >(1, vector<int>(1));
            this->sum_matrix[0][0] = 0;
            return;
        }
        this->sum_matrix = vector<vector<int> >(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                // cout << "i = " << i << ", j = " << j << endl;
                if (i == 0 && j == 0) {
                    sum_matrix[i][j] = matrix[i][j];
                }
                else if (i == 0) {
                    sum_matrix[i][j] = sum_matrix[i][j - 1] + matrix[i][j];
                }
                else if (j == 0) {
                    sum_matrix[i][j] = sum_matrix[i - 1][j] + matrix[i][j];
                }
                else {
                    sum_matrix[i][j] = sum_matrix[i][j - 1] + sum_matrix[i - 1][j] -
                    sum_matrix[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
/*
        for (int i = 0; i < sum_matrix.size(); i++) {
            for (int j = 0; j < sum_matrix[i].size(); j++) {
                cout << sum_matrix[i][j] << " ";
            }
            cout << endl;
        }
*/
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return sum_matrix[row2][col2];
        }
        else if (row1 == 0) {
            return sum_matrix[row2][col2] - sum_matrix[row2][col1 - 1];
        }
        else if (col1 == 0) {
            return sum_matrix[row2][col2] - sum_matrix[row1 - 1][col2];
        }
        else {
            return sum_matrix[row2][col2] - sum_matrix[row1 - 1][col2] -
            sum_matrix[row2][col1 - 1] + sum_matrix[row1 - 1][col1 - 1];
        }
        return 0;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main()
{
    int m[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    vector<vector<int> > matrix(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = m[i][j];
        }

    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;

    return 0;
}