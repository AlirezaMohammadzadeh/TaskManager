#include"Order.h"
using namespace std;
int main()
{
    Order O;
     string s;
     cout<<"enter your order"<<endl;
    while(getline(cin,s))
    {
        if(s=="month")
        {
            O.month();
            cout<<"done"<<endl;
        }
        else if(s=="today")
        {
            O.today();
            cout<<"done"<<endl;
        }

        else if(s=="add task")
        {
            try
            {
            string name;
            string st;
            string f;
            cout<<"enter tasks name :";
            getline(cin,name);
            cout<<"enter satrt date:";
            getline(cin,st);
            cout<<"enter finish date";
            getline(cin,f);
            unsigned int sm=((st[0]-'0')*10+(st[1]-'0'));
            unsigned int sd=((st[3]-'0')*10+(st[4]-'0'));
            unsigned int sh=((st[6]-'0')*10+(st[7]-'0'));
            unsigned int smin=((st[9]-'0')*10+(st[10]-'0'));

            unsigned int fm=((f[0]-'0')*10+(f[1]-'0'));
            unsigned int fd=((s[3]-'0')*10+(f[4]-'0'));
            unsigned int fh=((f[6]-'0')*10+(f[7]-'0'));
            unsigned int fmin=((f[9]-'0')*10+(f[10]-'0'));
            Date start(sm,sd,sh,smin);
            Date finish(sm,sd,fh,fmin);
            O.addTask(name,start,finish);
            cout<<"done"<<endl;
            }
            catch(const exception& e)
            {
                cout << e.what() << '\n';
            }
            
            

        }
        else if(s=="now")
        {
            O.now();
            cout<<"done"<<endl;
        }
 
        else if(s=="add employee")
        {
           try
           {
             string name;
            string ssid;
            string st;
            string f;
            cout<<"enter employees name:";
            getline(cin,name);
            cout<<"enter employees ssid:";
            getline(cin,ssid);
            cout<<"enter employees start of work:";
            getline(cin,st);
            cout<<"enter employees finish of work:";
            getline(cin,f);
            unsigned int sh=((st[0]-'0')*10+(st[1]-'0'));
            unsigned int smin=((st[3]-'0')*10+(st[4]-'0'));
            unsigned int fh=((f[0]-'0')*10+(f[1]-'0'));
            unsigned int fmin=((f[3]-'0')*10+(f[4]-'0'));
            O.addemployee(name,ssid,sh,smin,fh,fmin);
            cout<<"done"<<endl;
           }
           catch(exception& e)
           {
               cout << e.what() << '\n';
           }
           
        }
        else if(s=="assign task")
        {
            string name;
            string ssid;
            cout<<"enter tasks name :";
            getline(cin,name);
            cout<<"enter employees ssid:";
            getline(cin,ssid);
            O.assigntask(ssid,name);
            cout<<"done"<<endl;
        }
        else if(s=="free")
        {
            try
            {
            string st;
            cout<<"enter the date:";
            getline(cin,st);
            unsigned int sm=((st[0]-'0')*10+(st[1]-'0'));
            unsigned int sd=((st[3]-'0')*10+(st[4]-'0'));
            unsigned int sh=((st[6]-'0')*10+(st[7]-'0'));
            unsigned int smin=((st[9]-'0')*10+(st[10]-'0'));
            Date start(sm,sd,sh,smin);
            O.free(start);
            cout<<"done"<<endl;
            }
            catch(exception& e)
            {
                cout << e.what() << '\n';
            }
        }
        else if(s=="find time")
        {
            try
            {
            cout<<"enter  time:";
            string st;
            getline(cin,st);
            
            unsigned int sh=((st[0]-'0')*10+(st[1]-'0'));
            unsigned int smin=((st[3]-'0')*10+(st[4]-'0'));
            O.findtime(sh,smin);
            cout<<"done"<<endl;
            }
            catch(const exception& e)
            {
                cout << e.what() << '\n';
            }
            

        }
        else if(s=="exit")
        {
            O.exit();
            cout<<"done"<<endl;
            break;
        }
        else if(s=="schedule")
        {
            string ssid;
            string date;
            cout<<"enter ssid:";
            getline(cin,ssid);
            cout<<"enter date:";
            getline(cin,date);
            unsigned int month=((date[0]-'0')*10+date[1]-'0');
            unsigned int day=((date[3]-'0')*10+date[4]-'0');
            O.schedule(ssid,month,day);
            cout<<"done"<<endl;
        }
        else if(s=="print employees tasks")
        {
            string ssid;
            cout<<"enter employsees ssid:";
            getline(cin,ssid);
            O.print_employee_tasks(ssid);
            cout<<"done"<<endl;
        }
        else if(s=="print employees list")
        {
            O.print_employees_list();
            cout<<"done"<<endl;
        }
        else
        {
            cout<<"wrong order"<<endl;
        }

    } 
}