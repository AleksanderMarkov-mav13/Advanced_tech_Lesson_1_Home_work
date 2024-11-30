#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    ifstream bank;
    bank.open("C:\\develop\\Home_Work_GB\\C++Advanced_topics\\Lesson_1_Opening_files\\Lesson_1_Home_Work\\words.txt", ios::binary);
    string key_word;
    cout << "Input word for searching: ";
    cin >> key_word;
    int len_kw = key_word.length ();
    bank.seekg(0, ios::end);
    int len_f = bank.tellg();
    char buffer[len_kw];
    int count_cs_w = 0;
    for (int i = 0; i < len_f - len_kw +1; i++)
    {
        bank.seekg(i);
        bank.read(buffer, sizeof(buffer));
        int count_cs = 0;
        for (int j = 0; j < sizeof(buffer); j++)
        {
            if (key_word[j] == buffer[j]) {
                count_cs++;
            }
            else {
                break;
            }
            if (count_cs == sizeof(buffer))
            {
                count_cs_w++;
            }
        }
    }
    cout << "There are " << count_cs_w << " instances of your word in the file.";
    bank.close();
}