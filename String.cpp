#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

class stringg
{
    char *str;
    size_t len;

public:
    // Default constructor
    stringg() : str(nullptr), len(0) {}

    // Parameterized constructor
    stringg(const char *input)
    {
        len = strlen(input);
        str = new char[len + 1];
        strcpy(str, input);
    }

    // Copy constructor
    stringg(const stringg &other)
    {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~stringg()
    {
        delete[] str;
        str = nullptr;
        len = 0;
    }

    // Assignment operator
    stringg &operator=(const stringg &other)
    {
        if (str != nullptr)
            delete[] str;

        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
        return *this;
    }

    // Addition Operator
    stringg operator+(const stringg &other)
    {
        stringg temp;
        temp.len = len + other.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    // Subscript operator
    char operator[](size_t index)
    {
        if (index >= 0 && index <= len)
            ;
        return str[index];
    }

    // Relational operator
    bool operator<(const stringg &other)
    {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const stringg &other)
    {
        return strcmp(str, other.str) > 0;
    }

    bool operator>=(const stringg &other)
    {
        return strcmp(str, other.str) >= 0;
    }

    bool operator<=(const stringg &other)
    {
        return strcmp(str, other.str) <= 0;
    }

    bool operator!=(const stringg &other)
    {
        return strcmp(str, other.str) != 0;
    }

    bool operator==(const stringg &other)
    {
        return strcmp(str, other.str) == 0;
    }

    size_t begin()
    {
        return 0;
    }

    size_t end()
    {
        return len - 1;
    }

    // Friend functions for stream insertion & extraction
    friend istream &operator>>(istream &in, stringg &obj)
    {
        char buffer[1024];
        in >> buffer;
        obj = stringg(buffer);
        return in;
    }

    friend ostream &operator<<(ostream &out, stringg &obj)
    {
        out << obj.str;
        return out;
    }

    // Friend functions for string manipulation
    friend void strcpy(stringg &dest, stringg &src)
    {
        delete[] dest.str;
        dest.len = src.len;
        dest.str = new char[dest.len + 1];
        strcpy(dest.str, src.str);
    }

    friend void strncpy(stringg &dest, stringg &src, size_t n)
    {
        delete[] dest.str;
        dest.len = n;
        dest.str = new char[dest.len + 1];
        strncpy(dest.str, src.str, n);
        dest.str[dest.len] = '\0';
    }

    friend int strcmp(stringg &dest, stringg &src)
    {
        return strcmp(dest.str, src.str);
    }

    friend int strncmp(stringg &dest, stringg &src, int n)
    {
        return strncmp(dest.str, src.str, n);
    }

    friend void strcat(stringg &dest, stringg &src)
    {
        stringg temp;
        temp.len = dest.len + src.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, dest.str);
        strcat(temp.str, src.str);
        dest = temp;
    }

    friend void strncat(stringg &dest, stringg &src, int n)
    {
        stringg temp;
        temp.len = dest.len + n;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, dest.str);
        strncat(temp.str, src.str, n);
        dest = temp;
    }

    friend void strrev(stringg &obj)
    {
        reverse(obj.str, obj.str + obj.len);
    }

    friend void strlower(stringg &obj)
    {
        if (obj.str)
            for (size_t i = 0; i < obj.len; i++)
                obj.str[i] = tolower(obj.str[i]);
    }

    friend void strupper(stringg &obj)
    {
        if (obj.str)
            for (size_t i = 0; i < obj.len; i++)
                obj.str[i] = toupper(obj.str[i]);
    }

    friend char *strchr(stringg &obj, char ch)
    {
        return strchr(obj.str, ch);
    }

    friend char *strstr(stringg &obj, char *str)
    {
        return strstr(obj.str, str);
    }

    friend size_t strlen(stringg &obj)
    {
        return obj.len;
    }
};

int main()
{

    // Test parameterized constructor
    stringg str2("Hello");
    cout << "Parameterized constructed string: " << str2 << endl;

    // Test copy constructor
    stringg str3(str2);
    cout << "Copied string: " << str3 << endl;

    // Test assignment operator
    stringg str4;
    str4 = str2;
    cout << "Assigned string: " << str4 << endl;

    // Test addition operator
    stringg str5 = str2 + stringg(" World!");
    cout << "Concatenated string: " << str5 << endl;

    // Test subscript operator
    cout << "First character of str2: " << str2[0] << endl;

    // Test relational operators
    cout << "str2 < str5: " << (str2 < str5) << endl;
    cout << "str2 > str5: " << (str2 > str5) << endl;
    cout << "str2 == str4: " << (str2 == str4) << endl;

    // Test string manipulation functions
    stringg str6("Hello World!");
    cout << "Original string: " << str6 << endl;

    strlower(str6);
    cout << "Lowercase string: " << str6 << endl;

    strupper(str6);
    cout << "Uppercase string: " << str6 << endl;

    strrev(str6);
    cout << "Reversed string: " << str6 << endl;

    // Test strlen function
    cout << "Length of str6: " << strlen(str6) << endl;

    // Test strchr function
    char *foundChar = strchr(str6, 'W');
    if (foundChar)
    {
        cout << "'W' found in str6. " << endl;
    }
    else
    {
        cout << "'W' not found in str6." << endl;
    }

    // Test strstr function
    char *foundStr = strstr(str6, "lo");
    if (foundStr)
    {
        cout << "'lo' found in str6. " << endl;
    }
    else
    {
        cout << "'lo' not found in str6." << endl;
    }

    return 0;
}