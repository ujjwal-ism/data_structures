#include <iostream>
using namespace std; // questionable


int main() {
    string my_name = "David Blaine";
    string my_text_editor = "Emacs";
    string my_home_os = "Windows";

    cout << "My name is " << my_name << endl
     << "I was able to install and test g++ and "
     << "the text editor " << my_text_editor << '\n'
     << "in my home computer/laptop, which runs "
     << my_home_os << endl;
    return 0;
}
