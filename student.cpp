#include "student.h"
#include "marks.h"

std::ostream& operator<<(std::ostream& stream, Institute i){
     switch(i){
          case IIT: stream << "Институт информационных технологий"; break;
          case IAI: stream << "Институт искусственного интеллекта"; break;
          case ICS: stream << "Институт кибербезопасности и цифровых технологий"; break;
          case Industrial: stream << "Институт персппективных технологий и индустриального программирования"; break;
          case RadEl: stream << "Институт радиоэлектроники и информатики"; break;
          case IMT: stream << "Институт технологий управления"; break;
          case Chem: stream << "Институт тонких химических технологий им. М.В. Ломоносова"; break;
      }
      return stream;
}

Student::Student(const char* n, Date& b, int e, Institute i, const char* dep, const char* grp, const char* id, bool s, std::vector<std::vector<std::string>> m){
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
    marks = m;
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

const char* Student::Sex(){
    if(sex) return "Муж.";
    else return "Жен.";
}

const char* Student::Name(){
    return name;
}

std::string Student::Birth(){
    std::string result = "";
    if(birth->day < 10) result += "0";
    result = result + std::to_string(birth->day) + ".";
    if(birth->month < 10) result += "0";
    result = result + std::to_string(birth->month) + "." + std::to_string(birth->year);
    return result;
}

std::string Student::Enroll(){
    std::string result = "";
    result = std::to_string(enroll) + "г.";
    return result;
}

const char* Student::Institut(){
     switch(inst){
          case IIT: return "Институт информационных технологий";
          case IAI: return "Институт искусственного интеллекта"; 
          case ICS: return "Институт кибербезопасности и цифровых технологий"; 
          case Industrial: return "Институт персппективных технологий и индустриального программирования";
          case RadEl: return "Институт радиоэлектроники и информатики";
          case IMT: return "Институт технологий управления"; 
          case Chem: return "Институт тонких химических технологий им. М.В. Ломоносова"; 
          default: return "Unknown Institute Error";
    }
}

const char* Student::Department(){
    return department;
}

const char* Student::Group(){
    return group;
}

const char* Student::Identification(){
    return ID;
}

std::string Student::Mark(int sessionNumber, int subjNumber){
    return marks[sessionNumber][subjNumber];
}



