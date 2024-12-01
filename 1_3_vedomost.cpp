#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    ifstream vedomost ("vedomost.txt");
    string name;
    string surname;
    int salary;
    string date;
    vector <int> vec_salar;
    int max_salary = 0;
    string max_name;
    string max_surname;
    int sum_total = 0;
    while (!vedomost.eof ()) {
        vedomost >> name;
        vedomost >> surname;
        vedomost >> salary;
        vedomost >> date;
        if (salary > max_salary) {
            max_salary = salary;
            max_name = name;
            max_surname = surname;
        }
        vec_salar.push_back(salary);
        //    cout << name << " " << surname << " " << salary << " " << date;
    }
    for (int i = 0; i < vec_salar.size (); ++i) {
        sum_total += vec_salar [i];
    }
    cout << "Total sum: " << sum_total << endl;
    cout << "Maximal sum: " << max_salary << endl;
    cout << "Lucky name is " << max_name << " " << max_surname;

    vedomost.close();
}