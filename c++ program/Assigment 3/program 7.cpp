//Write a Program to perform following operation on text file :
//
//a) write content in a text file
//b) read content from file
//c) count no of word and no of lines in a file
//d) copy contents of one file to another file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    int words = 0, lines = 0;
    char ch;

    // a) Write content in a text file
    ofstream fout("input.txt");

    cout << "Enter text (type END on a new line to stop):\n";

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        fout << line << endl;
    }

    fout.close();

    // b) Read content from file
    ifstream fin("input.txt");

    cout << "\nContent of File:\n";

    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();

    // c) Count words and lines
    fin.open("input.txt");

    while (getline(fin, line))
    {
        lines++;

        bool inWord = false;

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ' && line[i] != '\t')
            {
                if (!inWord)
                {
                    words++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }
    }

    fin.close();

    cout << "\nNumber of Words: " << words << endl;
    cout << "Number of Lines: " << lines << endl;

    // d) Copy contents from one file to another
    fin.open("input.txt");
    ofstream fout2("output.txt");

    while (fin.get(ch))
    {
        fout2.put(ch);
    }

    fin.close();
    fout2.close();

    cout << "\nFile copied successfully to output.txt" << endl;

    return 0;
}

