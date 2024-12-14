#include <iostream>
#include <iomanip>
#include <unistd.h>  
#include <string>
#include<fstream>
#include<vector>
#include <conio.h>
#include <cctype>
#include <algorithm> // For std::transform
using namespace std;

class Student {
private: 
    string id;
    int grade;
    float price;

public:
    string name;
    int age;
    string gender;
    string email;

    string getId() {
        return id;
    }
  
    int getGrade() {
        return grade;
    }

    float getPrice() { 
        return price;
    }

  /*   Student(string id, int grade, float price, string name, int age, string gender) {
        this->id = id;
        this->grade = grade;
        this->price = price;
        this->name = name;
        this->age = age;
        this->gender = gender;
    } */

    void showLoadingScreen() {
        for (int i = 0; i < 5; i++) {
            cout << "Loading";
            for (int j = 0; j < i; j++) {
                cout << ".";
            }
            cout << "\r";  // Carriage return to overwrite the previous line
            sleep(1);  
        }
        cout << endl;
    }
    
    void input_username_age_gender_email(){
        cout << "\n\nEnter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your gender: ";
        getline(cin, gender);
        cout<<"Enter your email:";
        getline(cin,email);
        cout<< "Enter your age: ";
        cin.ignore();
        cin>>age;
    }
    void display_school_name() {
        cout << left << setw(50) << "" << "******************************" << endl;
        cout << left << setw(50) << "" << " *     RSH Coding Club      *" << endl;
        cout << left << setw(50) << "" << "******************************" << endl;
        
  
        
    }


   
    void Enrollment(void (Student::*input_username_age_gender_email)()) {
        
         cout << "Our school provides students 5 programming language choices:\n\n";
        string Subjects[5] = {"C++", "Python", "Html,Css,Javascript", "Java", "Java_master"};
        for (int i = 0; i < 5; i++) {
            cout << Subjects[i] << endl;
        }
        string choice;
        cout<<"\n\nEnter your choice :";
        cin >> choice;
        
        // Convert the user input to lowercase
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "c++") {
            fstream cpp_students_file;
            string line;
            int classroom_size=24;
            
            cpp_students_file.open("cpp_students_file.txt",ios::in);
            while(classroom_size)
            
            (this->*input_username_age_gender_email)();
            
            cpp_students_file.open("cpp_students_file.txt",ios::app);
            cpp_students_file<< name << " " <<gender<<" "<<email<<" "<<age << endl; 

            if(!cpp_students_file){
                cout<<"cpp_students_file is not found!"<<endl;
            }
            classroom_size--;            
            cpp_students_file.close();
        } else {
            cout << "You selected: " << choice << endl;
        }
    }
   
};

int main() {
    Student stu;
    stu.showLoadingScreen();
    stu.display_school_name();
    /* stu.input_username_age_gender_email();  */

   
    system("cls"); // Use "cls" for Windows, "clear" for Unix-like systems
     vector<string> menu = {
        "1. Information",
        "2. Enrollment",
        "3. View our students' source code",
        "4. Search Student ID",
        "5. Update Student ID",
        "6. Display students list",
        "7. Exit Application"
    };

    int currentOption = 0;
    char key;

    while (true) {
        
        system("cls");

        
        stu.display_school_name();
        for (int i = 0; i < menu.size(); ++i) {
            if (i == currentOption) {
                cout << "-> " << menu[i] << "\n"; // Highlight current option
            } else {
                cout << "   " << menu[i] << "\n";
            }
        }

        
        key = _getch(); // Windows-specific; use `getch()` for Linux

        if (key == 72) { 
            currentOption = (currentOption - 1 + menu.size()) % menu.size();
        } 
        else if (key == 80) { 
            currentOption = (currentOption + 1) % menu.size();
        }
         else if (key == '\r') { 
            system("cls");
            if (menu[currentOption] == "2. Enrollment") {
                stu.display_school_name();
                cout << "You selected: " << menu[currentOption] << "\n";
                stu.Enrollment(&Student::input_username_age_gender_email);
            }
            
            system("pause"); // Wait before returning to the menu
        }
    }
    return 0;
}