#include <iostream>
#include <string>
#include <time.h>
using namespace std;

typedef struct member
{
    string name;
    int no;
    int savings;
    int password;
} member;
void delay(int seconds)
{
    int milliseconds = seconds * 1000;
    clock_t start = clock();
    while (clock() < start + milliseconds)
    {
    };
}
member input(member e, int i)
{
    cout << "enter name \n";
    cin >> e.name;
    if (e.name.length() > 255)
    {
        cout << "invalid name length\n";
    }
label2:
    cout << "enter password\n";
    cin >> e.password;
    int count2, temp = e.password;
    while (temp != 0)
    {
        temp /= 10;
        count2++;
    }
    if (count2 > 10 || count2 == 0)
    {
        cout << "password is of invalid length";
        goto label2;
    }
    e.no = i;
    cout<<e.no<<"\n";
    e.savings = 0;

    return e;
}
bool password_check(int a, int b)
{

    return (a == b);
}
member deposit(member e)
{
    int b;
    cout << "enter amount deposited\n";
    cin >> b;
    e.savings += b;
    return e;
}
member withdraw(member e)
{
    int b;
    cout << "enter amount withdrawn\n";
    cin >> b;
    e.savings -= b;
    return e;
}
member display(member e)
{
    cout << e.name << "\n";
    cout << e.no << "\n";
    cout << e.savings << "\n";
    return e;
}
member edit(member e)
{
    string b;
    cout << "enter details to be changed";
    if (b == "name")
    {
        cin >> e.name;
    }
    else if (b == "password")
    {
        int d;
        cout << "enter previous password\n";
        if (d == e.password)
        {
            cin >> e.password;
        }
    }
    return e;
}
int main()
{

    const int num = 100;
    int i = 0;
    member people[num];
    int count = 0;
    int a;
    int count2;
    while (1)
    {
    label:

        cout << "WELCOME TO THE SYSTEM HOW CAN WE SERVE YOU TODAY\n";
        cout << "1:create account\n";
        cout << "2:deposit money\n";
        cout << "3:withdraw money\n:";
        cout << "4:display info:\n";
        cout << "5:edit  details\n";
        int choice;

        cin >> choice;

        if (count == 0 && choice != 1)
        {
            cout << "no account to operate with\n";
            delay(2);
            continue;
        }
        else
        {

            if (choice > 5 || choice < 0)
            {
                cout << "invalid choice\n";
                delay(2);
                continue;
            }
            if (choice != 1)
            {
                cout << "enter account number\n";
                cin >> a;
            }
            int password = 0;
            int count3 = 0;

            while (count3 < 5 && count != 0)
            {
                cout << "enter password\n";
                cin >> password;

                if (password_check(people[a].password, password))
                {

                    break;
                }
                else
                {
                    cout << "wrong password re-enter\n";
                    cin >> password;
                    count3++;
                }
            }
            if (count3 > 5)
            {
                cout << "invalid password trials exhausted\n";
                count3++;
                delay(2);
                continue;
            }
            else
            {
                switch (choice)
                {
                case 1:
                    people[i] = input(people[i], i);
                    i++;
                    count++;
                    delay(2);
                    break;
                case 2:

                    people[a] = deposit(people[a]);
                    delay(2);
                    break;
                case 3:

                    people[a] = withdraw(people[a]);
                    delay(2);
                    break;
                case 4:

                    people[a] = display(people[a]);
                    delay(2);
                    break;
                case 5:

                    people[a] = edit(people[a]);
                    delay(2);
                    break;
                }
            }
        }
    }
}