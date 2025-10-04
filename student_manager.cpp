#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    Student s = {name, id, midterm, final};
    StudentManager::students[num_of_students] = s;
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    for (int i = 0; i<num_of_students; i++){
        if (students[i].getID() == id){
            num_of_students--;
            for(int j = i; j<num_of_students; j++){
                students[j] = students[j+1];
            }
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int id =student.getID();
    for (int i = 0; i<num_of_students; i++){
        if(students[i].getID()==id){
            students[i] = student;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int i = 0; i<num_of_students;i++){
        if(students[i].getID()==id){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float mid_best = 0;
    int stu_idx = 0;
    for(int i = 0; i<num_of_students; i++){
        float stu_mid = students[i].getRecord().getMidterm();
        if(stu_mid>mid_best){
            mid_best = stu_mid;
            stu_idx = i;
        }
    }
    return stu_idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float fin_best = 0;
    int stu_idx = 0;
    for(int i = 0; i<num_of_students; i++){
        float stu_fin = students[i].getRecord().getFinal();
        if(stu_fin>fin_best){
            fin_best = stu_fin;
            stu_idx = i;
        }
    }
    return stu_idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float tot_best = 0;
    int stu_idx = 0;
    for(int i = 0; i<num_of_students; i++){
        float stu_tot = students[i].getRecord().getTotal();
        if(stu_tot>tot_best){
            tot_best = stu_tot;
            stu_idx = i;
        }
    }
    return stu_idx;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float mid_sum = 0;
    for (int i = 0; i<num_of_students; i++){
        mid_sum += students[i].getRecord().getMidterm();
    }
    return mid_sum/num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float fin_sum = 0;
    for (int i = 0; i<num_of_students; i++){
        fin_sum += students[i].getRecord().getFinal();
    }
    return fin_sum/num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float tot_sum = 0;
    for (int i = 0; i<num_of_students; i++){
        tot_sum += students[i].getRecord().getTotal();
    }
    return tot_sum/num_of_students;
}

