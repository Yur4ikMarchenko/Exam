#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
    setlocale(0, "");                            //локалізація                                                               
    string stroka = "";
    string buff;
   
    bool check_c = true;
    bool check_f = true;

    bool check_use_c = false;
    bool check_use_f = false;

    float version = 1.4;
        for (int i = 0; i < argc; ++i)
        {
            //help
            if (_stricmp(args[i], "-h") == 0)
            {
                cout << "Програма для обрахунку слiв." << endl;
                cout << "Щоб вивести версiю вкажiть - v" << endl;
            }
            //передача аргументу
            if (_stricmp(args[i], "-c") == 0)
            {
                check_c = false;
                check_use_c = true;
                if (check_use_f)
                {
                    cout << "eror!" << endl;
                    break;
                }
                for (int j = i + 1; j < argc; ++j)
                {
                    stroka += args[j] + (string)" ";
                }

            }
            //версія
            if (_stricmp(args[i], "-v") == 0)
            {
                cout << "Версiя: " << version << endl;
            }
            //файл
            if (_stricmp(args[i], "-f") == 0)
            {

                check_c = false;
                check_f = false;
                check_use_f = true;
                if (check_use_c)
                {
                    cout << "eror!" << endl;
                    break;
                }
                ifstream fin(args[i + 1]);
                if (fin.is_open())
                {
                    int kilkist = 1;
                    getline(fin, buff);
                    for (char i : buff)                   //підрахунок слів
                    {
                        if (i == ' ')
                            kilkist++;
                    }
                    fin.close();
                    cout << "Вмiст файлу: " << buff << endl << "К-ть слiв : " << kilkist << endl;
                }
            }
        }
        auto words = 0;                         //оголошення зміних
        if (check_c)
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
        if (check_f)
        {
            cout << "К-ть слiв: " << words << endl;      //вивід результату
        }
    system("pause");
    return 0;
};
//not so good as it could be but OK”
//some configuration reading
//one more nice code block