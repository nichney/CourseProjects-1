#include <iostream>
#include "marks.h"
#include "student.h"

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

int main(){
    Date* myBirth = new Date{2005, 11, 9};
    
    Marks *m = new Marks();
    
    Student FIRST("Osmolovsky K.A.", *myBirth, 2023, ICS, "КБ-2",  "БББО-04-23", "123Ad", true, *m);
    
    FIRST.changeSex();
    FIRST.changeInstitute(IIT);

    return 0;
}
