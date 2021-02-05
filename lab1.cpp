#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[])
{
    setlocale(0, "");                            //локалізація                                                               
    string stroka = "";
    bool check = true;
    float version = 1.4;
    for (int i = 0; i < argc; ++i)
    {
        if (_stricmp(args[i], "-h") == 0)
        {
            cout << "Програма для обрахунку слiв." << endl;
            cout << "Щоб вивести версiю вкажiть - v" << endl;
        }
        if (_stricmp(args[i], "-c") == 0)
        {
            check = false;
            for (int j = i + 1; j < argc; ++j)
            {
                stroka += args[j] + (string)" ";
            }
        }
        if (_stricmp(args[i], "-v") == 0) 
        {
            cout << "Версiя: "<<version << endl;
        }
    }

    auto words = 0;                         //оголошення зміних
    if (check)
    {

        cout << "Введiть рядок: " << stroka << endl;
        words++;
        getline(cin, stroka);                   //введення строки 
    }

    for (char i : stroka)                   //підрахунок слів
    {
        if (i == ' ')
            words++;
    }

    cout << "К-ть слiв: " << words << endl;      //вивід результату

    system("pause");
    return 0;
};
//not so good as it could be but OK”
//some configuration reading
//one more nice code block