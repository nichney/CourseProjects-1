#include <iostream>
#include "marks.h"
#include "student.h"


int main(){
    Date* myBirth = new Date{2005, 11, 9};
    
    Marks *m = new Marks();
    
    Student FIRST("Osmolovsky K.A.", *myBirth, 2023, Institute::ICS, "КБ-2",  "БББО-04-23", "123Ad", true, *m);
    
    FIRST.changeSex();

    return 0;
}
