#include "student.h"
#include "marks.h"

/*
void copyString(const char* to, const char* from){
    // local function to copy from const char* to empty const char*
    const size_t length = strlen(from); // get length of the name
    if(to == nullptr){
        to = new char[length + 1];
    }
    else{
        delete[] to; // delete if not empty
        to = new char[length + 1];
    }
    strncpy(to, from, length); 
}
*/
Student::Student(const char* n, Date& b, int e, Institute i, const char* dep, const char* grp, const char* id, bool s, Marks& m){
    name = nullptr;
    department = nullptr;
    group = nullptr;
    ID = nullptr;

  //  copyString(name, n);
    name = strdup(n);
    birth = &b;
    enroll = e;
    inst = i;
   // copyString(department, dep);
   // copyString(group, grp);
    //copyString(ID);
    department = strdup(dep);
    group = strdup(grp);
    ID = strdup(id);
    sex = s;
    marks = &m;
}

void Student::changeName(const char* n){
    //copyString(name, n);
    name = strdup(n);
}
