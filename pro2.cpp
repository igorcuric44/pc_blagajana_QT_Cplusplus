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
#include<QMainWindow>
#include <QDesktopWidget>

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


class SecondWindow: public QWidget {
   
public:
    SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
protected:

};
 
SecondWindow::SecondWindow(QWidget *parent): 
    QWidget(parent) 
{
    // Dummy UI
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("The Second Widget", this);
    layout->addWidget(l);
    centar po(this,350,300);
 //this->resize(350,150);
  this->setWindowTitle("Curicsoftdevelop");
  this->show();
    
}
 
SecondWindow::~SecondWindow() {
this->setAttribute(Qt::WA_DeleteOnClose);
QTextStream out(stdout);
out << "Zatvoreno" << endl;


 }





class Prozor : public QWidget{
    
  

  public:
    Prozor(QWidget *parent = 0);
    ~Prozor();
    
  private slots:
    void onClick();
    

  private:
    QPushButton *tipka1;
    QPushButton *tipka2;
    QPushButton *tipka3;
    QPushButton *tipka4;
    QPushButton *tipka5;
    QLabel *label;
    
  private:
    SecondWindow *m_secondWindow;
};

Prozor::Prozor(QWidget *parent)
    : QWidget(parent) {        
        
        
  label=new QLabel("I have not be clicked");
  tipka1=new QPushButton("Push me1");
  tipka2=new QPushButton("Push me2");
  tipka3=new QPushButton("Push me3");
  tipka4=new QPushButton("Push me4");
  tipka5=new QPushButton("Push me5");
  //l->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 40px;width: 120px;");
  label->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;qproperty-alignment: AlignCenter;");
  //label->setAlignment(Qt::AlignCenter);
  tipka1->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka2->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka3->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka4->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  tipka5->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(label,Qt::AlignCenter);
  v_box->addWidget(tipka1);
  v_box->addWidget(tipka2);
  v_box->addWidget(tipka3);
  v_box->addWidget(tipka4);
  v_box->addWidget(tipka5);
  
  this->setLayout(v_box);



  connect(tipka1, &QPushButton::clicked, this, &Prozor::onClick);
 centar po(this,350,300);
 //this->resize(350,150);
  this->setWindowTitle("Curicsoftdevelop");
  this->show();
 
}

Prozor::~Prozor(){
QTextStream out(stdout);
out << "Zatvorenox" << endl;


    delete m_secondWindow;
}


void Prozor::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  m_secondWindow = new SecondWindow();
  m_secondWindow->show();
  m_secondWindow->activateWindow();
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Prozor window;
  
  return app.exec();
}
