#include "popupview.h"
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QDate>
#include <QHostAddress>

popupview::popupview():
    _textEdit{new QTextEdit},
    _butClose{new QPushButton(tr("Close"))}
{
    //pre-set
    _textEdit->setReadOnly(true);
    //layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(_textEdit);
    layout->addWidget(_butClose);
    setLayout(layout);
    //connections
    connect(_butClose, &QPushButton::clicked, this, &QDialog::close);

}

popupview::~popupview()
{
    deleteLater();
}

void popupview::display(QString fileName)
{
    //reads file an appends it to text edit
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString readLines;
        while(!in.atEnd())
        {
            /*reads each line and appends to to the textedit with modifications made to certain key words*/
            QString line = in.readLine();
            if(line.contains("[todayDate]"))
            {
                QDate date = QDate::currentDate();
                line.replace("[todayDate]", date.toString("dd/MM/yyyy"));
            }else if(line.contains("[qtversion]")){
                line.replace("[qtversion]", qVersion());
            }else if(line.contains("[platform")){
                line.replace("[platform]", qVersion());
            }else if(line.contains("[localIp]")){
                line.replace("[localIp]", QHostAddress(QHostAddress::LocalHost).toString());
            }
            readLines.append(line);
        }
        //to show the HTML and inline CSS formatting
        _textEdit->setHtml(readLines);

        //alter the apperance of the popup formatting
        _textEdit->setFixedHeight(_textEdit->height());
        this->resize(sizeHint());
        _textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        file.close();
        this->show();
    }else
        QMessageBox::warning(this, tr("Warning"), tr("Could not open file"));
}
