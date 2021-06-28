#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>
#include<QTableWidget>
#include<QGridLayout>
#include <QHeaderView>
#include<string>
#include<iostream>
using namespace std;

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick1();
    void onClick2();

  private:
    QPushButton *b1,*b2,*b3,*b4;
    QLabel *l,*label1,*label2,*label3,*label1x,*label2x,*label3x,*label4x,*label1y,*label2y,*label3y,*label4y;
    QTableWidget *table;
    int index;
    int row;
    
  protected:
    void keyPressEvent(QKeyEvent * e);
};

Click::Click(QWidget *parent)
    : QWidget(parent) {        
        
  table=new QTableWidget();
  
  table->setRowCount(0);
  table->setColumnCount(7);
  table->horizontalHeader()->setDefaultSectionSize(125);
  table->verticalHeader()->setDefaultSectionSize(16);
  
   
  //table->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 42pt; }");
  
  QStringList list;
    
    list<< "Id" << "Artikl"<<"Kolicina"<<"Pdv"<<"Mjera"<<"Cijena"<<"Iznos";
    
    table->setHorizontalHeaderLabels(list);
  
  index=0;
  row=0;
  
  
  label1=new QLabel("Label 1");
  label2=new QLabel("");
  label3=new QLabel("Label 3");
  label3->setStyleSheet("font: bold;font-size: 30px;height: 30px;width: 120px;");
  
  label1x=new QLabel("Vrijeme :");
  label2x=new QLabel("Datum :");
  label3x=new QLabel("Racun :");
  label4x=new QLabel("Operator :");
  label1x->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label2x->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label3x->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label4x->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  
  label1y=new QLabel("Labely 1");
  label2y=new QLabel("Labely 2");
  label3y=new QLabel("Labely 3");
  label4y=new QLabel("Labely 4");
  label1y->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label2y->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label3y->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  label4y->setStyleSheet("font-size: 15px;height: 30px;width: 120px;");
  

  QGridLayout *grid=new QGridLayout();
  QGridLayout *grid1 = new QGridLayout();
  
  grid1->addWidget(label1x,0,0,1,1);
  grid1->addWidget(label2x,1,0,1,1);
  grid1->addWidget(label3x,2,0,1,1);
  grid1->addWidget(label4x,3,0,1,1);
  grid1->addWidget(label1y,0,1,1,1,Qt::AlignLeft);
  grid1->addWidget(label2y,1,1,1,1,Qt::AlignLeft);
  grid1->addWidget(label3y,2,1,1,1,Qt::AlignLeft);
  grid1->addWidget(label4y,3,1,1,1,Qt::AlignLeft);
  
  
  
  grid->addLayout(grid1,0,0,1,1);
  grid->addWidget(label2,0,1,1,1);
  grid->addWidget(label3,0,4,1,1,Qt::AlignCenter);
  
  
  QHBoxLayout *h_box = new QHBoxLayout();
  h_box->setSpacing(5);
  
 
  
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  
  v_box->addLayout(grid);
  //v_box->addWidget(b);
  v_box->addWidget(table);
  b1=new QPushButton("Push me 1");
  b2=new QPushButton("Push me 2");
  b3=new QPushButton("Push me 3");
  b4=new QPushButton("Push me 4");
  h_box->addWidget(b1);
  h_box->addWidget(b2);
  h_box->addWidget(b3);
  h_box->addWidget(b4);
  v_box->addLayout(h_box);
  
  this->setLayout(v_box);

  connect(b1, &QPushButton::clicked, this, &Click::onClick1);
  connect(b2, &QPushButton::clicked, this, &Click::onClick2);
 
 this->resize(920,600);
  this->setWindowTitle("Blagajna");
  this->show();
 
}

void Click::onClick1() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
}

void Click::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  row=table->rowCount();
    table->insertRow(row);
    
    table->setItem(index,0,new QTableWidgetItem("igor"));
    table->setItem(index,1,new QTableWidgetItem("igor"));
    table->setItem(index,2,new QTableWidgetItem("igor"));

    index++;
}

void Click::keyPressEvent(QKeyEvent *event) {
QTextStream out(stdout);
  
   if (event->key() == Qt::Key_Return) {
       row=table->rowCount();
    table->insertRow(row);
    
    table->setItem(index,0,new QTableWidgetItem("igor"));
    table->setItem(index,1,new QTableWidgetItem("igor"));
    table->setItem(index,2,new QTableWidgetItem("igor"));
    table->setItem(index,3,new QTableWidgetItem("igor"));
    table->setItem(index,4,new QTableWidgetItem("igor"));
    table->setItem(index,5,new QTableWidgetItem("igor"));
    table->setItem(index,6,new QTableWidgetItem("igor"));
    
    
    index++;
   }
   if(event->key()==Qt::Key_Q)
    {
    std::string myString = event->text().toStdString();
        out << "You Released Key Q" << endl;
        qDebug() << " ChildLineEdit,keyPressEvent , key : " << event->text();
        cout<<myString<<endl;
    }
    if(event->key()==Qt::Key_B)
    {
    std::string myString = event->text().toStdString();
        out << "You Released Key Q" << endl;
        qDebug() << " ChildLineEdit,keyPressEvent , key : " << event->text();
        cout<<myString.c_str()<<endl;
    }
   
    {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    int key = keyEvent->key();
QString text = keyEvent->text();
        out << text << endl;
    } 
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
