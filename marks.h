#ifndef MARKS_H
#define MARKS_H

#include <cstring>
#include <iostream>


class Disciplines {
    private:
        const char* name; 
        const char* mark;
    public:
        Disciplines();
        Disciplines(const char*, const char*);
        ~Disciplines();

        Disciplines& operator=(const Disciplines&);

        void changeName(const char*);
        void changeMark(const char*);
        
        const char* Name();
        const char* Mark();
};


class Sessions{
    private:
        Disciplines *d;
        int size;
    public:
        Sessions();
        ~Sessions();
        
        int addSubject(const char*, const char*);
        int removeSubject(const char*);
};


class Marks {
    private:
        Sessions *s;
        int size;
    public:
        Marks();
        ~Marks();
};

#endif
