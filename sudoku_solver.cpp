#include <iostream>
#include<math.h>
using namespace std;

void Print(int board[][9],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n"; 
    }
    
}
bool isValid(int board[][9],int i,int j, int num,int n){
    // Row Check and column check
    for (int k = 0; k < 9; k++)
    {
        if((num==board[i][k]) || (num == board[k][j])){
            return false;
        }
    } 
    // Grid Check
    int si = i - i/(sqrt(n));
    int sj = j - j/(sqrt(n));
    for (int p = si; p <si+3; p++)
    {
        for (int q = sj; q <sj+3; q++)
        {
            if(board[p][q] == num){
                return false;
            }
        }
    }
    return true;
}
bool SudokuSolver(int board[][9],int i,int j, int n){
    // base case 
    if (i==n){
        Print(board,n);
        return true;
    }
    // if we are not inside the box
    if( j == n){
        return SudokuSolver(board,i+1,0,n);
    }
    // if it is already filled
    if(board[i][j]!=0){
        return SudokuSolver(board,i,j+1,n);
    }

    // we try to fill with an appropriate number
    for (int num = 1; num <= n; num++)
    {
        // chech if num is valid
        if(isValid(board,i,j,num,n)){
            board[i][j] = num;
            bool subAns =SudokuSolver(board,i,j+1,n);
            if(subAns){
                return true;
            }
            // Backtracking - undo the changes
            board[i][j] = 0;
            
        }
    }
    
}

int main(){
    int n = 9;
    int board[9][9] ={
        {0,0,7,1,0,0,0,6,0},
        {1,0,5,2,0,8,0,0,0},
        {6,0,0,0,0,7,1,2,0},
        {3,1,2,4,0,5,0,0,8},
        {0,0,6,0,9,0,2,0,0},
        {0,0,0,0,0,3,0,0,1},
        {0,0,1,0,0,4,9,8,6},
        {8,0,3,9,0,6,0,0,0},
        {0,6,0,0,8,2,7,0,3}
    };
    bool a = SudokuSolver(board,0,0,n);
    return 0;
}