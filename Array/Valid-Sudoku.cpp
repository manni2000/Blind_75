#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3; 

/*If the cell is not empty, the code proceeds to extract the number from the cell by subtracting the
                character '0' and 1. The result is stored in the variable num.
    The variable k is calculated to represent the subgrid index based on the current row i and column j.*/

                    if(used1[i][num] || used2[j][num] || used3[k][num]) 
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
/*The code checks if the current number num is already present in the corresponding row (used1), column (used2),
      or subgrid (used3). If any of them are true, it means the Sudoku board is not valid, and 
      the function returns false.
If the number is not already used, it updates the respective row, column, and subgrid arrays by
            setting the corresponding index to 1 to mark the number as used.*/
        
        return true;
    }
};

int main(){

    Solution result;
    
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    bool isValid = result.isValidSudoku(board);
    
    if (isValid)
        cout << "The Sudoku board is valid." << endl;
    else
        cout << "The Sudoku board is invalid." << endl;
    
    return 0;
}

//TC-O(1)
//SC-O(1)