#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include<iostream>
#include<QMainWindow>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QSqlRecord>
#include <QSqlDriver>
#include <string>
#include <QFrame>
#include <QFormLayout>


using namespace std;


class centar{

public:
	centar(QWidget *window,int x,int y);

};

centar::centar(QWidget *window,int x,int y){
   QDesktopWidget *desktop = QApplication::desktop();

int screenWidth = desktop->width();
int screenHeight = desktop->height();

int xx = (screenWidth - x) / 2;
int yy = (screenHeight - y) / 2; 
   
 window->setFixedSize(x, y);
 window->move(xx,yy);



}


class Blagajna: public QWidget {
   
public:
    Blagajna(QWidget *parent = 0);
    ~Blagajna();
protected:

};
 
Blagajna::Blagajna(QWidget *parent): 
    QWidget(parent) 
{
    // Dummy UI
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("The Second Widget", this);
    layout->addWidget(l);
    centar po(this,350,300);
 //this->resize(350,150);
  this->setWindowTitle("Blagajna");
  this->show();
    
}
 
Blagajna::~Blagajna() {

QTextStream out(stdout);
out << "Zatvoreno blagajna" << endl;


 }
 
class Skladiste: public QWidget {
   
public:
    Skladiste(QWidget *parent = 0);
    ~Skladiste();
protected:

};
 
Skladiste::Skladiste(QWidget *parent): 
    QWidget(parent) 
{
    QHBoxLayout *hbox = new QHBoxLayout(this);

  QTableWidget *table = new QTableWidget();
  table->setRowCount(0);
  table->setColumnCount(6);
  table->horizontalHeader()->setDefaultSectionSize(140);
  table->verticalHeader()->setDefaultSectionSize(16);
  
   
  //table->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 42pt; }");
  
  QStringList list;
    
    list<< "Id" << "Artikl"<<"Pdv"<<"Kolicina"<<"Mjera"<<"Cijena";
    
    table->setHorizontalHeaderLabels(list);
    table->setFont(QFont("Times",13));
    
    QFont font = table->horizontalHeader()->font();
font.setPointSize(12);
table->horizontalHeader()->setFont( font ); 
    //label1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("baza.db");
    db.open();
    QSqlQuery query;
    
    query.exec("SELECT * FROM skladiste;");
  
    int index=0;
    int row=0;
    QTextStream out(stdout); 
    while(query.next()){
    QString id=query.value(0).toString();
    QString artikl=query.value(1).toString();
    QString pdv=query.value(2).toString();
    QString kolicina=query.value(3).toString();
    QString mjera=query.value(4).toString();
    QString cijena=query.value(5).toString();
    row=table->rowCount();
    table->insertRow(row);
    //QTableWidgetItem *number=new QTableWidgetItem(id);
    
    //form_widget->setItem(1,1,new QTableWidgetItem("5"));
    table->setItem(index,0,new QTableWidgetItem(id));
    table->setItem(index,1,new QTableWidgetItem(artikl));
    table->setItem(index,2,new QTableWidgetItem(pdv));
    table->setItem(index,3,new QTableWidgetItem(kolicina));
    table->setItem(index,4,new QTableWidgetItem(mjera));
    table->setItem(index,5,new QTableWidgetItem(cijena));
    
    index++;
    out<<id<<" "<<artikl<<" "<<pdv<<" "<<kolicina<<" "<<mjera<<" "<<cijena<<endl;
    }
  
  hbox->addWidget(table);
    centar po(this,900,600);
 //this->resize(350,150);
  this->setWindowTitle("Skladiste");
  this->show();
    
}
 
Skladiste::~Skladiste() {

QTextStream out(stdout);
out << "Zatvoreno skladiste" << endl;


 }



class Unos: public QWidget {
   
public:
    Unos(QWidget *parent = 0);
    ~Unos();

private slots:
    void onClick1();
    void onClick2();


private:
QLabel *label1,*label2,*label3,*label4,*label5,*label6;

QLineEdit *edit1,*edit2,*edit3,*edit4,*edit5,*edit6;

 QPushButton *b1; 
 QPushButton *b2;
 
 
  
};
 
Unos::Unos(QWidget *parent): 
    QWidget(parent) 
{
    // Dummy UI
    QVBoxLayout *vbox=new QVBoxLayout();
 
    QGridLayout *gridLayout = new QGridLayout;
    label1 = new QLabel("Id");
    label2 = new QLabel("Artikl");
    label3 = new QLabel("Pdv");
    label4 = new QLabel("Kolicina");
    label5 = new QLabel("Mjera");
    label6 = new QLabel("Cijena");
    label1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    label2->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    label3->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    label4->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    label5->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    label6->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    
    edit1=new QLineEdit();
    edit2=new QLineEdit();
    edit3=new QLineEdit();
    edit4=new QLineEdit();
    edit5=new QLineEdit();
    edit6=new QLineEdit();
    edit1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    edit2->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    edit3->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    edit4->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    edit5->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    edit6->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    
    b1= new QPushButton("Potvrdi");
    b1->setStyleSheet("font: bold;font-size: 15px;height: 20px;width: 120px;");
    b2= new QPushButton("Odustani");
    b2->setStyleSheet("font: bold;font-size: 15px;height: 20px;width: 120px;");
    
    
    gridLayout->addWidget(label1,1,0,1,1);
    gridLayout->addWidget(label2,2,0,1,1);
    gridLayout->addWidget(label3,3,0,1,1);

    // 1st row
    gridLayout->addWidget(label4,4,0,1,1);

    // 2nd row with 2-column span
    gridLayout->addWidget(label5,5,0,1,1);

    // 3rd row with 3-column span
    gridLayout->addWidget(label6,6,0,1,1);

 
    gridLayout->addWidget(edit1,1,1,1,1);
    gridLayout->addWidget(edit2,2,1,1,1);
    gridLayout->addWidget(edit3,3,1,1,1);
    gridLayout->addWidget(edit4,4,1,1,1);
    gridLayout->addWidget(edit5,5,1,1,1);
    gridLayout->addWidget(edit6,6,1,1,1);


   
    // Set the grid layout as a main layout
    vbox->addLayout(gridLayout);
    
    QHBoxLayout *hbox=new QHBoxLayout();
    
     hbox->addWidget(b1);
    hbox->addWidget(b2);
    
    vbox->addLayout(hbox);
   
    this->setLayout(vbox);

    centar po(this,300,300);
    
    connect(b1, &QPushButton::clicked, this, &Unos::onClick1);
    connect(b2, &QPushButton::clicked, this, &Unos::onClick2);
    
 //this->resize(350,150);
  this->setWindowTitle("Unos");
  this->show();
    
}
 
Unos::~Unos() {

QTextStream out(stdout);
out << "Zatvoreno unos" << endl;


 }

void Unos::onClick1() {
    
  QTextStream out(stdout);
  out << "Button clicked 1" << endl;
  QString id=edit1->text();
  QString artikl=edit2->text();
  QString pdv=edit3->text();
  QString kolicina=edit4->text();
  QString mjera=edit5->text();
  QString cijena=edit6->text();
  
  out<<edit1->text().toInt()<<endl;
  out<<edit2->text()<<endl;
  out<<edit3->text().toFloat()<<endl;
  out<<edit4->text().toFloat()<<endl;
  out<<edit5->text().toFloat()<<endl;
  out<<edit6->text().toFloat()<<endl;
  QSqlDatabase db;
  db = QSqlDatabase::addDatabase("QSQLITE");

 db.setDatabaseName("baza.db");
 db.open();
 QSqlQuery query;
  
 query.exec("INSERT INTO skladiste (id,artikl,pdv,kolicina,mjera,cijena) "
            "VALUES("+id+",'"+artikl+"',"+pdv+","+kolicina+","+mjera+","+cijena+")");
this->close();
}

void Unos::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked 2" << endl;
  this->close();
}

class Sifrarnik: public QWidget {
   
public:
    Sifrarnik(QWidget *parent = 0);
    ~Sifrarnik();
protected:

};
 
Sifrarnik::Sifrarnik(QWidget *parent): 
    QWidget(parent) 
{
  
  QVBoxLayout *vbox=new QVBoxLayout();
  
  QFrame *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  

  QFrame *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  

  QFrame *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  
  

  QGridLayout *grid = new QGridLayout();
  grid->addWidget(frame1, 0, 0,1,3);
  grid->addWidget(frame2, 0, 3,1,1);
  grid->addWidget(frame3, 0, 4,1,3);
  
  

  //grid->addWidget(hbox, 7, 0,1,7);



  vbox->addLayout(grid);
  
  QHBoxLayout *hbox=new QHBoxLayout();
  QPushButton *b1=new QPushButton("Potvrdi");
  QPushButton *b2=new QPushButton("Odustani");
  
  
  
  hbox->addWidget(b1,1,Qt::AlignRight);
  hbox->addWidget(b2,0,Qt::AlignLeft);
    
  vbox->addLayout(hbox);
   
  this->setLayout(vbox);
  
  
    
    centar po(this,900,600);
 
  this->setWindowTitle("Sifrarnik");
  this->show();
    
}
 
Sifrarnik::~Sifrarnik() {

QTextStream out(stdout);
out << "Zatvoreno sifrarnik" << endl;


 }






class Prozor : public QWidget{
  public:
    Prozor(QWidget *parent = 0);
    ~Prozor();
    
  private slots:
    void onClick1();
    void onClick2();
    void onClick3();
    void onClick4();
    void onClick6();

  private:
    QPushButton *tipka1;
    QPushButton *tipka2;
    QPushButton *tipka3;
    QPushButton *tipka4;
    QPushButton *tipka5;
    QPushButton *tipka6;
    QLabel *label;
    
  private:
    Blagajna *blagajna;
    Unos *unos;
    Skladiste *skladiste;
    Sifrarnik *sifrarnik;
};

Prozor::Prozor(QWidget *parent)
    : QWidget(parent) {        
        
        
  label=new QLabel("I have not be clicked");
  tipka1=new QPushButton("Blagajna");
  tipka2=new QPushButton("Unos");
  tipka3=new QPushButton("Skladiste");
  tipka4=new QPushButton("Sifrarnik");
  tipka5=new QPushButton("Push me5");
  tipka6=new QPushButton("Izlaz");
  
  //l->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 40px;width: 120px;");
  label->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;qproperty-alignment: AlignCenter;");
  //label->setAlignment(Qt::AlignCenter);
  tipka1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka2->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka3->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka4->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka5->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka6->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  
  
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(label);
  v_box->addWidget(tipka1);
  v_box->addWidget(tipka2);
  v_box->addWidget(tipka3);
  v_box->addWidget(tipka4);
  v_box->addWidget(tipka5);
  v_box->addWidget(tipka6);
  
  this->setLayout(v_box);



  connect(tipka1, &QPushButton::clicked, this, &Prozor::onClick1);
  connect(tipka2, &QPushButton::clicked, this, &Prozor::onClick2);
  connect(tipka3, &QPushButton::clicked, this, &Prozor::onClick3);
  connect(tipka4, &QPushButton::clicked, this, &Prozor::onClick4);
  connect(tipka6, &QPushButton::clicked, this, &Prozor::onClick6);
  
  
 centar po(this,350,300);
 //this->resize(350,150);
  this->setWindowTitle("Curicsoftdevelop");
  this->show();
 
}

Prozor::~Prozor(){
QTextStream out(stdout);
out << "Zatvorenox" << endl;


   // delete blagajna;
   // delete unos;
}


void Prozor::onClick1() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  blagajna=new Blagajna();
  blagajna->setAttribute(Qt::WA_DeleteOnClose);
  blagajna->show();
  blagajna->activateWindow();
  
  
}

void Prozor::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  unos = new Unos();
  unos->setAttribute(Qt::WA_DeleteOnClose);
  unos->show();
  unos->activateWindow();
  
  
}

void Prozor::onClick3() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  skladiste = new Skladiste();
  skladiste->setAttribute(Qt::WA_DeleteOnClose);
  skladiste->show();
  skladiste->activateWindow();
  
  
}

void Prozor::onClick4() {
    
  QTextStream out(stdout);
  out << "Button clicked sifrarnik" << endl;
  sifrarnik= new Sifrarnik();
  sifrarnik->setAttribute(Qt::WA_DeleteOnClose);
  sifrarnik->show();
  sifrarnik->activateWindow();
  
  
}

void Prozor::onClick6() {
    
  QTextStream out(stdout);
  out << "Button clicked 6" << endl;
  QApplication::quit();
  
  
}



int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Prozor window;
  
  return app.exec();
}

