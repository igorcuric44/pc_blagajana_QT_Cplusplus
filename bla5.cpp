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




using namespace std;

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);
    ~Click();

  private slots:
    void onClick1();
    void onClick2();
    void onClick3();

  private:
    QPushButton *b1,*b2,*b3,*b4;
    QLabel *l,*label1,*label2,*label3,*label1x,*label2x,*label3x,*label4x,*label1y,*label2y,*label3y,*label4y;
    QTableWidget *table;
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

Click::~Click()
{
QTextStream out(stdout);
  out << "Obrisao" << endl;
  
}


Click::Click(QWidget *parent)
    : QWidget(parent) {        
        
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

  connect(b1, &QPushButton::clicked, this, &Click::onClick1);
  connect(b2, &QPushButton::clicked, this, &Click::onClick2);
  connect(b3, &QPushButton::clicked, this, &Click::onClick3);
 
 this->setFocusPolicy(Qt::StrongFocus);
 table->setFocusPolicy(Qt::NoFocus);
 b1->setFocusPolicy(Qt::NoFocus);
 b2->setFocusPolicy(Qt::NoFocus);
 b3->setFocusPolicy(Qt::NoFocus);
 b4->setFocusPolicy(Qt::NoFocus);
 
 this->resize(920,600);
  this->setWindowTitle("Blagajna");
  this->show();
 
}

void Click::onClick1() {
    
  QTextStream out(stdout);
  out << "Button clicked" << row<<endl;
  row=table->rowCount();
  index=row-1;
  table->removeRow(index);
  out << "Button clicked " <<index<<endl;
  if(index>=0){
  index--;
  }else
  {
  index=0;
  }
  
  
}

void Click::onClick2() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  

}

void Click::onClick3() {
    
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

void Click::keyPressEvent(QKeyEvent *event) {
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
    table->setItem(index,3,new QTableWidgetItem(Mjera));
    table->setItem(index,4,new QTableWidgetItem(Cijena));
    table->setItem(index,5,new QTableWidgetItem(Pdv));
    table->setItem(index,6,new QTableWidgetItem(Iznos));
    
    //db.close();
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

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  //window.setFocus();

  
  return app.exec();
}
