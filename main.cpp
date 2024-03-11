#include <iostream>
#include <vector>
#include <cstring>

#include "marks.h"
#include "student.h"

extern std::ostream& operator<<(std::ostream& stream, Institute i);

int main(){
    Date* myBirth = new Date{2005, 11, 9};
    
    Marks *m = new Marks();
    std::vector<std::string> marks;
    marks.push_back(std::string("Хор."));

    Student FIRST("Osmolovsky K.A.", *myBirth, 2023, ICS, "КБ-2",  "БББО-04-23", "!$**ILOVERUSSIA@@*", true, marks);
    
    FIRST.changeSex();
    FIRST.changeInstitute(IIT);
    FIRST.output();

    return 0;
}
