//
// Created by Shinelon on 2018/12/26.
//

#include <QString>

#ifndef NOTEPAD_EMPMODEL_H
#define NOTEPAD_EMPMODEL_H


class EmpModel {

public:
    EmpModel();

    const QString &getName() const;

    void setName(const QString &name);

    const QString &getId() const;

    void setId(const QString &id);

    const QString & getGender() const;

    void setGender(const QString & gender);

    int getAge() const;

    void setAge(int age);

    const QString &getDept() const;

    void setDept(const QString &dept);

    const QString &getHobby() const;

    void setHobby(const QString &hobby);

private:
    QString name;
    QString id;
    QString  gender;
    int age;
    QString dept;
    QString hobby;
};


#endif //NOTEPAD_EMPMODEL_H
