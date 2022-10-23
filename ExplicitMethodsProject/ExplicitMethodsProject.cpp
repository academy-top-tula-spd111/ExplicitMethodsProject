#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyString
{
    char* str;

public:
    MyString(int size)
    {
        str = new char[size];
    }
    MyString(const char* str)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
    MyString(char ch) = delete;

    friend MyString operator-(MyString s1, MyString s2) = delete;
    friend MyString operator-(MyString& s, int index);
    friend MyString operator-(MyString s, char ch) = delete;

    friend std::ostream& operator<<(std::ostream& out, const MyString& str)
    {
        out << str.str;
        return out;
    }
};

int main()
{
    MyString s1(20);
    std::cout << s1 << "\n";
    MyString s2("Hello");
    std::cout << s2 << "\n";

    s2 = s2 - 'l';

    std::cout << s2 << "\n";

    //MyString s3('A');
    //std::cout << s3 << "\n";
}

MyString operator-(MyString& s, int index)
{
    char* str = new char[strlen(s.str)];
    for (int i = 0; i < index; i++)
        str[i] = s.str[i];
    for (int i = index + 1; i < strlen(s.str) + 1; i++)
        str[i - 1] = s.str[i];

    delete[]s.str;
    s.str = str;
    return s;
}
