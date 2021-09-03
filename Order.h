
#include"employee.h"
#include<iomanip>
#include<ctime>
#include<fstream>
using namespace std;
class Order
{
    public:
    void read_tasks();
    void read_employees();
    void today();
    void month();
    string Now() const;
    void now() const;
    void addTask(string ,Date&,Date&);
    void findtime(unsigned int,unsigned int);
    void free(  Date&);
    void assigntask(string,string);
    void addemployee(string,string ,unsigned int,unsigned int,unsigned int,unsigned int);
    void exit();
    void schedule(string,unsigned int,unsigned int);
    void print_employee_tasks(string);
    void print_employees_list();
    private:
    vector<employee>employeelist;
    vector<task> yearbook[12][31];
    static const string monthName[12];
    

};
const string Order::monthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
void Order:: addTask(string taskname,Date& taskstart,Date& taskfinish)
{
    task temp(taskname,taskstart,taskfinish);
    (taskstart.month)--;
    (taskfinish.month)--;
    yearbook[taskstart.getMonth()][taskstart.getDay()].push_back(temp);
}
string Order::Now()const
{
    time_t now = time(0);
    string s = ctime(&now);
    return s;
}
void Order::today()
{
    unsigned int monthNow=0;
    unsigned int dayNow=0;
    string s=Now();
    string r = s.substr(4, 3); 
    for(;monthNow<12;++monthNow)
    {
        if(monthName[monthNow]==r)
            break;
    }
    monthNow;
    dayNow=((s[8]-'0')*10);
    dayNow+=(s[9]-'0');
    sort(yearbook[monthNow][dayNow].begin(),yearbook[monthNow][dayNow].end());
     cout<<"This day works :"<<endl;
    for(auto it=yearbook[monthNow][dayNow].begin();it!=yearbook[monthNow][dayNow].end();++it)
    
        cout<<it->getNameTask()<<"-("<<it->getStartTask().getMonth()<<"/"<<it->getStartTask().getDay()<<" "
                <<it->getStartTask().getHour()<<":"<<it->getStartTask().getMinute()<<"-"<<it->getFinishTask().getHour()<<":"<<it->getFinishTask().getMinute()<<")"<<endl;
        
    
}
void Order::month()
{
    cout<<"This month works :"<<endl;
    unsigned int monthNow=0;
    string s=Now();
    string r = s.substr(4, 3); 
    for(;monthNow<12;++monthNow)
    {
        if(monthName[monthNow]==r)
            break;
    }
    
    for(int i=0;i<31;++i)
    {
        sort(yearbook[monthNow][i].begin(),yearbook[monthNow][i].end());
        for(auto it=yearbook[monthNow][i].begin();it!=yearbook[monthNow][i].end();++it)
            cout<<it->getNameTask()<<"-("<<it->getStartTask().getMonth()<<"/"<<it->getStartTask().getDay()<<" "
                <<it->getStartTask().getHour()<<":"<<it->getStartTask().getMinute()<<"-"<<it->getFinishTask().getHour()<<":"<<it->getFinishTask().getMinute()<<")"<<endl;
    }     
}
void Order::free( Date &A)
{
    (A.month)--;
    sort(yearbook[A.getMonth()][A.getDay()].begin(),yearbook[A.getMonth()][A.getDay()].end());
    int flag=0;
    for(auto it=yearbook[A.getMonth()][A.getDay()].begin();it!=yearbook[A.getMonth()][A.getDay()].end();++it)
    {
        if(A>=it->getStartTask()&&A<=it->getFinishTask())
        { 
            
            if((it+1)==yearbook[A.getMonth()][A.getDay()].end())
                throw invalid_argument("U can not free your calender");
            auto element_remove=it;
            yearbook[A.getMonth()][A.getDay()].erase(element_remove);
        }
    }
    
}

void Order::findtime(unsigned int Ah,unsigned int Am)
{
    unsigned int monthNow=0;
    unsigned int dayNow=0;
    unsigned int hourNow=0;
    unsigned int MinNow=0;
    unsigned int a=Am;
    a+=(Ah*60);
    string s=Now();
    string r = s.substr(4, 3); 
    for(;monthNow<12;++monthNow)
    {
        if(monthName[monthNow]==r)
            break;
    }
    dayNow=((s[8]-'0')*10);
    dayNow+=(s[9]-'0');
     hourNow=((s[11]-'0')*10);
    hourNow+=(s[12]-'0');
    MinNow=((s[14]-'0')*10);
    MinNow+=(s[15]-'0');
    int i=dayNow;
    int flag=0;
    unsigned int h,m;
    for(;i<31;++i)
    {
        
        if(yearbook[monthNow][i].empty())
        {
            h=8;
            m=0;
            break;
        }
        else
        {
        sort(yearbook[monthNow][i].begin(),yearbook[monthNow][i].end());
        for(auto it=yearbook[monthNow][i].begin();it!=yearbook[monthNow][i].end();++it)
        {
             if((it+1)!=yearbook[monthNow][i].end())
             {
                 unsigned int tool=(((it+1)->getStartTask().getHour())-(it->getFinishTask().getHour()));
                 tool*=60;
                 tool+=(((it+1)->getFinishTask().getMinute())-(it->getStartTask().getMinute()));
                 if(tool>=a)
                 {
                     h=(it->getFinishTask().getHour());
                     m=(it->getFinishTask().getMinute());
                     flag=1;
                     break;
                 }
             }
           else if((it+1)==yearbook[monthNow][i].end())
           {
               unsigned int tool=(24-(it->getFinishTask().getHour()));
               tool*=60;
               tool-=(it->getFinishTask().getMinute());
                 if(tool>=a)
                 {
                     h=(it->getFinishTask().getHour());
                     m=(it->getFinishTask().getMinute());
                     flag=1;
                     break;
                 }
           }
        }
     if(flag==1)
         break;
      
        } 
    }
    unsigned int mf=(m+Am);
    unsigned int hf=(h+Ah);
    if(mf>=60)
    {
        mf-=60;
        ++hf;
    }
    if(hf>=24)
    {
        hf-=24;
        i++;
    }
        
    cout<<monthNow+1<<"/"<<i<<" "<<h<<":"<<m<<"-"<<hf<<":"<<mf<<endl;
}
void Order::assigntask(string SSID,string NAME)
{
    Date A;
    Date B;
    unsigned int monthNow=0;
    string s=Now();
    string r = s.substr(4, 3); 
    for(;monthNow<12;++monthNow)
    {
        if(monthName[monthNow]==r)
            break;
    }
    for(int j=monthNow;j<12;++j)
    {
        for(int i=0;i<31;++i)
        {
            for(auto it=yearbook[j][i].begin();it!=yearbook[j][i].end();++it)
                {
                    if(it->getNameTask()==NAME)
                    {
                        A=it->getStartTask();
                        B=it->getFinishTask();
                        break;
                    }
                        
                }
        }
    }
    task temp(NAME,A,B);
    for(auto it=employeelist.begin();it!=employeelist.end();++it)
    {
        if(it->getSsid()==SSID)
        {
            it->employeetasks.push_back(temp);
            break;
        }
            
            
    }
 }

void Order::now()const
{
    unsigned int monthNow=0;
    unsigned int dayNow=0;
    unsigned int hourNow=0;
    unsigned int MinNow=0;
    string s=Now();
    string r = s.substr(4, 3); 
    for(;monthNow<12;++monthNow)
    {
        if(monthName[monthNow]==r)
            break;
    }
    dayNow=((s[8]-'0')*10);
    dayNow+=(s[9]-'0');
    hourNow=((s[11]-'0')*10);
    hourNow+=(s[12]-'0');
    MinNow=((s[14]-'0')*10);
    MinNow+=(s[15]-'0');
    cout<<monthNow+1<<"/"<<dayNow<<setw(10)<<hourNow<<":"<<MinNow<<endl;


}
void Order::addemployee(string Name,string Ssid ,unsigned int hs,unsigned int ms,unsigned int hf,unsigned int mf)
{
    employee temp(Name,Ssid,hs,ms,hf,ms);
    employeelist.push_back(temp);  
}
void Order::schedule(string ssid,unsigned int mo,unsigned int day)
{
    auto it=employeelist.begin();
    --mo;
    for(;it!=employeelist.end();++it)
    {
        if(it->getSsid()==ssid)
            break;
    }
    it->employeetasks.clear();
    unsigned int employee_hour_start=it->getStartHour();
    unsigned int employee_minute_start=it->getStartMinute();
    unsigned int employee_hour_finish=it->getFinishHour();
    unsigned int employee_minute_finish=it->getFinishMinute();
    Date C(mo,day,employee_hour_start,employee_hour_finish);
    Date D(mo,day,employee_hour_finish,employee_minute_finish);
    sort(yearbook[mo][day].begin(),yearbook[mo][day].end());
    for(auto i=yearbook[mo][day].begin();i!=yearbook[mo][day].end();++i)
    {
        
        int flag=0;
        int flag2=0;
        for(auto r=it->employeetasks.begin();r!=it->employeetasks.end();++r)
        {
            
            if(i->getStartTask()<=r->getFinishTask()&&i->getStartTask()>=r->getStartTask())
            {
                flag2=1;
                break;
            }
        }

        if(i->getStartTask()>=C&&i->getFinishTask()<=D&&flag2==0)
        {
            for(auto j=(i+1);j!=yearbook[mo][day].end();++j)
            {
                
                if(i->getFinishTask()>=j->getFinishTask())
                {
                    ++flag;
                    break;
                }
            }

        }
        if(flag==0)
            it->employeetasks.push_back((*i));
    }

}
void Order::print_employee_tasks(string ssid)
{
    auto it=employeelist.begin();
    for(;it!=employeelist.end();++it)
    {
        
        if(ssid==it->getSsid())
            break;
            
    }
    for(auto it2=it->employeetasks.begin();it2!=it->employeetasks.end();++it2)
    {
        cout<<it2->getNameTask()<<"-("<<it2->getStartTask().getMonth()<<"/"
            <<it2->getStartTask().getDay()<<" "<<it2->getStartTask().getHour()<<":"
            <<it2->getStartTask().getMinute()<<"-"<<it2->getFinishTask().getHour()<<":"
            <<it2->getFinishTask().getMinute()<<")"<<endl;
    }

}
void Order::print_employees_list()
{
    for(auto it=employeelist.begin();it!=employeelist.end();++it)
    {
        cout<<it->getName()<<"-"<<it->getSsid()<<"-"<<it->getStartHour()<<":"
            <<it->getStartMinute()<<"-"<<it->getFinishHour()<<":"<<it->getFinishMinute()<<endl;
    }
}
void Order::exit()
{
    fstream binFile("tasks", ios::binary | ios::out);
    if(!binFile)
        cout << "Error in file!" << endl;
    for(int j=0;j<12;++j)
    {
        for(int i=0;i<31;++i)
        {
            for(auto it=yearbook[j][i].begin();it!=yearbook[j][i].end();++it)
            {
                string s=it->getNameTask();
                Date start=it->getStartTask();
                Date finish=it->getFinishTask();
                unsigned int sizes=s.length();
                binFile.write(reinterpret_cast<char*>(&sizes),sizeof(unsigned int));
                binFile.write(reinterpret_cast<char*>(&s[0]),sizes);
                binFile.write(reinterpret_cast<char*>(&start),sizeof(Date));
                binFile.write(reinterpret_cast<char*>(&finish),sizeof(Date));
            }
        }
    }
   binFile.close();

    fstream binFile2("employees", ios::binary | ios::out);
    if(!binFile2)
        cout << "Error in file!" << endl;
    for(auto it=employeelist.begin();it!=employeelist.begin();++it)
    {
        string n=it->getName();
        string ss=it->getSsid();
        unsigned int hour_start=it->getStartHour();
        unsigned int min_start=it->getStartMinute();
        unsigned int hour_finish=it->getFinishHour();
        unsigned int min_finish=it->getFinishMinute();
        unsigned int sizen=n.length();
        unsigned int sizess=ss.length();
        binFile2.write(reinterpret_cast<char*>(&sizen),sizeof(unsigned int));
        binFile2.write(reinterpret_cast<char*>(&n[0]),sizen);
        binFile2.write(reinterpret_cast<char*>(&sizess),sizeof(unsigned int));
        binFile2.write(reinterpret_cast<char*>(&ss[0]),sizess);
        binFile2.write(reinterpret_cast<char*>(&hour_start),sizeof(unsigned int));
        binFile2.write(reinterpret_cast<char*>(&min_start),sizeof(unsigned int));
        binFile2.write(reinterpret_cast<char*>(&hour_finish),sizeof(unsigned int));
        binFile2.write(reinterpret_cast<char*>(&min_finish),sizeof(unsigned int));
        for(auto it2=it->employeetasks.begin();it2!=it->employeetasks.begin();++it2)
        {
            string s=it2->getNameTask();
            Date start=it2->getStartTask();
            Date finish=it2->getFinishTask();
            unsigned int sizes=s.length();
            binFile.write(reinterpret_cast<char*>(&sizes),sizeof(unsigned int));
            binFile.write(reinterpret_cast<char*>(&s[0]),sizes);
            binFile.write(reinterpret_cast<char*>(&start),sizeof(Date));
            binFile.write(reinterpret_cast<char*>(&finish),sizeof(Date));
            
        }
    }
    binFile2.close();
}
void Order::read_tasks()
{
    fstream binFile("tasks", ios::binary | ios::in);
    if(binFile)
    {
         unsigned int sizes;
            Date A;
            Date B;
            binFile.read(reinterpret_cast<char*>(&sizes),sizeof(unsigned int));
            char title[sizes];
            binFile.read(reinterpret_cast<char*>(&title[0]),sizes);
            binFile.read(reinterpret_cast<char*>(&A),sizeof(Date));
            binFile.read(reinterpret_cast<char*>(&B),sizeof(Date));
            task temp(title,A,B);

        while(!binFile.eof())
        {
            yearbook[A.getMonth()][A.getDay()].push_back(temp);
            binFile.read(reinterpret_cast<char*>(&sizes),sizeof(unsigned int));
            char title[sizes];
            binFile.read(reinterpret_cast<char*>(&title[0]),sizes);
            binFile.read(reinterpret_cast<char*>(&A),sizeof(Date));
            binFile.read(reinterpret_cast<char*>(&B),sizeof(Date));
            task temp(title,A,B);
            
        }
    
    }
    binFile.close();
}
void Order::read_employees()
{
    fstream binFile2("employees", ios::binary | ios::in);
    if(!binFile2)
    {
        while(!binFile2.eof())
        {
            unsigned int size_name;
            unsigned int size_ssid;
            string Name;
            string ssid;
            unsigned int start_hour;
            unsigned int start_min;
            unsigned int finish_hour;
            unsigned int finish_min;
            vector<task>J;
            binFile2.read(reinterpret_cast<char*>(&size_name),sizeof(unsigned int));
            binFile2.read(reinterpret_cast<char*>(&Name[0]),size_name);
            binFile2.read(reinterpret_cast<char*>(&size_ssid),sizeof(unsigned int));
            binFile2.read(reinterpret_cast<char*>(&ssid[0]),size_ssid);
            binFile2.read(reinterpret_cast<char*>(&start_hour),sizeof(unsigned int));
            binFile2.read(reinterpret_cast<char*>(&start_min),sizeof(unsigned int));
            binFile2.read(reinterpret_cast<char*>(&finish_hour),sizeof(unsigned int));
            binFile2.read(reinterpret_cast<char*>(&finish_min),sizeof(unsigned int));
            employee temp(Name,ssid,start_hour,start_min,finish_hour,finish_min);
            employeelist.push_back(temp);
        }
        binFile2.close();
    }

}
    
