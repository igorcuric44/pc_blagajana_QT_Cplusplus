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


class Prozor : public QWidget{
    
  

  public:
    Prozor(QWidget *parent = 0);

  private slots:
    void onClick();
    

  private:
    QPushButton *b;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    QLabel *l;
};

Prozor::Prozor(QWidget *parent)
    : QWidget(parent) {        
        
        
  l=new QLabel("I have not be clicked");
  b = new QPushButton("Push me");
  b1 = new QPushButton("Push me");
  b2 = new QPushButton("Push me");
  b3 = new QPushButton("Push me");
  b4 = new QPushButton("Push me");
  //l->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 40px;width: 120px;");
  l->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  b->setStyleSheet("font: bold;font-size: 20px;height: 30px;width: 120px;");
  QFont f("Monospace");
        f.setPointSize(12);
      f.setBold(true);
      f.setWeight(5);
      b1->setFont(f);
      b1->setText("Changed Property");
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(l);
  v_box->addWidget(b);
  v_box->addWidget(b1);
  v_box->addWidget(b2);
  v_box->addWidget(b3);
  v_box->addWidget(b4);
  
  this->setLayout(v_box);

  connect(b, &QPushButton::clicked, this, &Prozor::onClick);
 
 this->resize(250, 150);
  this->setWindowTitle("Disconnect");
  this->show();
 
}

void Prozor::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Prozor window;
  
  return app.exec();
}
