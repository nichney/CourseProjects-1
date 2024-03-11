#include "marks.h"

Disciplines::Disciplines(){
    name = nullptr;
}

Disciplines::Disciplines(const char* n){
    name = strdup(n);
}

Disciplines::~Disciplines(){
    delete name;
}

Disciplines& Disciplines::operator= (const Disciplines &d){
    if(&d != this){
        if(name != nullptr)
            delete[] name;
        if(d.name != nullptr)
            name = strdup(d.name);
    }
    return *this;
}

void Disciplines::changeName(const char* n){
    delete name;
    name = strdup(n);
}


const char* Disciplines::Name(){
    return name;
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

int Sessions::addSubject(const char* name){
    if(size == 10)
        return -1; // too many subjects
    for(int i=0; i<size; i++){
        if(strcmp(d[i].Name(), name) == 0)
            return -2; // subject already used!
    }
    Disciplines *buf = new Disciplines[size+1];
    for(int i=0; i< size; i++){
        buf[i] = d[i];
    }
    Disciplines last(name);
    buf[size] = last;
    if(d != nullptr) delete[] d;
    d = buf;
    return 0;
}

int Sessions::editDisciplineName(const char* to, const char* from){
    for(int i=0; i<size; i++){
        if(strcmp(d[i].Name(), from) == 0){
            d[i].changeName(to);
            return 0;
        }
    }
    return -1; // No such subject

}


Sessions& Sessions::operator= (const Sessions &s){
    if(&s != this){
        if(d != nullptr)
            delete[] d;
        if(s.d != nullptr){
            size = s.size;
            for(int i=0; i<size; i++){
                d[i] = s.d[i];
            }
        }
    }
    return *this;
}

Marks::Marks(){
    int amountOfSessions;
    do{
        std::cout << "Сколько сессий вы хотите добавить?\n";
        std::cin >> amountOfSessions;
        if(amountOfSessions < 1 || amountOfSessions > 9) std::cout << "Число сессий должно быть целым числом, не превышающим 10. попробуйте ещё раз:\n";
    }while(amountOfSessions < 1 || amountOfSessions > 9);
    s = new Sessions[amountOfSessions];
    for(int i=0; i< amountOfSessions; i++){
        int selection;
        std::string n;
        do{
            std::cout << "Сессия №" << i+1 << "\n1 - добавить предмет\n2 - перейти к следующей сессии\n";
            std::cin >> selection;
            if(selection == 1){
                std::cout << "Введите название дисциплины: ";
                std::cin >> n;
                int result = s[i].addSubject(n.c_str());
                if(result == -1){ 
                    std::cout << "Максимальное число дисциплин за семестр - десять.\n";
                    selection = 2;
                }
                else if(result == -2){
                    std::cout << "Предмет с таким названием уже существует\n";
                }
            }
        }while(selection != 2);
    }
}

Marks::~Marks(){
    if(s != nullptr)
        delete[] s;
}


Marks& Marks::operator= (const Marks &m){
    if(&m != this){
        if(s != nullptr)
            delete[] s;
        if(m.s != nullptr){
            size = m.size;
            for(int i=0; i<size; i++){
                s[i] = m.s[i];
            }
        }
    }
    return *this;
}

void Marks::addSubject2Session(){
    int sessionNumber;
    std::string name;
    std::cout << "\nВведите номер сессии, в которую вы хотите добавить предмет: ";
    std::cin >> sessionNumber;
    if(sessionNumber > size){
        std::cout << "\nНет такой сессии\n";
        return;
    }
    sessionNumber--;
    std::cout << "\nВведите название предмета, который вы хотите добавить: ";
    std::cin >> name;
    int returnedCode = s[sessionNumber].addSubject(name.c_str());
    if(returnedCode == -1){
        std::cout << "\nМаксимальное число дисциплин за семестр (10) уже достигнуто\n";
        return;
    }
    if(returnedCode == -2){
        std::cout << "\nДисциплина с таким названием уже есть в семестре\n";
        return;
    }
}

void Marks::addSession(){
    if(size == 9){
        std::cout << "\nДостигнуто максимальное число сессий (9)\n";
    }
    Sessions *newS = new Sessions[size+1];
    for(int i=0; i<size; i++){
        newS[i] = s[i];
    }
    int selection;
    std::string n;
    size++;
    do{
        std::cout << "Добавьте предметы в новую Сессию:\n" << "\n1 - добавить предмет\n2 - перейти к следующей сессии\n";
        std::cin >> selection;
        if(selection == 1){
            std::cout << "Введите название дисциплины: ";
            std::cin >> n;
            int result = newS[size].addSubject(n.c_str());
            if(result == -1){ 
                std::cout << "Максимальное число дисциплин за семестр - десять.\n";
                selection = 2;
            }
            else if(result == -2){
                std::cout << "Предмет с таким названием уже существует\n";
            }
        }
    }while(selection != 2);
    if(s != nullptr) delete[] s; 
    s = newS;
}


void Marks::removeSubjectFromSession(){
    int sessionNumber;
    std::string toRemove;
    std::cout << "\nВведите номер сессии, из которой следует убрать дисциплину: \n";
    std::cin >> sessionNumber;
    if(sessionNumber > size){
        std::cout << "\nНет такой сессии!\n";
        return;
    }
    sessionNumber--;
    std::cout << "\nВведите название предмета для удаления:\n";
    std::cin >> toRemove;
    int code = s[sessionNumber].removeSubject(toRemove.c_str());
    if(code == -1){
        std::cout << "\nИз сессии нельзя удалить последнюю дисциплину!\n";
        return;
    }
    else if(code == -2){
        std::cout << "\nВ сессии нет дисциплины с таким названием!\n";
    }
}

void Marks::removeSession(){
    int sessionNumber;
    std::string toRemove;
    std::cout << "\nВведите номер сессии, которую следует удалить: \n";
    std::cin >> sessionNumber;
    if(sessionNumber > size || sessionNumber < 0){
        std::cout << "\nНет такой сессии!\n";
        return;
    }
    sessionNumber--;

    if(size < 2){
        std::cout << "\nНе может остаться меньше одной сессии!\n";
        return;
    }
    int newsize = size - 1;
    Sessions *buf = new Sessions[newsize];
    int j=0;
    for(int i=0; i < size; i++){
        if(i != sessionNumber){
            buf[i] = s[i];
            j++;
        }
    }
    delete[] s;
    size = newsize;
    s = buf;
}

void Marks::editDisciplineName(){
    int sessionNumber;
    std::string toEdit, newString;
    std::cout << "\nВведите номер сессии, в которой вы хотите поменять название дисциплины: \n";
    std::cin >> sessionNumber;
    if(sessionNumber > size || sessionNumber < 0){
        std::cout << "\nНет такой сессии!\n";
        return;
    }
    sessionNumber--;
    std::cout << "\nВведите название дисциплины, которое вы хотите поменять: \n";
    std::cin >> toEdit;
    std::cout << "\nВведите новое название дисциплины: \n";
    std::cin >> newString;
    int code = s[sessionNumber].editDisciplineName(newString.c_str(), toEdit.c_str());
    if(code == -1){
        std::cout << "\nВ этой сессии нет дисциплины с таким названием для замены!\n";
    }

}


int Marks::getAmountOfSessions(){
    return size;
}

int Sessions::getAmountOfSubjects(){
    return size;
}

int Marks::getAmountOfSubjects(int ses){
    return s[ses].getAmountOfSubjects();
}








