#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    string text = "ECDTM ECAER AUOOL EDSAM MERNE NASSO DYTNR VBNLC RLTIQ LAETR IGAWE BAAEI HOR";
    vector<char> input;
    vector<int> appearance;
    appearance.resize(26);
    for(int i=0; i<text.size(); i++){
        if(text[i] != ' ') {
            input.push_back(text[i]);
            appearance[text[i]-'A']++;
        }
    }
    int len = input.size();
    vector<int> dimension;
    for(int i=2; i<=sqrt(len); i++){
        if(len % i == 0) {
            dimension.push_back(i);
            dimension.push_back(len/i);
        }
    }
    vector<char> vowel;
    vowel.resize(5);
    vowel[0] = 'A';
    vowel[1] = 'E';
    vowel[2] = 'I';
    vowel[3] = 'O';
    vowel[4] = 'U';
    vector<double> v_percent;
    vector<vector<int> > v_count;
    v_count.resize(dimension.size());
    v_percent.resize(dimension.size());
    for(int i=0; i<dimension.size(); i++){
        // cout << dimension[i] << endl;
        v_count[i].resize(dimension[i]);
        for(int j=0; j<len; j++){
            for(int k=0; k<vowel.size(); k++){
                if(input[j] == vowel[k]) {
                    v_count[i][j % dimension[i]]++;
                    break;
                }
            }
        }
        for(int j=0; j<v_count[i].size(); j++){
            // cout << v_count[j] << " ";
            // cout << abs(0.4*len/dimension[i] - double(v_count[j])) << " ";
            v_percent[i] += abs(0.4*len/dimension[i] - double(v_count[i][j]));
        }
        // cout << endl;
    }

    for(int i=0; i<dimension.size(); i++){
        cout << dimension[i] << "x" << len/dimension[i] << " diff:" <<v_percent[i] << endl;
        vector<vector<char> > rectangle;
        int di = dimension[i];
        rectangle.resize(di);
        for(int j=0; j<di; j++)
            rectangle[j].resize(len/di);

        for(int j=0; j<len; j++)
            rectangle[j%di][j/di] = input[j];
        
        for(int j=0; j<di; j++){
            for(int k=0; k<len/di; k++){
                cout << rectangle[j][k] << " ";
            }
            cout << "\t" << v_count[i][j] << "\t"<< abs(0.4*len/dimension[i] - double(v_count[i][j])) << endl;
        }
        cout << endl;
    }

    return 0;
}