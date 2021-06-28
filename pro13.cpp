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
#include <QRadioButton>
#include <QGroupBox>
#include <QList>
#include <QMessageBox>
#include <QTime>
#include <QDate>
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


class Blagajna : public QWidget {
    
  

  public:
    Blagajna(QPushButton *tipka,QWidget *parent = 0);
    ~Blagajna();

  private slots:
    void onClick1();
    void onClick2();
    void onClick3();

  private:
    QPushButton *b1,*b2,*b3,*b4;
    QLabel *l,*label1,*label2,*label3,*label1x,*label2x,*label3x,*label4x,*label1y,*label2y,*label3y,*label4y;
    QTableWidget *table;
    QPushButton *tipka;
    QDate cd;
    QTime ct;  
    int index;
    int row;
    QString str,stri;
    int s;
    int ss;
    int t;
    float suma;
    float sx;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  protected:
    void keyPressEvent(QKeyEvent * e);
};

Blagajna::~Blagajna()
{
QTextStream out(stdout);
  out << "Obrisao" << endl;
 this->tipka->setEnabled(true); 
}


Blagajna::Blagajna(QPushButton *tipka,QWidget *parent)
    : QWidget(parent) {        
     
  this->tipka=tipka;      
  table=new QTableWidget();
  
  table->setRowCount(0);
  table->setColumnCount(7);
  table->horizontalHeader()->setDefaultSectionSize(125);
  table->verticalHeader()->setDefaultSectionSize(16);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  
  //table->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 42pt; }");
  
  QStringList list;
    
    list<< "Id" << "Artikl"<<"Kolicina"<<"Mjera"<<"Cijena"<<"Pdv"<<"Iznos";
    
    table->setHorizontalHeaderLabels(list);
  
  index=0;
  row=0;
  s=0;
  ss=0;
  t=0;
  cd= QDate::currentDate();
  QString cdx=cd.toString("dd.MM.yyyy");
  ct = QTime::currentTime();
  QString ctx=ct.toString("hh:mm:ss");
  
  label1=new QLabel("Label 1");
  label2=new QLabel("");
  label3=new QLabel("0.00");
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
  
  label1y->setText(cdx);
  label2y->setText(ctx);

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
  b1=new QPushButton("Obrisi redak");
  b2=new QPushButton("Obrisi sve");
  b3=new QPushButton("Push me 3");
  b4=new QPushButton("Push me 4");
  h_box->addWidget(b1);
  h_box->addWidget(b2);
  h_box->addWidget(b3);
  h_box->addWidget(b4);
  v_box->addLayout(h_box);
  
  this->setLayout(v_box);

  connect(b1, &QPushButton::clicked, this, &Blagajna::onClick1);
  connect(b2, &QPushButton::clicked, this, &Blagajna::onClick2);
  connect(b3, &QPushButton::clicked, this, &Blagajna::onClick3);
 
 this->setFocusPolicy(Qt::StrongFocus);
 table->setFocusPolicy(Qt::NoFocus);
 b1->setFocusPolicy(Qt::NoFocus);
 b2->setFocusPolicy(Qt::NoFocus);
 b3->setFocusPolicy(Qt::NoFocus);
 b4->setFocusPolicy(Qt::NoFocus);
 
 centar po(this,920,600);
 
  this->setWindowTitle("Blagajna");
  this->show();
 
}

void Blagajna::onClick1() {
    
  QTextStream out(stdout);
  out << "Button clicked" << row<<endl;
  row=table->rowCount();
  index=row-1;
  
  if(index!=-1){
  float plabel=label3->text().toFloat();
  float p=table->item(index,6)->text().toFloat();
  out<<plabel<<" "<<p<<endl;
  plabel=plabel-p;
  label3->setText(QString().sprintf("%0.2f",plabel));
  }
  table->removeRow(index);
  out << "Button clicked " <<index<<endl;
  suma=0.0;
  
}

void Blagajna::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  while(index!=-1)
  {
  row=table->rowCount();
  index=row-1;
  table->removeRow(index);
  label3->setText(QString().sprintf("%0.2f",0.0));
  }  
  suma=0.0;
}

void Blagajna::onClick3() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  row=table->rowCount();
    table->insertRow(row);
    index=row;
    table->setItem(index,0,new QTableWidgetItem("igor"));
    table->setItem(index,1,new QTableWidgetItem("igor"));
    table->setItem(index,2,new QTableWidgetItem("igor"));
out << "Button clicked" << row<<endl;
    //index++;
}

void Blagajna::keyPressEvent(QKeyEvent *event) {
QTextStream out(stdout);
  
   if (event->key() == Qt::Key_Return  && s==0 ) {
     row=table->rowCount();
     out<<"prije "<<row<<endl;
    table->insertRow(row);  
    out<<"poslije "<<row<<endl;
    index=row;
    

    db.setDatabaseName("baza.db");
    db.open();
  
    QSqlQuery query;
    
    stri="select * from sifrarnik where id="+str;
    
    query.exec(stri);
    query.next();
    QString Id=query.value(0).toString();
    QString Artikl=query.value(1).toString();
    QString Kolicina=query.value(2).toString();
    QString Mjera=query.value(3).toString();
    QString Cijena=query.value(4).toString();
    QString Pdv=query.value(5).toString();
    QString Iznos=query.value(4).toString();
    
    
    table->setItem(index,0,new QTableWidgetItem(Id));
    table->setItem(index,1,new QTableWidgetItem(Artikl));
    table->setItem(index,2,new QTableWidgetItem("1"));
    table->setItem(index,3,new QTableWidgetItem("1"));
    table->setItem(index,4,new QTableWidgetItem(Cijena));
    table->setItem(index,5,new QTableWidgetItem(Pdv));
    table->setItem(index,6,new QTableWidgetItem(Iznos));
    
    db.close();
    //index++;
    
    out<<str<<endl;
   s=1;
   }
   
   if (event->key() != Qt::Key_Return) {
   
   s=0;ss=0;
   }
   
    if (event->key() == Qt::Key_Return  && s==1 ) {
    ss++;
    str="";
    row=table->rowCount();
    index=row-1;
    QString numberx= QString::number(ss);
    table->setItem(index,2,new QTableWidgetItem(numberx));
    QString Cijena1=QString().sprintf("%0.2f",table->item(index,4)->text().toFloat());
    table->setItem(index,4,new QTableWidgetItem(Cijena1));
    sx=table->item(index,4)->text().toFloat();
    
    QString Iznos=QString().sprintf("%0.2f",sx*ss);
    table->setItem(index,6,new QTableWidgetItem(Iznos));
    suma+=sx;
    label3->setText(QString().sprintf("%0.2f",suma));
    out<<row<<endl;
    }
   
   if (event->key()==Qt::Key_Space) {
   
   out<<"space"<<endl;
   db.setDatabaseName("baza.db");
   db.open();
  
   QSqlQuery query;
   //list<< "Id" << "Artikl"<<"Kolicina"<<"Mjera"<<"Cijena"<<"Pdv"<<"Iznos";
   for(int i=0;i<table->rowCount();i++)
  {
  QString Id=table->item(i,0)->text();
  QString Artikl=table->item(i,1)->text();
  QString Kolicina=table->item(i,2)->text();
  QString Mjera=table->item(i,3)->text();
  QString Cijena=table->item(i,4)->text();
  QString Pdv=table->item(i,5)->text();
  QString Iznos=table->item(i,6)->text();
  
  
   out<<Id<<" "<<Artikl<<" "<<Kolicina<<" "<<Mjera<<" "<<Cijena<<" "<<Pdv<<" "<<Iznos<<endl;
   
   
   
   QString strx="SELECT id1,id2,mjera1,mjera2 FROM sifrarnik where id="+Id;
   
   query.exec(strx);
   query.next();
   int Id1=query.value(0).toInt();
   int Id2=query.value(1).toInt();
   
   float Mjera1=query.value(2).toFloat();
   float Mjera2=query.value(3).toFloat();
   
   out<<Id1<<" "<<Id2<<" "<<Mjera1<<" "<<Mjera2<<endl;
   
   if(Id1!=0){
   QString strx1="select kolicina from skladiste where id="+QString::number(Id1);
   query.exec(strx1);
   query.next();
   
   float kol= Kolicina.toFloat();
   float kolicina=query.value(0).toFloat();
   float kolicinax=0.0f;
   
   kolicinax=kolicina-Mjera1*kol;
   
   QString strxy1="update skladiste set kolicina="+QString::number(kolicinax)+" where id="+QString::number(Id1);
   query.exec(strxy1);
   
   }
   
   if(Id2!=0){
   QString strx1="select kolicina from skladiste where id="+QString::number(Id2);
   query.exec(strx1);
   query.next();
   
   float kol= Kolicina.toFloat();
   float kolicina=query.value(0).toFloat();
   float kolicinax=0.0f;
   
   kolicinax=kolicina-Mjera2*kol;
   
   QString strxy1="update skladiste set kolicina="+QString::number(kolicinax)+" where id="+QString::number(Id2);
   query.exec(strxy1);
   
   }
   
   
   
   }
   
   QString strxz1="select count(*) from racun;";
   query.exec(strxz1);
   query.next();
   
   int raci=query.value(0).toInt();
   out<<raci<<endl;
   
   raci++;
   
  
  QString cdx=QDate::currentDate().toString("dd.MM.yyyy");
  QString ctx=QTime::currentTime().toString("hh:mm:ss");
   
   QString strxx="insert into racun values ("+QString::number(raci)+",'"+ctx+"','"+cdx+"',"+QString::number(suma)+");";
   query.exec(strxx);
   
   db.close();
   
  QString cdxx=QDate::currentDate().toString("yy");
  QString racun=QString().sprintf("%04d/",raci);
  QString racunx=racun+""+cdxx;
  
  label1y->setText(cdx);
  label2y->setText(ctx);
  label3y->setText(racunx); 
   
   while(index!=-1)
  {
  row=table->rowCount();
  index=row-1;
  table->removeRow(index);
  }
  label3->setText(QString().sprintf("%0.2f",0.0));  
  suma=0.0;
   
   }
   
   if(event->key()==Qt::Key_1)
    {
    
        out << "You Released Key 1" << endl;
       str+="1";
       out<<str<<endl;
       
    }
    else if(event->key()==Qt::Key_2)
    {
    
        out << "You Released Key 2" << endl;
        str+="2";
        out<<str<<endl;
    }
    else if(event->key()==Qt::Key_3)
    {
    
        out << "You Released Key 3" << endl;
        str+="3";
        out<<str<<endl;
    }
   else if(event->key()==Qt::Key_4)
    {
    
        out << "You Released Key 4" << endl;
        str+="4";
        out<<str<<endl;
    }
   else if(event->key()==Qt::Key_5)
    {
    
        out << "You Released Key 5" << endl;
        str+="5";
        out<<str<<endl;
    }
   else if(event->key()==Qt::Key_6)
    {
    
        out << "You Released Key 6" << endl;
        str+="6";
        out<<str<<endl;
    } 
    else if(event->key()==Qt::Key_7)
    {
    
        out << "You Released Key 2" << endl;
        str+="7";
        out<<str<<endl;
    }
    else if(event->key()==Qt::Key_8)
    {
    
        out << "You Released Key 8" << endl;
        str+="8";
        out<<str<<endl;
    }
    else if(event->key()==Qt::Key_9)
    {
    
        out << "You Released Key 9" << endl;
        str+="9";
        out<<str<<endl;
    }
   else if(event->key()==Qt::Key_0)
    {
    
        out << "You Released Key 0" << endl;
        str+="0";
        out<<str<<endl;
    } 
}

 
class Skladiste: public QWidget {
   
public:
    Skladiste(QPushButton *tipka,QWidget *parent = 0);
    ~Skladiste();
private:
QSqlDatabase db;
QPushButton *tipka;
QPushButton *b;
void closeDb();
private slots:
    void Odustani();
};
 
Skladiste::Skladiste(QPushButton *tipka,QWidget *parent): 
    QWidget(parent) 
{
	this->tipka=tipka;
    

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
  
  QVBoxLayout *vbox=new QVBoxLayout();
  QHBoxLayout *hbox = new QHBoxLayout();
  vbox->addWidget(table);
  
  
  b=new QPushButton("Izlaz");
  hbox->addStretch();
  hbox->addWidget(b);
  hbox->addStretch();
  
  vbox->addLayout(hbox);
  connect(b, &QPushButton::clicked, this, &Skladiste::Odustani);
  vbox->addLayout(hbox);
  
  
  this->setLayout(vbox);
    centar po(this,900,600);
 //this->resize(350,150);
  this->setWindowTitle("Skladiste");
  this->show();
    
}
 
Skladiste::~Skladiste() {

QTextStream out(stdout);
out << "Zatvoreno skladiste" << endl;
this->tipka->setEnabled(true);
closeDb();
 }
 
 void Skladiste::Odustani(){
QTextStream out(stdout);
out << "Zatvoreno skladiste izlaz" << endl;
this->close();
 
 }
 
 void Skladiste::closeDb()
{
    {
        db = QSqlDatabase::database();
        db.close();
    }
    QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );
    return;
}



class Unos: public QWidget {
   
public:
    Unos(QPushButton *tipka,QWidget *parent = 0);
    ~Unos();

private slots:
    void onClick1();
    void onClick2();


private:
QLabel *label1,*label2,*label3,*label4,*label5,*label6;

QLineEdit *edit1,*edit2,*edit3,*edit4,*edit5,*edit6;

 QPushButton *b1; 
 QPushButton *b2;
 QPushButton *tipka;
 
  
};
 
Unos::Unos(QPushButton *tipka,QWidget *parent): 
    QWidget(parent) 
{
    // Dummy UI
    this->tipka=tipka;
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
    
    b1= new QPushButton("Potvrdi");
    b1->setStyleSheet("font: bold;font-size: 12px;height: 20px;width: 80px;");
    b2= new QPushButton("Odustani");
    b2->setStyleSheet("font: bold;font-size: 12px;height: 20px;width: 80px;");
    hbox->addWidget(b1,1,Qt::AlignRight);
  hbox->addWidget(b2,0,Qt::AlignLeft);
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
this->tipka->setEnabled(true);

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
 db.close();
this->close();
}

void Unos::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked 2" << endl;
  this->close();
}

class Unossifara: public QWidget {
   
public:
    Unossifara(QPushButton *tipka,QWidget *parent = 0);
    ~Unossifara();
private:
QLineEdit *IdEdit,*ArtiklEdit,*Id1Edit,*Mjera1Edit,*Cijena1Edit,*Pdv1Edit,
*Id2Edit,*Mjera2Edit,*Cijena2Edit,*Pdv2Edit;
QRadioButton *rbutton1,*rbutton2;
QSqlDatabase db; 
QTableWidget *table;
QPushButton *tipka;
private slots:
    void row();
    void Odustani();
    void Potvrdi();
public:
void closeDb();
};
 
Unossifara::Unossifara(QPushButton *tipka,QWidget *parent): 
    QWidget(parent) 
{
  this->tipka=tipka;
  QVBoxLayout *vbox=new QVBoxLayout();
  
  IdEdit = new QLineEdit();
  ArtiklEdit = new QLineEdit();
  Id1Edit = new QLineEdit();
  Mjera1Edit = new QLineEdit();
  Cijena1Edit = new QLineEdit();
  Pdv1Edit = new QLineEdit();
  Id2Edit = new QLineEdit();
  Mjera2Edit = new QLineEdit();
  Cijena2Edit = new QLineEdit();
  Pdv2Edit = new QLineEdit();
  IdEdit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  ArtiklEdit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Id1Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Mjera1Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Cijena1Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Pdv1Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Id2Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Mjera2Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Cijena2Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  Pdv2Edit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  
  QFormLayout *framex1 =new QFormLayout();
  
  
  //framex1->setLabelAlignment(Qt::AlignRight | Qt::AlignCenter);
  
  framex1->addRow("Id:", IdEdit);
  framex1->addRow("Artikl:", ArtiklEdit);
  framex1->addRow("Id1:", Id1Edit);
  framex1->addRow("Mjera1:", Mjera1Edit);
  framex1->addRow("Cijena1:", Cijena1Edit);
  framex1->addRow("Pdv1:", Pdv1Edit);
  framex1->addRow("Id2:", Id2Edit);
  framex1->addRow("Mjera2:", Mjera2Edit);
  framex1->addRow("Cijena2:", Cijena2Edit);
  framex1->addRow("Pdv2:", Pdv2Edit);
  
  
  framex1->labelForField(IdEdit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(ArtiklEdit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Id1Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Mjera1Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Cijena1Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Pdv1Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Id2Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Mjera2Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Cijena2Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(Pdv2Edit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  
  
  QGroupBox *groupBox= new QGroupBox(tr("Id radio"));
  rbutton1= new QRadioButton("Id1");
  rbutton2= new QRadioButton("Id2");
  QVBoxLayout *framex2=new QVBoxLayout();
  framex2->addWidget(rbutton1);
  framex2->addWidget(rbutton2);
  rbutton1->setStyleSheet("font: bold;font-size: 15px;height: 30px;width: 120px;");
  rbutton2->setStyleSheet("font: bold;font-size: 15px;height: 30px;width: 120px;");
  rbutton1->setChecked(true);
  groupBox->setLayout(framex2);
  groupBox->setStyleSheet("font: bold;font-size: 15px;");
  
  QVBoxLayout *framex3=new QVBoxLayout();
  table = new QTableWidget();
  table->setRowCount(0);
  table->setColumnCount(3);
  table->horizontalHeader()->setDefaultSectionSize(140);
  table->verticalHeader()->setDefaultSectionSize(16);
  table->setStyleSheet("font: bold;font-size: 12px;");
   table->setEditTriggers(QAbstractItemView::NoEditTriggers);
   table->setSelectionBehavior(QAbstractItemView::SelectRows);
  //table->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 42pt; }");
  
  QStringList list;
    
    list<< "Id" << "Artikl"<<"Pdv";
  table->setHorizontalHeaderLabels(list);
  framex3->addWidget(table);
  
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("baza.db");
    db.open();
    QSqlQuery query;
    
    query.exec("SELECT * FROM skladiste;");
  
    int index=0;
    int row=0;
  while(query.next()){
    QString id=query.value(0).toString();
    QString artikl=query.value(1).toString();
    QString pdv=query.value(2).toString();
    row=table->rowCount();
    table->insertRow(row);
    
    table->setItem(index,0,new QTableWidgetItem(id));
    table->setItem(index,1,new QTableWidgetItem(artikl));
    table->setItem(index,2,new QTableWidgetItem(pdv));

    index++;
    }
    
  

  QGridLayout *grid = new QGridLayout();
  grid->addLayout(framex1, 0, 0,1,3);
  grid->addWidget(groupBox, 0, 3,1,1);
  grid->addLayout(framex2, 0, 3,1,1);
 
  grid->addLayout(framex3, 0, 4,1,5);
  



  vbox->addLayout(grid);
  
  QHBoxLayout *hbox=new QHBoxLayout();
  QPushButton *b1=new QPushButton("Potvrdi");
  b1->setStyleSheet("font: bold;font-size: 15px;height: 20px;width: 120px;");
  QPushButton *b2=new QPushButton("Odustani");
  b2->setStyleSheet("font: bold;font-size: 15px;height: 20px;width: 120px;");
  
  
  hbox->addWidget(b1,1,Qt::AlignRight);
  hbox->addWidget(b2,0,Qt::AlignLeft);
    
  vbox->addLayout(hbox);
   
  this->setLayout(vbox);
  
  
  connect(table,&QTableWidget::clicked, this,&Unossifara::row);
  connect(b2,&QPushButton::clicked, this,&Unossifara::Odustani);
  connect(b1,&QPushButton::clicked, this,&Unossifara::Potvrdi);
    
    centar po(this,900,500);
 
  this->setWindowTitle("Unos sifara");
  this->show();
    
}
 
Unossifara::~Unossifara() {

QTextStream out(stdout);
out << "Zatvoreno unossifara" << endl;
this->tipka->setEnabled(true);
closeDb();

 }

void Unossifara::row()
{
QTextStream out(stdout);
out << "Redak" << endl;

QModelIndex curentIndex = table->currentIndex();

out <<table->item(curentIndex.row(), 0)->text()<<endl;
out <<table->item(curentIndex.row(), 1)->text()<<endl;
out <<table->item(curentIndex.row(), 2)->text()<<endl;
QString str1=table->item(curentIndex.row(), 0)->text()+" "+table->item(curentIndex.row(), 1)->text()+" "+
table->item(curentIndex.row(), 2)->text();

QMessageBox(QMessageBox::Information, "title", str1, QMessageBox::Yes).exec(); 

if(rbutton1->isChecked()){
out<<"rbutton1"<<endl;
Id1Edit->setText(table->item(curentIndex.row(), 0)->text());
Pdv1Edit->setText(table->item(curentIndex.row(), 2)->text());
}else if(rbutton2->isChecked())
{
out<<"rbutton2"<<endl;
Id2Edit->setText(table->item(curentIndex.row(), 0)->text());
Pdv2Edit->setText(table->item(curentIndex.row(), 2)->text());
}

}

void Unossifara::Odustani()
{
QTextStream out(stdout);
out << "Odustani" << endl;
closeDb();
this->close();

}

void Unossifara::Potvrdi()
{
QTextStream out(stdout);
out << "Potvrdi" << endl;



QString Id=IdEdit->text();
QString Artikl=ArtiklEdit->text();
QString Id1=Id1Edit->text();
QString Mjera1=Mjera1Edit->text();
QString Cijena1=Cijena1Edit->text();
QString Pdv1=Pdv1Edit->text();
QString Id2=Id2Edit->text();
QString Mjera2=Mjera2Edit->text();
QString Cijena2=Cijena2Edit->text();
QString Pdv2=Pdv2Edit->text();


  
out<<IdEdit->text().toInt()<<endl;
out<<ArtiklEdit->text()<<endl;
out<<Id1Edit->text().toInt()<<endl;
out<<Mjera1Edit->text().toFloat()<<endl;
out<<Cijena1Edit->text().toFloat()<<endl;
out<<Pdv1Edit->text().toFloat()<<endl;
out<<Id2Edit->text().toInt()<<endl;
out<<Mjera2Edit->text().toFloat()<<endl;
out<<Cijena2Edit->text().toFloat()<<endl;
out<<Pdv2Edit->text().toFloat()<<endl;

 
QSqlDatabase db1;
db1 = QSqlDatabase::addDatabase("QSQLITE");

db1.setDatabaseName("baza.db");
db1.open();
QSqlQuery query;


if(Id2.toInt()!=0){  
query.exec("INSERT INTO sifrarnik (id,artikl,id1,mjera1,cijena1,pdv1,id2,mjera2,cijena2,pdv2) "
   "VALUES("+Id+",'"+Artikl+"',"+Id1+","+Mjera1+","+Cijena1+","+Pdv1+","+Id2+","+Mjera2+","+Cijena2+","+Pdv2+");");
}else
{
query.exec("INSERT INTO sifrarnik (id,artikl,id1,mjera1,cijena1,pdv1,id2,mjera2,cijena2,pdv2) "
   "VALUES("+Id+",'"+Artikl+"',"+Id1+","+Mjera1+","+Cijena1+","+Pdv1+",0,0,0,0);");

}



db1.close();
this->close();


}


void Unossifara::closeDb()
{
    {
        db = QSqlDatabase::database();
        db.close();
    }
    QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );
    return;
}

class Sifrarnik: public QWidget {
   
public:
    Sifrarnik(QPushButton *tipka,QWidget *parent = 0);
    ~Sifrarnik();
private slots:
    void Odustani();

private:
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
QPushButton *tipka;
};
 
Sifrarnik::Sifrarnik(QPushButton *tipka,QWidget *parent): 
    QWidget(parent) 
{
  this->tipka=tipka;
  QVBoxLayout *vbox = new QVBoxLayout();
  
  QTableWidget *table = new QTableWidget();
  table->setRowCount(0);
  table->setColumnCount(10);
  table->horizontalHeader()->setDefaultSectionSize(100);
  //table->horizontalHeader()->setDefaultSectionSize(50);
  table->setColumnWidth(0, 50);
  table->setColumnWidth(1, 150);
  table->verticalHeader()->setDefaultSectionSize(16);
   //    QTableWidgetItem * pItem = table->horizontalHeaderItem( 0 );
   // pItem->setTextAlignment( Qt::AlignLeft | Qt::AlignVCenter );
     
  //  pItem = table->horizontalHeaderItem( 1 );
  //  pItem->setTextAlignment( Qt::AlignHCenter | Qt::AlignVCenter );
   vbox->addWidget(table);
   
   QStringList list;
    
   list<< "Id" << "Artikl"<<"Id1"<<"Mjera1"<<"Cijena1"<<"Pdv1"<<"Id2"<<"Mjera2"<<"Cijena2"<<"Pdv2";
    
   table->setHorizontalHeaderLabels(list);
   

   db.setDatabaseName("baza.db");
   db.open();
   QSqlQuery query;
    
   query.exec("SELECT * FROM sifrarnik;");
   
   int index=0;
    int row=0;
    QTextStream out(stdout); 
    while(query.next()){
    QString Id=QString().sprintf("%03d",query.value(0).toInt());;
    QString Artikl=query.value(1).toString();
    QString Id1=query.value(2).toString();
    QString Mjera1=query.value(3).toString();
    QString Cijena1=QString().sprintf("%0.2f",query.value(4).toFloat());
    QString Pdv1=query.value(5).toString();
    QString Id2=query.value(6).toString();
    QString Mjera2=query.value(7).toString();
    QString Cijena2=query.value(8).toString();
    QString Pdv2=query.value(9).toString();
    
    QTableWidgetItem *Cijena1x=new QTableWidgetItem(Cijena1);
    Cijena1x->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    row=table->rowCount();
    table->insertRow(row);
    //QTableWidgetItem *number=new QTableWidgetItem(id);
    
    //form_widget->setItem(1,1,new QTableWidgetItem("5"));
    table->setItem(index,0,new QTableWidgetItem(Id));
    table->setItem(index,1,new QTableWidgetItem(Artikl));
    table->setItem(index,2,new QTableWidgetItem(Id1));
    table->setItem(index,3,new QTableWidgetItem(Mjera1));
    table->setItem(index,4,Cijena1x);
    table->setItem(index,5,new QTableWidgetItem(Pdv1));
    table->setItem(index,6,new QTableWidgetItem(Id2));
    table->setItem(index,7,new QTableWidgetItem(Mjera2));
    table->setItem(index,8,new QTableWidgetItem(Cijena2));
    table->setItem(index,9,new QTableWidgetItem(Pdv2));
    
    index++;
    //out<<id<<" "<<artikl<<" "<<pdv<<" "<<kolicina<<" "<<mjera<<" "<<cijena<<endl;
    }
   
   db.close();
   
   QHBoxLayout *hbox = new QHBoxLayout();
   
   QPushButton *b=new QPushButton("Izlaz");

   hbox->addStretch();
   hbox->addWidget(b);
   hbox->addStretch();
  
  vbox->addLayout(hbox);
  connect(b, &QPushButton::clicked, this, &Sifrarnik::Odustani);
   this->setLayout(vbox); 
   centar po(this,1000,500);
 
  this->setWindowTitle("Sifrarnik");
  this->show();
    
}
 
Sifrarnik::~Sifrarnik() {

QTextStream out(stdout);
out << "Zatvoreno sifarnik" << endl;
this->tipka->setEnabled(true);

 }
 
 
void Sifrarnik::Odustani() {

QTextStream out(stdout);
out << "Zatvoreno sifarnik odustani" << endl;
this->tipka->setEnabled(true);
this->close();

 }

class Unoskolicina: public QWidget {
   
public:
    Unoskolicina(QPushButton *tipka,QWidget *parent = 0);
    ~Unoskolicina();
private slots:
    void Potvrdi();
    void Odustani();    

private:
QPushButton *tipka;
QLineEdit *IdEdit,*KolicinaEdit;
QPushButton *b1,*b2;
};
 
Unoskolicina::Unoskolicina(QPushButton *tipka,QWidget *parent): 
    QWidget(parent) 
{
    // Dummy UI
    //this->tipka=new QPushButton();
    this->tipka=tipka;
    QVBoxLayout *vbox = new QVBoxLayout();
    IdEdit = new QLineEdit();
  	KolicinaEdit = new QLineEdit();
  	IdEdit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
 	KolicinaEdit->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  	
  	QFormLayout *framex1 =new QFormLayout();
  
  
  //framex1->setLabelAlignment(Qt::AlignRight | Qt::AlignCenter);
  
  framex1->addRow("Id:", IdEdit);
  framex1->addRow("Kolicina:", KolicinaEdit);
    
    framex1->labelForField(IdEdit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  framex1->labelForField(KolicinaEdit)->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
    
    QHBoxLayout *hbox = new QHBoxLayout();
    b1=new QPushButton("Potvrdi");
    b2=new QPushButton("Odustani");
   hbox->addWidget(b1,1,Qt::AlignRight);
  hbox->addWidget(b2,0,Qt::AlignLeft);
    
  vbox->addLayout(framex1);
  vbox->addLayout(hbox);
  this->setLayout(vbox);
    
    connect(b2,&QPushButton::clicked, this,&Unoskolicina::Odustani);
  connect(b1,&QPushButton::clicked, this,&Unoskolicina::Potvrdi);
    centar po(this,350,300);
 //this->resize(350,150);
  this->setWindowTitle("Unos kolicine");
  this->show();
    
}
 
Unoskolicina::~Unoskolicina() {

QTextStream out(stdout);
out << "Zatvoreno unoskolicina" << endl;
this->tipka->setEnabled(true);



 }

void Unoskolicina::Potvrdi()
{
QTextStream out(stdout);
out << "potvrdi" << endl;

}

void Unoskolicina::Odustani()
{
QTextStream out(stdout);
out << "odustani" << endl;
this->close();

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
    void onClick5();
    void onClick6();
    void onClick7();

  private:
    QPushButton *tipka1;
    QPushButton *tipka2;
    QPushButton *tipka3;
    QPushButton *tipka4;
    QPushButton *tipka5;
    QPushButton *tipka6;
    QPushButton *tipka7;
    QLabel *label;
    
  private:
    Blagajna *blagajna;
    Unos *unos;
    Skladiste *skladiste;
    Unossifara *unossifara;
    Sifrarnik *sifrarnik;
    Unoskolicina *unoskolicina;
};

Prozor::Prozor(QWidget *parent)
    : QWidget(parent) {        
        
        
  label=new QLabel("I have not be clicked");
  tipka1=new QPushButton("Blagajna");
  tipka2=new QPushButton("Unos");
  tipka3=new QPushButton("Skladiste");
  tipka4=new QPushButton("Unos sifara");
  tipka5=new QPushButton("Sifrarnik");
  tipka6=new QPushButton("Unos kolicina");
  tipka7=new QPushButton("Izlaz");
  
  //l->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 40px;width: 120px;");
  label->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;qproperty-alignment: AlignCenter;");
  //label->setAlignment(Qt::AlignCenter);
  tipka1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka2->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka3->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka4->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka5->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka6->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka7->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(label);
  v_box->addWidget(tipka1);
  v_box->addWidget(tipka2);
  v_box->addWidget(tipka3);
  v_box->addWidget(tipka4);
  v_box->addWidget(tipka5);
  v_box->addWidget(tipka6);
  v_box->addWidget(tipka7);
  
  this->setLayout(v_box);



  connect(tipka1, &QPushButton::clicked, this, &Prozor::onClick1);
  connect(tipka2, &QPushButton::clicked, this, &Prozor::onClick2);
  connect(tipka3, &QPushButton::clicked, this, &Prozor::onClick3);
  connect(tipka4, &QPushButton::clicked, this, &Prozor::onClick4);
  connect(tipka5, &QPushButton::clicked, this, &Prozor::onClick5);
  connect(tipka6, &QPushButton::clicked, this, &Prozor::onClick6);
  connect(tipka7, &QPushButton::clicked, this, &Prozor::onClick7);
  
  
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
  blagajna=new Blagajna(tipka1);
  blagajna->setAttribute(Qt::WA_DeleteOnClose);
  blagajna->show();
  blagajna->activateWindow();
  tipka1->setEnabled(false);
  
}

void Prozor::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  unos = new Unos(tipka2);
  unos->setAttribute(Qt::WA_DeleteOnClose);
  unos->show();
  unos->activateWindow();
  tipka2->setEnabled(false);
  
}

void Prozor::onClick3() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  skladiste = new Skladiste(tipka3);
  skladiste->setAttribute(Qt::WA_DeleteOnClose);
  skladiste->show();
  skladiste->activateWindow();
  tipka3->setEnabled(false);
  
}

void Prozor::onClick4() {
    
  QTextStream out(stdout);
  out << "Button clicked sifrarnik" << endl;
  unossifara= new Unossifara(tipka4);
  unossifara->setAttribute(Qt::WA_DeleteOnClose);
  unossifara->show();
  unossifara->activateWindow();
  tipka4->setEnabled(false);
  
}

void Prozor::onClick5() {
    
  QTextStream out(stdout);
  out << "Button clicked sifrarnik" << endl;
  sifrarnik= new Sifrarnik(tipka5);
  sifrarnik->setAttribute(Qt::WA_DeleteOnClose);
  sifrarnik->show();
  sifrarnik->activateWindow();
  tipka5->setEnabled(false);
  
}

void Prozor::onClick6() {
    
  QTextStream out(stdout);
  out << "Button clicked sifrarnik" << endl;
  unoskolicina= new Unoskolicina(tipka6);
  unoskolicina->setAttribute(Qt::WA_DeleteOnClose);
  unoskolicina->show();
  unoskolicina->activateWindow();
  tipka6->setEnabled(false);
  
}

void Prozor::onClick7() {
    
  QTextStream out(stdout);
  out << "Button clicked 6" << endl;
  QApplication::quit();
  
  
}




int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Prozor window;
  
  return app.exec();
}

