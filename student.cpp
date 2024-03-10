#include "student.h"
#include "marks.h"

Student::Student(const char* n, Date& b, int e, Institute i, const char* dep, const char* grp, const char* id, bool s, Marks& m){
    name = nullptr;
    department = nullptr;
    group = nullptr;
    ID = nullptr;

    name = strdup(n);
    birth = &b;
    enroll = e;
    inst = i;
    department = strdup(dep);
    group = strdup(grp);
    ID = strdup(id);
    sex = s;
    marks = &m;
}

Student::~Student(){
    if(name != nullptr){
        delete[] name;
    }
    if(birth != nullptr){
        delete birth;
    }
    if(department != nullptr){
        delete[] department;
    }
    if(group != nullptr){
        delete[] group;
    }
    if(ID != nullptr){
        delete[] ID;
    }
    if(marks != nullptr){
        delete marks;
    }

}

void Student::changeName(const char* n){
    name = strdup(n);
}

void Student::changeBirth(int y, int m, int d){
    delete birth;
    Date *newBirth = new Date{y, m, d};
    birth = newBirth;
}

void Student::changeEnroll(int e){
    enroll = e;
}

void Student::changeInstitute(Institute i){
    inst = i;
}

void Student::changeDepartment(const char* d){
    department = strdup(d);
}

void Student::changeGroup(const char* g){
    group =  strdup(g);
}

void Student::changeID(const char* id){
    ID = strdup(id);
}

void Student::changeSex(){
    sex = !sex;
}



