#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include <vector>

#include <iostream> // FOR DEBUG!!!

struct Date {
    int year, month, day; 
};

enum Institute { IIT,
                IAI,
                ICS,
                Industrial,
                RadEl,
                IMT,
                Chem}; 
                                                               // IIT - Институт информационных технологий
                                                               // IAI - Институт искусственного интеллекта
                                                               // ICS - Институт кибербезопасности и цифровых технологий
                                                               // Industrial - Институт перспективных технологий и индустриального программирования
                                                               // RadEl - Институт радиоэлектроники и информатики
                                                               // IMT - Институт технологий управления
                                                               // Chem - Институт тонких химических технологий им. М.В. Ломоносова

class Student {
    private:
        const char* name;
        Date* birth;
        int enroll; // year of enroll to college
        Institute inst; // факультет (институт)
        const char* department; // кафедра
        const char* group;
        const char* ID; // Номер зачётной книжки
        bool sex; // Пол, 0 - женский, 1 - мужской
        std::vector<std::vector<std::string>> marks; // Оценки за весь период обучения (массив строк)
    public:
        Student(const char*, Date&, int, Institute, const char*, const char*, const char*, bool, std::vector<std::vector<std::string>>);
        ~Student();

        void changeName(const char*); // +
        void changeBirth(int, int, int); // +
        void changeEnroll(int); // +
        void changeInstitute(Institute inst); // +
        void changeDepartment(const char*);
        void changeGroup(const char*);
        void changeID(const char*);
        void changeSex();

        // getters
        const char* Name();
        std::string Birth();
        std::string Enroll();
        const char* Institut();
        const char* Department();
        const char* Group();
        const char* Identification();
        const char* Sex();
        std::string Mark(int, int);

};




#endif
