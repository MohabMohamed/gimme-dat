#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list = ui->listWidget;
    list->setWindowFlags(Qt::WindowFlags(
       Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint));
     list->setAttribute(Qt::WA_ShowWithoutActivating);
     // ////////
    QFile file("/home/mohab/projects/gimme-dat/Search Links (Scenario 1 & 2).txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    else {
        QTextStream in(&file);
        while (!in.atEnd())
          {

             QString line = in.readLine();
             QStringList tmp = line.split(",");
                     wieghts.push_back(tmp.value(0).toInt());
            words.push_back(tmp.value(1).toLower());
          }
    }
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),ui->listWidget,SLOT(setVisible(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
}

size_t MainWindow::uiLevenshteinDistance(string &str1, string &str2)
    {
        const size_t m(str1.size());
        const size_t n(str2.size());

        if (m == 0) return n;
        if (n == 0) return m;

        size_t *c = new size_t[n + 1];

        for (size_t k = 0; k <= n; k++) c[k] = k;

        size_t i = 0;
        for (string::const_iterator it1 = str1.begin(); it1 != str1.end(); ++it1, ++i)
        {
            c[0] = i + 1;
            size_t corner = i;

            size_t j = 0;
            for (string::const_iterator it2 = str2.begin(); it2 != str2.end(); ++it2, ++j)
            {
                size_t upper = c[j + 1];
                if (*it1 == *it2)
                {
                    c[j + 1] = corner;
                }
                else
                {
                    size_t t(upper<corner ? upper : corner);
                    c[j + 1] = (c[j]<t ? c[j] : t) + 1;
                }

                corner = upper;
            }
        }

        size_t r = c[n];
        delete[] c;
 return r;
    }

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if (ui->lineEdit->text().isEmpty()) {
        list->hide();
        return;
      }
      list->clear();
      list->addItem(ui->lineEdit->text());
      list->addItem(tr("Google: ") + ui->lineEdit->text());

      if (!list->isVisible()) list->show();

}

