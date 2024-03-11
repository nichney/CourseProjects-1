#include "marks.h"

Disciplines::Disciplines(){
    name = nullptr;
    mark = nullptr;
}

Disciplines::Disciplines(const char* n, const char* m){
    name = strdup(n);
    mark = strdup(m);
}

Disciplines::~Disciplines(){
    delete name;
    delete mark;
}

Disciplines& Disciplines::operator= (const Disciplines &d){
    if(&d != this){
        if(name != nullptr)
            delete[] name;
        if(mark != nullptr)
            delete[] mark;
        if(d.name != nullptr)
            name = strdup(d.name);
        if(d.mark != nullptr)
            mark = strdup(d.mark);
    }
    return *this;
}

void Disciplines::changeName(const char* n){
    delete name;
    name = strdup(n);
}

void Disciplines::changeMark(const char* m){
    delete mark;
    mark = strdup(m);
}

const char* Disciplines::Name(){
    return name;
}
const char* Disciplines::Mark(){
    return mark;
}

Sessions::Sessions(){
    size = 0;
    d = nullptr;
}

Sessions::~Sessions(){
    if(d != nullptr)
        delete[] d;
}

int Sessions::removeSubject(const char* toRemove){
    if(size < 2)
        return -1; // too small session!
    int newsize = size;
    for(int i=0; i< size; i++){
        if(strcmp(d[i].Name(), toRemove) == 0){
            newsize--;
        } 
    }
    if(newsize == size)
        return -2; // no such subject!
    Disciplines *buf = new Disciplines[newsize];
    int j=0;
    for(int i=0; i < size; i++){
        if(strcmp(d[i].Name(), toRemove) != 0){
            buf[i] = d[i];
            j++;
        }
    }
    delete[] d;
    size = newsize;
    d = buf;
    return 0;
}

int Sessions::addSubject(const char* name, const char* mark){
    if(size == 10)
        return -1; // too many subjects
    Disciplines *buf = new Disciplines[size+1];
    for(int i=0; i< size; i++){
        buf[i] = d[i];
    }
    Disciplines last(name, mark);
    buf[size] = last;
    if(d != nullptr) delete[] d;
    d = buf;
    return 0;
}

Marks::Marks(){
    int amountOfSessions;
    do{
        std::cout << "Сколько сессий вы хотите добавить этому ученику?\n";
        std::cin >> amountOfSessions;
        if(amountOfSessions < 1 || amountOfSessions > 9) std::cout << "Число сессий должно быть целым числом, не превышающим 10. попробуйте ещё раз:\n";
    }while(amountOfSessions < 1 || amountOfSessions > 9);
    s = new Sessions[amountOfSessions];
    for(int i=0; i< amountOfSessions; i++){
        int selection;
        std::string n, m;
        do{
            std::cout << "Сессия №" << i+1 << "\n1 - добавить предмет\n2 - перейти к следующей сессии\n";
            std::cin >> selection;
            if(selection == 1){
                std::cout << "Введите название дисциплины: ";
                std::cin >> n;
                std::cout << "\nВведите оценку по этой дисциплине: ";
                std::cin >> m;
                int result = s[i].addSubject(n.c_str(), m.c_str());
                if(result == -1){ 
                    std::cout << "Максимальное число дисциплин за семестр - десять.";
                    selection = 2;
                }
            }
        }while(selection != 2);
    }
}

Marks::~Marks(){
    if(s != nullptr)
        delete[] s;
}












