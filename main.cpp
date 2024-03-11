#include <iostream>
#include <vector>
#include <cstring>

#include "marks.h"
#include "student.h"

extern std::ostream& operator<<(std::ostream& stream, Institute i);

int main(){
    Date* myBirth = new Date{2005, 11, 9};
    
    Marks *m = new Marks();
    std::vector<std::vector<std::string>> marks;
    std::vector<std::string> FirstSem;
    FirstSem.push_back(std::string("Хор."));
    FirstSem.push_back(std::string("Отл."));
    FirstSem.push_back(std::string("Отл."));
    FirstSem.push_back(std::string("Хор."));
    marks.push_back(FirstSem);

    Student FIRST("Osmolovsky K.A.", *myBirth, 2023, ICS, "КБ-2",  "БББО-04-23", "!$**ILOVERUSSIA@@*", true, marks);
    
    FIRST.changeSex();
    FIRST.changeInstitute(IIT);

    return 0;
}
