#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print(const vector<vector<int>> a, int size) {
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_placeable(const vector<vector<int>> a, int size, int row, int col) {
    for(int i = 0; i < size; i++) {
        if(a[row][i] == 1) return false;
        if(a[i][col] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(a[i][j] == 1) return false;
    }
    for(int i = row, j = col; i < size && j >= 0; i++, j--) {
        if(a[i][j] == 1) return false;
    }
    for(int i = row, j = col; i >= 0 && j < size; i--, j++) {
        if(a[i][j] == 1) return false;
    }
    for(int i = row, j = col; i < size && j < size; i++, j++) {
        if(a[i][j] == 1) return false;
    }
    return true;
}

vector<vector<int>> rec(vector<vector<int>> tab, int size, int row, int queens){
    if(queens == size){
        return tab;
    }

    for(int col = 0; col < size; col++){
        if (is_placeable(tab, size, row, col)){
            tab[row][col] = 1;
            vector<vector<int>> result = rec(tab, size, row + 1, queens + 1);
            if (!result.empty()){
                return result;
            }
            tab[row][col] = 0;
        }
    }

    return vector<vector<int>>();
}

int main(){
    ifstream fin("file.in");
    int n;
    fin >> n;
    fin.close();

    vector<vector<int>> a(n, vector<int>(n, 0));
    a = rec(a, n, 0, 0);

    if(a.empty()){
        cout << "No solution found." << endl;
    } 
    else{
        cout << "Solution found:" << endl;
        print(a, n);
    }

    return 0;
}