#include <iostream>
#include <fstream>
using namespace std;
string get_extension(string filePath)
{
    int lastDotIndex = filePath.rfind('.');
    if (lastDotIndex == string::npos) {
        return "";
    }
    else {
        return filePath.substr(lastDotIndex + 1);
    }
}
bool isPNG(string filePath)
{
    ifstream file(filePath, ios::binary); 
    if (!file.is_open())
    {
        cerr << "Не удалось открыть файл" << endl;
        return false;
    }
    char magicNumber[8];                            
    file.read(magicNumber, 8);                      
    file.close();                                   
    string pngMagicNumber = "89504e470d0a1a0a";     
    string actualMagicNumber = string(magicNumber); 
    if (actualMagicNumber == pngMagicNumber)
    {                                                     
        cout << "Файл является изображением PNG" << endl; 
        return true;
    }
    else
    {
        cout << "Файл не является изображением PNG" << endl; 
        return false;
    }
}

int main()
{
    string filePath; 
    cout << "Введите путь к файлу: ";
    cin >> filePath;                           
    string extension = get_extension(filePath); 
    if (extension == "png")
    { 
        if (isPNG(filePath))
        {                                          
            cout << "Это изображение PNG" << endl; 
        }
        else
        {
            cout << "Содержимое файла не соответствует формату PNG" << endl; 
        }
    }
    else
    {
        cout << "Этот файл не имеет расширения PNG" << endl; 
    }
    return 0;
}
