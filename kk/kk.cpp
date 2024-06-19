#include <iostream>
#include <cstring>

using namespace std;

class String
 {
private:
    char* str;
    int size;
    static int count;

public:
    String() : String(80) {}

    String(int size) 
    {
        this->size = size;
        str = new char[size + 1];
        str[0] = '\0';
        count++;
    }

    String(const char* input)
    {
        size = strlen(input);
        str = new char[size + 1];
        strcpy_s(str, size + 1, input);
        count++;
    }

    ~String() 
    {
        delete[] str;
        count--;
    }

    void input()
    {
        cout << "Enter a string: ";
        cin.getline(str, size);
    }

    void print() const
    {
        cout << str << endl;
    }

    static int getCount() 
    {
        return count;
    }
};

int String::count = 0;

int main() {
    String str1;
    str1.input();
    str1.print();

    String str2(20);
    str2.input();
    str2.print();

    String str3("Hello, world!");
    str3.print();

    cout << "Number of String objects created: " << String::getCount() << endl;

}