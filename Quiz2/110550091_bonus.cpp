#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void){
    string text = "LLOWA POLNH NHOEG YSOKD NDWNI TUIEE FHMDR IEBYT CWEOH ARRUE";
    vector<char> input;
    for(int i=0; i<text.size(); i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            input.push_back(text[i]);
        }
    }
    int len = input.size();
    int row = 6;
    int col = ceil(double(len)/6);
    int mod = len % col;
    vector<vector<char> > rectangle;
    rectangle.resize(row);
    for(int i=0; i<row; i++)
        rectangle[i].resize(col);
    for(int i=0; i<len; i++){
        if(i/row >= mod) rectangle[i % mod][mod + (i - mod * row) / mod] = input[i];
        else rectangle[i%row][i/row] = input[i];
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << rectangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}