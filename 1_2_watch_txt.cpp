#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    string file_path;
    cout << "Input path for opening file ";
    cin >> file_path;
    file_path = "D:\\words.txt";
    ifstream my_file(file_path, ios::binary);
    if (!my_file.is_open()) {
        cerr << "I couldn't open the file\n";
        return 1;
    }
    else {
        cout << "File was opened successfully!\n";
    }
    const int buffer_size = 1024;
    char buffer[buffer_size];
    while (my_file.read(buffer, buffer_size)) {
        cout << 1111;
        cout.write(buffer, my_file.gcount());
    }
    cout << my_file.gcount() << endl;
    if (my_file.gcount() > 0) {
        cout.write(buffer, my_file.gcount());
    }
    my_file.close();
}