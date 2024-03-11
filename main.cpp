#include <iostream>
#include "marks.h"
#include "student.h"

extern std::ostream& operator<<(std::ostream& stream, Institute i);

int main(){
    Date* myBirth = new Date{2005, 11, 9};
    
    Marks *m = new Marks();
    
    Student FIRST("Osmolovsky K.A.", *myBirth, 2023, ICS, "КБ-2",  "БББО-04-23", "23Б0439", true, *m);
    
    FIRST.changeSex();
    FIRST.changeInstitute(IIT);
    FIRST.output();

    return 0;
}
