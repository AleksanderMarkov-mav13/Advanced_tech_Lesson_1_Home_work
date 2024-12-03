#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void show_quest(int position, string & file_name)
{
    if (position == 1) file_name += "1.txt";
    if (position == 2) file_name += "2.txt";
    if (position == 3) file_name += "3.txt";
    if (position == 4) file_name += "4.txt";
    if (position == 5) file_name += "5.txt";
    if (position == 6) file_name += "6.txt";
    if (position == 7) file_name += "7.txt";
    if (position == 8) file_name += "8.txt";
    if (position == 9) file_name += "9.txt";
    if (position == 10) file_name += "10.txt";
    if (position == 11) file_name += "11.txt";
    if (position == 12) file_name += "12.txt";
    if (position == 13) file_name += "13.txt";
    // cout << file_name << endl;
    ifstream quest_n(file_name, ios::binary);
    const int buffer_size = 100;
    char buffer[buffer_size];
    while (quest_n.read(buffer, buffer_size)) {
        cout.write(buffer, quest_n.gcount());
    }
    if (quest_n.gcount() > 0) {
        cout.write(buffer, quest_n.gcount());
    }
    cout << endl;
    quest_n.close();
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Let's play WHEN? WHERE? WHEN?\n";
    cout << "Sector 1 is now on our reel.\n";
    bool question [13];
    int player_score = 0;
    int observ_score = 0;
    for (int i = 0; i < 13; ++i) {
        question [i] = 1;
    }
    int position = 1;
    int offset = 0;
    while (player_score < 6 && observ_score < 6) {
        string file_name = "d:\\Question_for_game\\q_";
        cout << "Input offset ";
        cin >> offset;
        if (offset > 12) {
            cout << "Incorrect input! Repeat please " << endl;
            cin >> offset;
        }
        position += offset;
        // cout << "position " << position << endl;
        if (position > 13) {
            position -= 13; 
        }
        while (!question[position-1]) {
            position++;
        }
        question [position -1] = 0;
        show_quest(position, file_name);
        string answ_pl;
        cout << "Input your answer: ";
        cin >> answ_pl;
        file_name.at(21) = 'a';
        ifstream answer(file_name);
        string answ_r;
        answer >> answ_r;
        if (answ_r == answ_pl) {
            player_score++;
        } 
        else {
            observ_score ++;
        }
        cout << "Actual count: Player - " << player_score << " Observers - " << observ_score << endl;
    }
    if (player_score == 6) {
        cout << endl << "PLAYER WIN!!!";
    }
    else {
        cout << endl << "OBSERVERS WIN!!!";
    }
}