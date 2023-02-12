#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
Задача 1: Дан текстовый файл. Необходимо создать новый файл, в который переписать из исходного файла все слова, состоящие не менее чем из семи букв.
Задача 2: Дан текстовый файл. Необходимо переписать его строки в другой файл. Порядок строк во втором файле должен совпадать с порядком строк в заданном файле.
Задача 3: Создать и инициализировать массив из 4-х объектов типа Дробь (Fraction) и записать этот массив в файл в бинарном режиме.
Затем создать другой массив из 4-х объектов типа Дробь и считать в этот массив объекты из этого файла.
Задача 4: Создать и инициализировать массив из 4-х объектов типа Дробь (Fraction) и записать этот массив в файл в бинарном режиме.
Затем создать объект типа Дробь и считать из этого файла в этот объект данные предпоследнего объекта массива. Использовать позиционирование по файлу.
*/


void Task_1()
{
    ifstream sourceFile;
    ofstream newFile;
    string word;

    sourceFile.open("sourcefile.txt");
    newFile.open("newfile.txt");

    while (sourceFile >> word)
    {
        if (word.length() >= 7)
        {
            newFile << word << endl;
        }
    }

    sourceFile.close();
    newFile.close();
}

void Task_2()
{
    ifstream inputFile("sourcefile.txt");
    ofstream outputFile("newfile.txt");
    string line;

    while (getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

struct Fraction {
    int numerator;
    int denominator;
};

int main()
{
    // Task_1();
    // Task_2();
    Fraction arr[4];

    arr[0] = { 2, 3 };
    arr[1] = { 4, 5 };
    arr[2] = { 6, 7 };
    arr[3] = { 8, 9 };

    
    ofstream outfile("data.txt", ios::binary);
    outfile.write((char*)&arr, sizeof(arr));
    outfile.close();

   
    Fraction arr2[4];
    ifstream infile("data.txt", ios::binary);
    infile.read((char*)&arr2, sizeof(arr2));
    infile.close();

    for (int i = 0; i < 4; i++) 
    {
        cout << arr2[i].numerator << "|" << arr2[i].denominator << endl;
    }

    // _______________________________________________________________________

    Fraction fractions[4] = { {2, 3}, {5, 6}, {7, 8}, {9, 10} };

    ofstream file("fractions.txt", ios::binary);

    file.write((char*)fractions, sizeof(fractions));
    file.close();
    
    Fraction fraction;
    
    ifstream input("fractions.txt", ios::binary);
    input.seekg(-2 * sizeof(Fraction), ios::end);
    input.read((char*)&fraction, sizeof(Fraction));
    input.close();

    cout << fraction.numerator << "/" << fraction.denominator << endl;

    return 0;
}
