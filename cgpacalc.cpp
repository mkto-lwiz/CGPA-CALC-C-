#include <bits/stdc++.h>
using namespace std;

// double calculate_cgpa(){

// }
double getGradePoint(char c) {
    c = toupper(c); // Handle lowercase input
    
    if (c == 'A') {
        return 4.0;
    }
    else if (c == 'B') {
        return 3.0;
    }
    else if (c == 'C') {
        return 2.0;
    }
    else if (c == 'D') {
        return 1.0;
    }
    else {
        return 0.0; // 'F' or invalid grade
    }
}
struct classinfo
{
    /* data */
    char Grade;
    int credit_hour;
    double grade_point;


    classinfo() : Grade('F'), credit_hour(0), grade_point(0.0) {}
    classinfo(char a, int b){
        Grade = a;
        credit_hour = b;
        grade_point = getGradePoint(a);

    }
    void display() const{
        cout <<"Grade : "<< Grade << endl;
        cout <<"Credit hour : "<< credit_hour << endl;
        cout <<"Course Grade Point : " << grade_point << endl;
    }

};

int main(){
    int n;
    cout << "Enter the number of course taken throughout the study : ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    map<string,classinfo> course_taken;
    for (int i = 1; i < n+1; i++)
    {
        /* code */
        string class_name_temporary;
        cout << "Enter the "<< i << "st name of course taken :";
        getline(cin,class_name_temporary);
        char grade_temp;
        cout << "Enter its grade : ";
        cin >> grade_temp;
        int course_credit_temp;
        cout << "Enter its credit hour :";
        cin >> course_credit_temp;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer after numeric input

        course_taken[class_name_temporary] = classinfo(grade_temp, course_credit_temp);
    }

    cout << "\nCourse details:\n";
    for (const auto& entry : course_taken) {
        cout << "Course name: " << entry.first << "\n";
        entry.second.display();
        cout << "-----------------\n";
    }

    return 0;
}


