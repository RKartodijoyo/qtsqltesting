#include <QCoreApplication>
#include <QtSql>
#include<QDebug>
#include<string>
#include<QString>
#include<iostream>
void declarationdatabase();
void showdatabase();
using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  
  QString nama,password;
  string nama1,password1;
  int state;
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("password");
  db.setDatabaseName("crud");
  cout << "Please enter your user name: ";
          cin >> nama1;
          cout << "Please enter your user password: ";
          cin >> password1;
          nama =QString::fromStdString(nama1);
          password =QString::fromStdString(password1);
  if(db.open())
  {
      qDebug()<<"bisa";
           QSqlQuery query;
           if(query.exec("SELECT * FROM user"))
           {
               while(query.next())
               {
                   if(query.value(1).toString()==nama && query.value(2).toString()==password)
                   {  qDebug()<<"bisa login";
                       cout << "Press 1 show user: "<<endl;
                       cout << "Press 2 add user "<<endl;
                       cout << "Press 3 change nama user "<<endl;
                       cout << "Press 4 change password user "<<endl;
                       cout << "Press 5 change delete user "<<endl;
                       cout << "Press : ";
                        cin >> state;
                        if(state==1){
                        showdatabase();
                            
                         
                          }
                        else if(state==2){

                            string idku,nameku,passwordku;
                            cout << "insert id  :  ";
                            cin >> idku;
                             
                            cout << "insert name  :  ";
                             cin >> nameku;
                             cout << "insert password  :  ";
                             cin >> passwordku;
                             query.prepare("INSERT INTO user ( id, nama, password) "
                                                 "VALUES (:id, :nama, :password)");
                             
                             query.bindValue(":id", QString::fromStdString(idku));
                                  query.bindValue(":nama", QString::fromStdString(nameku));
                                  query.bindValue(":password", QString::fromStdString(passwordku));
                                   query.exec();
                                   qDebug() << "Error = " << db.lastError().text();
                            }
                        else if(state==3){
                            showdatabase();
                            string choose,changename;
                            cout << "choose id  :  ";
                             cin >> choose;
                             cout << "change name  :  ";
                              cin >> changename;
                              
                              query.prepare("UPDATE user SET nama = :name WHERE id= :id");
                              query.bindValue(":name", QString::fromStdString(changename));
                              query.bindValue(":id", QString::fromStdString(choose));
                                           query.exec();
                                           qDebug() << "Error = " << db.lastError().text();
                          }
                        else if(state==4){
                            showdatabase();
                            string choose,changepassword;
                            cout << "choose id  :  ";
                             cin >> choose;
                             cout << "change password  :  ";
                              cin >> changepassword;
                              
                              query.prepare("UPDATE user SET password = :password WHERE id= :id");
                              query.bindValue(":password", QString::fromStdString(changepassword));
                              query.bindValue(":id", QString::fromStdString(choose));
                                           query.exec();
                                           qDebug() << "Error = " << db.lastError().text();
                          }
                             else if(state==5){
                            
                            string choose,changename;
                            cout << "choose id  :  ";
                             cin >> choose;
                             query.prepare("DELETE FROM user where  id = :id");
                             query.bindValue(":id", QString::fromStdString(choose));
                                  query.exec();
                                  qDebug() << "Error = " << db.lastError().text();
                          }
                        else{
                            qDebug() << "Error = " << db.lastError().text();
                          }
                      
   
                    } else{}}
       }
      else {
      }

         
qDebug() << "Error = " << db.lastError().text();
    }
  db.close();
  
  return a.exec();
}
void showdatabase(){
    QSqlQuery query;
  query.exec("SELECT * FROM user ");
  while (query.next()) {
      QString idq = query.value(0).toString();
           QString namaq = query.value(1).toString();
           QString passwordq = query.value(2).toString();
           qDebug() << idq<< namaq<< passwordq;
       }
}

