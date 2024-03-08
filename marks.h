#ifndef MARKS_H
#define MARKS_H

class Disciplines {
    private:
        const char* name; 
        const char* mark;
};


class Sessions {
    private:
        Disciplines *d;
        int size;

};


class Marks {
    private:
        Sessions *s;
        int size;
};

#endif
