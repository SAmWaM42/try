#include <iostream>
#include <time.h>
#include <string>
using namespace std;
void delay(int seconds)
{
    int milliseconds = seconds * 1000;
    clock_t start = clock();
    while (clock() < start + milliseconds)
    {
    };
}

int main()
{
    int i;
    cout << "enter the number of students";
    cin >> i;
    int marks[i];
    int divide = i;
    double total=0;

    while (i > 0)
    {
        cout << "enter the  marks";
        cin >> marks[i];
        total+= marks[i];
         i--;
    }
    cout << divide << "\n";
    double average = total / divide;
    cout << average << "\n";
}