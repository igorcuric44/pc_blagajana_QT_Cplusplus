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

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick();
    

  private:
    QPushButton *b;
    QLabel *l;
    QTableWidget *table;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {        
        
  b = new QPushButton("Push me");
  l=new QLabel("I have not be clicked");
  table=new QTableWidget();

  QHBoxLayout *h_box = new QHBoxLayout();
  h_box->setSpacing(5);
  
  h_box->addStretch();
  h_box->addWidget(l);
  h_box->addStretch();
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(b);
  v_box->addWidget(table);
  v_box->addLayout(h_box);
  
  this->setLayout(v_box);

  connect(b, &QPushButton::clicked, this, &Click::onClick);
 
 this->resize(250, 150);
  this->setWindowTitle("Disconnect");
  this->show();
 
}

void Click::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
