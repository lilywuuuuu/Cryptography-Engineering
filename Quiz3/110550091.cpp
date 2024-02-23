#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    string message;
    string temp;
    while(cin >> temp)
        message += temp;
    
    vector<char> input;
    for(int i=0; i<message.size(); i++)
        if(message[i] >= 'A' && message[i] <= 'Z') 
            input.push_back(message[i]);
    
    int num = 10;
    vector<vector<double> > ic;
    ic.resize(num+1);
    vector<vector<vector<int > > > alphabet;
    alphabet.resize(num+1);

    for(int i=1; i<=num; i++){
        alphabet[i].resize(i);
        ic[i].resize(i);
        vector<int> len;
        len.resize(i);
        for(int j=0; j<i; j++)
            alphabet[i][j].resize(26);
        for(int j=0; j<input.size(); j++){
            alphabet[i][j%i][input[j] - 'A']++;
            len[j%i]++;
        }
        for(int j=0; j<i; j++){
            for(int k=0; k<26; k++)
                ic[i][j] += alphabet[i][j][k] * (alphabet[i][j][k] - 1);
            ic[i][j] /= len[j] * (len[j] - 1);
        }
        for(int j=0; j<i; j++){
            ic[i][0] += ic[i][j];
        }
        ic[i][0] /= i;
    }

    double ans_sum = 0;
    int ans;
    for(int i=2; i<=num/2 ;i++){
        if(ans_sum < ic[i][0]){
            ans_sum = ic[i][0];
            ans = i;
        } 
    }
    if(ans!=5 && ans!=6) ans*=2;
    // letter frequency
    vector<double> lf = {0.082, 0.015, 0.028, 0.043, 0.13,
                        0.022, 0.02, 0.061, 0.07, 0.0015,
                        0.0077, 0.04, 0.024, 0.067, 0.075,
                        0.019, 0.00095, 0.06, 0.063, 0.091, 
                        0.028, 0.0098, 0.024, 0.0015, 0.02, 
                        0.00074};

    string answer;
    answer.resize(ans);
    double len = input.size()/ans;
    for(int i=0; i<ans; i++){
        double min = INT_MAX;
        int min_ind;
        for(int j=0; j<26; j++){ // try all different 26 keys
            double alphabet_dif = 0.0;
            for(int k=0; k<26; k++)
                alphabet_dif += abs(alphabet[ans][i][(k+j)%26]/len - lf[k]);
            if (alphabet_dif < min){
                min = alphabet_dif;
                min_ind = j;
            }
        }
        answer[i] = 'A' + min_ind;
        // cout << char('A' + min_ind) << " ";
    }
    cout << "Key = " << answer << endl;
    cout << "Plaintext = \n";
    ofstream file;
    file.open("message1_out.txt");
    for(int i=0; i<input.size(); i++){
        cout << char((input[i] - answer[i%ans] + 26) % 26 + 'A');
        file << char((input[i] - answer[i%ans] + 26) % 26 + 'A');
    }
    file.close();
    cout << endl;

    return 0;
}