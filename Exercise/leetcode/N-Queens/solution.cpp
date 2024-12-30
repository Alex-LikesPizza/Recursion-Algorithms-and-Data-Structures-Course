#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool isValidPosition(vector<string>& board, int i, int j){
    for(int k = i + 1; k < board.size(); k++){ // btm
      if(board.at(k).at(j) == 'Q') return false;}
    for(int k = i - 1; k >= 0; k--){ // top
      if(board.at(k).at(j) == 'Q') return false;}
    for(int k = j + 1; k < board.size(); k++){ // right
      if(board.at(i).at(k) == 'Q') return false;}
    for(int k = j - 1; k >= 0; k--){ // left
      if(board.at(i).at(k) == 'Q') return false;}
    for(int m = i + 1, n = j + 1; m < board.size() && n < board.size(); m++, n++){ // btm right
      if(board.at(m).at(n) == 'Q') return false;}
    for(int m = i + 1, n = j - 1; m < board.size() && n >= 0; m++, n--){ // btm left
      if(board.at(m).at(n) == 'Q') return false;}
    for(int m = i - 1, n = j + 1; m >= 0 && n < board.size(); m--, n++){ // top right
      if(board.at(m).at(n) == 'Q') return false;}
    for(int m = i - 1, n = j - 1; m >= 0 && n >= 0; m--, n--){ // top left
      if(board.at(m).at(n) == 'Q') return false;}
    return true;
  }
  vector<vector<string>> solutionFn (vector<string> board, int i){
    if(i == board.size()) return {board};
    vector<vector<string>> solutions;
    for(int j = 0; j < board.size(); j++){
      if(isValidPosition(board, i, j)) {
        board.at(i).at(j) = 'Q';
        vector<vector<string>> s = solutionFn(board, i+1);
        solutions.insert(solutions.end(), s.begin(), s.end());
        board.at(i).at(j) = '.';
      }
    }

    return solutions;
  }
  vector<vector<string>> solveNQueens(int n){
    vector<string> board(n);
    for(string& s : board){
        s.append(n, '.');
    }
    return solutionFn(board, 0);
  }
};