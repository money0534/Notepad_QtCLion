//
// Created by Shinelon on 2018/12/26.
//

#include "EmpModel.h"


EmpModel::EmpModel() : name(""), id(""), gender("男"), age(0), dept("研发部"),
                       hobby("") {}

const QString &EmpModel::getName() const {
    return name;
}

void EmpModel::setName(const QString &name) {
    EmpModel::name = name;
}

const QString &EmpModel::getId() const {
    return id;
}

void EmpModel::setId(const QString &id) {
    EmpModel::id = id;
}

const QString & EmpModel::getGender() const {
    return gender;
}

void EmpModel::setGender(const QString & gender) {
    EmpModel::gender = gender;
}

int EmpModel::getAge() const {
    return age;
}

void EmpModel::setAge(int age) {
    EmpModel::age = age;
}

const QString &EmpModel::getDept() const {
    return dept;
}

void EmpModel::setDept(const QString &dept) {
    EmpModel::dept = dept;
}

const QString &EmpModel::getHobby() const {
    return hobby;
}

void EmpModel::setHobby(const QString &hobby) {
    EmpModel::hobby = hobby;
}
