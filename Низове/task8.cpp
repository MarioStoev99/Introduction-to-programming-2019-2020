#include <iostream>
using namespace std;
const size_t MAX_SIZE = 128;
int Strlen(const char* str)
{
    int count = 0;
    for(int i = 0;str[i] != 0;i++)
    {
        count++;
    }
    return count;
}
char* createStr(size_t size)
{
    char* str = new(nothrow) char[size];
    return str;
}
void print(const char* str)
{
    for(int i = 0;str[i] != 0;i++)
        cout << str[i];
}
void strcpy(char* text,const char* text1)
{
    int i;
    for(i = 0;text1[i] != 0;i++)
        text[i] = text1[i];
    text[i] = '\0';
}
void resize(char*& str,int sizeofText)
{
    int len = Strlen(str);
    char* new_arr = new(nothrow) char[len + sizeofText + 1];
    if(!new_arr)
        return;
    for(int i = 0;str[i] != 0;i++)
        new_arr[i] = str[i];
    delete[] str;
    str = new_arr;
}
void strcat(char* text1,const char* text2)
{
    int text1_i = Strlen(text1);
    for(int i = 0;text2[i] != 0;i++)
    {
        text1[text1_i++] = text2[i];
    }
    text1[text1_i] = '\0';
}
void dynamicConcat(char*& str,const char* text)
{
    resize(str,Strlen(text));
    strcat(str,text);
}
void _delete(char* str)
{
    delete[] str;
}
int main()
{
    char buffer[MAX_SIZE];
    const char* text = " world";
    cin.getline(buffer,MAX_SIZE);
    int len = Strlen(buffer);
    char* str = nullptr;
    str = createStr(len);
    if(!str)
    {
        cout << "error";
        return 0;
    }
    strcpy(str,buffer);
    dynamicConcat(str,text);
    print(str);
    _delete(str);
    return 0;
}
