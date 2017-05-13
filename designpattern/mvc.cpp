//mvc -model view controller
//controller decouples model and view, acts as an interface
//between them. controller is responsible for data flow into the model and 
// also to update view as needed.

#include <iostream>

using namespace std;

class Student {
    public:
        Student(string name, int rollno): name{name}, rollno{rollno}{}
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        int getRollno(){
            return rollno;
        }
        void setRollno(int rollno){
            this->rollno = rollno;
        }
    private:
        string name;
        int rollno;
};

class StudentView {
    public:
        void printStudentDetails(string name, int rollno){
            cout <<"Student : [" <<" Name :" << name <<" Rollno :" << rollno <<" ].\n";
        }
};

class StudentController {
    public:
        StudentController(Student *student, StudentView *sv) : student{student},sv{sv}{}
        string getStudentName(){
            return student->getName();
        }
        void setStudentName(string name){
            student->setName(name);
        }
        int getStudentRollno(){
            return student->getRollno();
        }
        void setStudentRollno(int rollno){
            return student->setRollno(rollno);
        }
        void updateView(){
            sv->printStudentDetails(student->getName(), student->getRollno());
        }
    private:
        Student *student;
        StudentView *sv;
};

Student* getStudentFromDB(){
    Student* student = new Student("jack", 55);
    return student;
}

int main(){
    Student *student = getStudentFromDB();
    StudentView *sv = new StudentView;
    StudentController *sc = new StudentController(student, sv);
    sc->updateView();
    sc->setStudentName("tim");
    sc->updateView();
    sc->setStudentRollno(44);
    sc->updateView();
    return 0;
}
