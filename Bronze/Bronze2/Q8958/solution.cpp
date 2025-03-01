#include <iostream>
#include <string>
using namespace std;

int main() {
    int loop = 0;
    cin >> loop;

    string line = "";
    int score[loop];
    int yunsok = 1;
    
    for (int i = 0; i < loop; i++)
    {
        cin >> line;
        
        score[i] = 0;

        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == 'O')
            {
                score[i] += yunsok;
                yunsok++;
            }
            else {
                yunsok = 1;
            }
        }
        yunsok = 1;
    }

    for (int i = 0; i < loop; i++)
    {
        cout << score[i] << '\n';
    }
    
    return 0;
}