
#include <iostream>
#include<vector>
using namespace std;

bool isValidMove(vector<vector<char>> &board,int row,int col,int dig)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]-'0'==dig)
        return false;
        if(board[row][i]-'0'==dig)
        return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]-'0'==dig)
        return false;
    }
    return true;
}

bool solver(vector<vector<char>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
                for(int k=1;k<=9;k++)
                {
                    
                    if(isValidMove(board,i,j,k))
                    {
                        board[i][j]=(char)(k+'0');
                        bool cansolvefurther=solver(board);
                        
                        if(cansolvefurther)//If u can solve further u keep the value as it is and go ahead
                        return true;
                        else
                        board[i][j]='.';
                        
                    }
                    
                }
                if(board[i][j]=='.')//No move was found valid for i,j 
                return false;
            }
            
        }
    }
    return true;
    
    
}
void solveSudoku(vector<vector<char>> &A) {
    if(solver(A))
    {
        for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    }
    else
    cout<<"No solution";
    
}

int main()
{
    // 0 means unassigned cells
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
                       
    vector<vector<char>> characterGrid(9,vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                characterGrid[i][j] = '.';
            } else {
                characterGrid[i][j] = '0' + grid[i][j];
            }
        }
    }
    solveSudoku(characterGrid);
 
    return 0;
    // This is code is contributed by Pradeep Mondal P
}
