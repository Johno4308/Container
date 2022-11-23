//COS3711 ASSIGNMENT 3
//Johnathan David Cookson 8812125074088
//8812125074088
#ifndef CONTAINERCODE_H
#define CONTAINERCODE_H
#include <QDate>
#include <QObject>

//class used to construct my container codes
class ContainerCode : public QObject
{
    Q_OBJECT

public:
    ContainerCode();
    QString createCode(char Type, int uniqueNum);
    void setCode(QString code);

private:
    QString _code;
};

#endif // CONTAINERCODE_H



