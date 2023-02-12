#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
������ 1: ��� ��������� ����. ���������� ������� ����� ����, � ������� ���������� �� ��������� ����� ��� �����, ��������� �� ����� ��� �� ���� ����.
������ 2: ��� ��������� ����. ���������� ���������� ��� ������ � ������ ����. ������� ����� �� ������ ����� ������ ��������� � �������� ����� � �������� �����.
������ 3: ������� � ���������������� ������ �� 4-� �������� ���� ����� (Fraction) � �������� ���� ������ � ���� � �������� ������.
����� ������� ������ ������ �� 4-� �������� ���� ����� � ������� � ���� ������ ������� �� ����� �����.
������ 4: ������� � ���������������� ������ �� 4-� �������� ���� ����� (Fraction) � �������� ���� ������ � ���� � �������� ������.
����� ������� ������ ���� ����� � ������� �� ����� ����� � ���� ������ ������ �������������� ������� �������. ������������ ���������������� �� �����.
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
