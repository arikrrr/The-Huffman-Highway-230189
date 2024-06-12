#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int rollNo;
    vector<string> course;
    int total_marks;
};

class StudentRecord{
    private:
        vector<Student> list_student;
    public:
        void insertRecord(string name, int roll, vector<string> course, int tot){
            Student new_student = {name,roll,course,tot};
            list_student.push_back(new_student);
            cout << name << " was added....\n\n\n\n";
        }


        void deleteRecord(int roll){
            for(auto it = list_student.begin(); it!=list_student.end(); it++){
                if((*it).rollNo==roll){
                    list_student.erase(it);
                    break;
                }
            }
            cout << "Deletion Successful.\n";
        }


        void showStudentRecord(int roll){
            if(searchStudentRecord(roll))
                {
                for(auto it = list_student.begin(); it!=list_student.end(); it++){
                    if((*it).rollNo==roll){
                        Student s = *it;
                        cout << "Name: " << s.name << endl;
                        cout << "Roll Number: "<<s.rollNo << endl;
                        cout << "Courses: \n";
                        for(auto tp: s.course){
                            cout << tp << endl;
                        }
                        cout << "Total Marks: "<<s.total_marks<<endl;
                    }
                }
            }
            else{
                cout << "Record Not Found";
            }
        }


        bool searchStudentRecord(int roll){
            for(auto it = list_student.begin(); it!=list_student.end(); it++){
                if((*it).rollNo==roll){
                    return true;
                }
            }
            return false;
        }        
};

int main(){
    StudentRecord sys;
    int n=1;
    while(n!=0)
    {
        cout << "1. Insert student record\n";
        cout << "2. Delete student record\n";
        cout << "3. Show student record\n";
        cout << "4. Search student record\n";
        cout << "5. Enter 0 to exit\n";
        cout << "Enter your choice: ";
        cin>> n;
        string name;
        int rollNo;
        int num;
        vector<string> course;
        int total_marks;
        switch (n)
        {
        case 1:
            cout << "Enter name:\n";
            cin.ignore();
            getline(cin, name);
            cout << "Enter roll No:\n";
            cin >> rollNo;
            course.clear();
            cout << "Enter number of courses:\n"; cin >>num;
            for(int i=0; i<num; i++){
                string c;
                cout << "Enter course "<< i+1<<" " ;
                cin >> c; course.push_back(c);
            }
            cout << "Enter total marks:\n";
            cin >> total_marks;
            sys.insertRecord(name, rollNo, course, total_marks);
            break;
        case 2:
            cout << "Enter roll number of student:\n";
            cin >> rollNo;
            sys.deleteRecord(rollNo);
            break;
        case 3:
            cout << "Enter roll number of student:\n";
            cin >> rollNo;
            sys.showStudentRecord(rollNo);
            break;
        case 4:
            cout << "Enter roll number of student:\n";
            cin >> rollNo;
            if(sys.searchStudentRecord(rollNo)){
                cout << "Found\n";
            }
            else{
                cout << "Not Found\n";
            }
            break;
        case 0:
            cout << "Exiting....\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
    return 0;
}