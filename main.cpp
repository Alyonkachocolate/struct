#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

struct Stud
{
    string fio;
    int age{};
    int dis{};
    double mark{};
};
int main() {
    std::ifstream ifout;
    //ifout.open ("input.txt", std::ios::in)
    ifout.open ("input.txt", std::ios::in);

    std::ofstream ofout;
    //ofout.open ("output.txt");
    ofout.open ("input.txt", std::ios::out);


    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter user: " << endl;
        Stud student;
        cin.ignore();
        getline(cin, student.fio);
        cin >> student.age;
        cin >> student.dis;
        cin >> student.mark;
        ofout << student.fio << endl << student.age << ' '<< student.dis << ' '<< student.mark << endl;
    }

    ofout.close();


    {

        while (ifout.peek() != EOF) {
            Stud student;
            cin.ignore();
            getline(ifout, student.fio);
            ifout >> student.age;
            ifout >> student.dis;
            ifout >> student.mark;

            cout << "Read user: fio=" << student.fio << ", age="
                 << student.age << ", dis=" << student.dis << ", mark=" << student.mark;
        }
        ifout.close();
    }
    return 0;
}