#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
/* TODO: Initializer list 사용해 초기화 해보기 */
: midterm(midterm), final(final)
{};

float StudentRecord::getTotal() const {
    /* TODO */
    return getMidterm() + getFinal();
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student() 
: name(""), id(0)
/* TODO: Initializer list 사용해 초기화 해보기 */
{ };

Student::Student(const char *name, int id, float midterm, float final)
: name(name), id(id), record(midterm,final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{  };

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    this->record.updateScores(midterm, final);
}

