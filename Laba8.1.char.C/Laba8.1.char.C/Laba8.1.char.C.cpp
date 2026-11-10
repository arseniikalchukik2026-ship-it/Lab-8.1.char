#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* s) // s - вказівник на початок рядка
{
    int k = 0,
        pos = 0; // pos - позиція початку пошуку
    char* t;

    // Шукаємо першу літеру 'S' або 'Q' в рядку
    while ((t = strchr(s + pos, 'S')) || (t = strchr(s + pos, 'Q')))
    {
        // Якщо знайшли обидва символи в залишку рядка, беремо той, що ближче
        char* tS = strchr(s + pos, 'S');
        char* tQ = strchr(s + pos, 'Q');
        if (tS != 0 && tQ != 0)
            t = (tS < tQ) ? tS : tQ;
        else
            t = (tS != 0) ? tS : tQ;

        pos = t - s + 1; // pos - наступний символ після знайденого

        // Перевіряємо пару: якщо знайшли 'S', то наступний має бути 'Q', і навпаки
        if ((*t == 'S' && *(t + 1) == 'Q') || (*t == 'Q' && *(t + 1) == 'S'))
            k++;
    }
    return k;
}

char* Change(char* s) // s - вказівник на початок рядка
{
    // Створюємо буфер із запасом, оскільки рядок розширюється при заміні на ***
    char* t = new char[strlen(s) * 3 / 2 + 1];
    char* p;
    int pos1 = 0, // pos1 - позиція початку пошуку
        pos2 = 0;
    *t = 0;

    while ((p = strchr(s + pos1, 'S')) || (p = strchr(s + pos1, 'Q')))
    {
        char* pS = strchr(s + pos1, 'S');
        char* pQ = strchr(s + pos1, 'Q');
        if (pS != 0 && pQ != 0)
            p = (pS < pQ) ? pS : pQ;
        else
            p = (pS != 0) ? pS : pQ;

        if ((*p == 'S' && *(p + 1) == 'Q') || (*p == 'Q' && *(p + 1) == 'S'))
        {
            pos2 = p - s + 2; // pos2 - позиція наступного символу після пари
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1; // pos2 - позиція наступного символу після поточної літери
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'QS' or 'SQ'" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
