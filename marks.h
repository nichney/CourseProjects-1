#ifndef MARKS_H
#define MARKS_H

#include <cstring>
#include <iostream>

class Disciplines {
    private:
        const char* name; 
    public:
        Disciplines();
        Disciplines(const char*);
        ~Disciplines();

        Disciplines& operator=(const Disciplines&);

        void changeName(const char*);
        
        const char* Name();
};


class Sessions{
    private:
        Disciplines *d;
        int size;
    public:
        Sessions();
        ~Sessions();
       
        Sessions& operator=(const Sessions&);

        int addSubject(const char*); // return codes: -1: too many subjects
                                     //               -2: subject already used
        int removeSubject(const char*); // return codes: -1: too small session
                                        //               -2: no such subject
        int editDisciplineName(const char*, const char*); // return codes: no such subject
        int getAmountOfSubjects();
};


class Marks {
    private:
        Sessions *s;
        int size;
    public:
        Marks();
        ~Marks();

        Marks& operator=(const Marks&);

        void addSubject2Session();
        void addSession();
        void removeSubjectFromSession();
        void removeSession();
        void editDisciplineName();

        int getAmountOfSessions();
        int getAmountOfSubjects(int);

};

#endif
