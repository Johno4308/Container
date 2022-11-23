#ifndef POPUPVIEW_H
#define POPUPVIEW_H

/*Used to display the about and help popup windows
 * without having to create separate classes for each*/

#include <QDialog>
class QTextEdit;
class QPushButton;

class popupview : public QDialog
{
public:
    popupview();
    ~popupview();
    //Display the file located in the path of fileName
    void display(QString fileName);

private:
    QTextEdit *_textEdit;
    QPushButton *_butClose;
};

#endif // POPUPVIEW_H
