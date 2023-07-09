#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<vector>
#include <utility>
#include<string>
using namespace std;
class student_profile
{
public:
char name[20];
int admno;
long long int phone_number;
char password[100];
float maths, sci, sst;
float tot;
float percentage;
student_profile ()
{
maths = 0, sci = 0, sst = 0;
tot = 0, percentage = 0;
}
void markss ();
void getdata ()
{
ofstream fo;
cout << "\n--------------\n";
cout << "\n Name:";
cin >> (name);
cout << "\n Admno:";
cin >> admno;
cout << "\n Phone number:";
cin >> phone_number;
cout << "\n pass length :";
int n;
cin >> n;
int i = 0;
password[n] ={0};
while (i < n)
{
cin >> password[i];
i++;
}
}
void modify ();
void display ()
{
cout << "\n--------------\n";
cout << "Name:" << name << endl;
cout << "Admno:" << admno << endl;
cout << "Phone number:" << phone_number << endl;
}
};
void
student_profile::markss ()
{
cout << "\n--------------\n";
cout << "\n name: " << (name);
cout << "\n maths marks: " << maths;
cout << "\n science marks: " << sci;
cout << "\n sst marks: " << sst;
cout << "\n total marks:" << tot;
cout << "\n percentage: " << percentage;
}
void student_profile::modify ()
{
int a;
cout << "\n--------------\n";
cout << "Name:" << name << endl;
cout << "Admno:" << admno << endl;
cout << "Phone number:" << phone_number << endl;
cout << "\n PRESS 1 TO RETAIN & PRESS 0 TO CHANGE ";
cout << "\n 1.NAME :";
cin >> a;
if (a == 0)
{
cout << "\n new name :";
cin >> name;
strcpy (this->name, name);
}
cout << "\n PHONE NUMBER:";
cin >> a;
if (a == 0)
{
cout << "\n new ph no:";
cin >> phone_number;
this->phone_number = phone_number;
}
cout << "\n PASSWORD:";
cin >> a;
if (a == 0)
{
cout << "\n enter your current password :";
char p[100];
cin >> p;
if (strcmp (p, password) == 0)
cout << "\n enter new password:";
else
cout << "\n wrong password input :(";
}
}
vector<string> notification;
int nu=0;
class course_registration:public student_profile
{
int course_code;
char course_name[40];
public:
void add_record ()
{
cout << "\n--------------\n";
cout<< "course name:_course code:\n maths_101\nscience_102\n sst_103"<<endl;
cout << "\n enter course code in number :";
cin >> course_code;
cout << "\n enter the course name :";
cin >> (course_name);
}
void display_record ()
{
cout << "\n ------- COURSE REGISTERD FOR -----------\n";
display ();
cout << "\n code:" << course_code << endl;
cout << "\n course name:" << course_name << endl;
cout << "\n--------------\n";
}
};
vector < course_registration > record;
pair<int,int> num_of_attempts[1000];
vector< course_registration > deleted_students;
class student_login_page:public student_profile
{
public:
void login_credential ();
void teacher_or_student ();
};
void student_login_page::login_credential ()
{
line:
cout << "\n--------------\n";
go:
cout << "\n 1. LOGIN \n 2. SIGN-UP \n 3.BACK \n option number:";
int value;
cin >> value;
if (value == 2)
{
fstream filin;
filin.open ("recordd.txt", ios::in | ios::out | ios::app);
course_registration st;
st.getdata ();
num_of_attempts[nu].first=st.admno;
num_of_attempts[nu].second=0;
nu++;
cout<<"\n you are "<<nu<<" th student \n";
int f=0;
for(int i=0;i<record.size();i++)
{ if(record[i].admno==st.admno)
{cout<<"\n sorry , but this admno already exist :";
f=1;
}
}
if(f==0)
{record.push_back (st);
filin.write ((char *) &st, sizeof (st));}
else
{cout<<"\n enter correct admno : ";
goto go;
}
filin.close ();
cout << "\n do you want to go through other options (y/n) : ";
char b;
cin >> b;
if (b == 'y');
goto line;
}
else if (value == 3)
{
teacher_or_student ();
}
else if (value == 1)
{
char pass[100];
cout << "\n enter admission number : ";
int a;
cin >> a;
cout << "\n pass length :";
int n;
cin >> n;
int i = 0;
pass[n] =
{
0};
while (i < n)
{
pass[i] = getch ();
cout << "*";
i++;
}
int f = 0;
for (int i = 0; i < record.size (); i++)
{
if (record[i].admno == a && strcmp (record[i].password, pass) == 0)
{
f = 1;
break;
}
}
if (f == 0)
{ int j,k,i;
for (i = 0; i < record.size (); i++)
{
if (record[i].admno == a )
{for(j=0;j<record.size();j++)
{if(num_of_attempts[j].first==a)
{num_of_attempts[j].second =num_of_attempts[j].second+1;
break;}
}
if(num_of_attempts[j].second>=3)
{cout<<"\n straight away contact to your admin , your id has been deleted,\n because wrong login credential 3 times ";
cout<<"\n earlier number of students were:"<<record.size();
deleted_students.push_back(record[i]);
course_registration *rr = &record[i];
record.erase (record.begin () + i);
cout<<"\n after deleting you , it is : "<<record.size();
}
break;
}
}
cout << "\n wrong login credentials :(";
teacher_or_student ();
}
else
{
stu_start:
int ans;
cout << "\n------WELCOME--------\n";
cout <<"\n 1.Modify data \n 2.Course registration \n 3.View result \n 4.Display info \n5.Notifications posted by teacher for all \n 6.Logout\n Choose(1/2/3/4/5/6)";
cin >> ans;
course_registration st;
if(ans==5)
{cout<<"\n Notifications are as follows :";
for(int i=0;i<notification.size();i++)
{ cout<<"\n";
cout<<i+1<<")"<<notification[i];
}
}
else if (ans == 1)
{
cout << "\n-----YOUR CURRENT DATA---------\n";
cout << "\n Enter your admission number:";
int val;
cin >> val;
int i;
for (i = 0; i < record.size (); i++)
{
if (val == record[i].admno)
{
record[i].modify ();
break;
}
if (i == record.size () - 1)
{
cout << "\n entered wrong admission no";
}
}
if (i < record.size () - 1)
{
fstream fileo ("recordd.txt",
ios::in | ios::out | ios::binary);
int pos;
course_registration object;
while (!fileo.eof ())
{
pos = fileo.tellg ();
fileo.read ((char *) &object, sizeof (object));
if (object.admno == val)
{
cout <<
"\n Fill in the details once again to confirm :";
object.modify ();
fileo.seekg (pos);
fileo.write ((char *) &object, sizeof (object));
break;
}
}
}
}
else if (ans == 2)
{
cout << "\n Enter your admission number:";
int val;
cin >> val;
int i;
for (i = 0; i < record.size (); i++)
{
if (val == record[i].admno)
{
record[i].add_record ();
break;
}
if (i == record.size () - 1)
{
cout << "\n Entered wrong admission no";
}
}
cout <<
"\n -------: You have registered for following course :------\n";
record[i].display_record ();
}
else if (ans == 6)
{
cout << "\n Hope to see you soon :) ";
teacher_or_student ();
}
else if (ans == 4)
{ cout << "\n Enter your admission number:";
int val;
cin >> val;
int i;
for (i = 0; i < record.size (); i++)
{
if (val == record[i].admno)
{ cout << "\n -----YOUR INFO----\n";
record[i].display ();
break;
}
if (i == record.size () - 1)
{
cout << "\n Entered wrong admission no";
}
}
}
else if (ans == 3)
{
cout << "\n Enter your admission number:";
int val;
cin >> val;
for (int i = 0; i < record.size (); i++)
{
if (val == record[i].admno)
{
record[i].markss ();
break;
}
if (i == record.size () - 1)
{
cout << "\n Entered wrong admission no";
}
}
}
goto stu_start;
}
}
}
class teacher:public student_login_page
{
int frequency;
public:
void display_all_options ();
void display_record_of_each_student ();
void insertion_of_a_new_stu_by_teacher ();
void deletion_of_a_stu ();
void postnotification();
void marks_enter_of_stu ();
void percentage_calculator ();
void percentage_filter ();
void frequency_of_students_at_percentage ();
void topper ();
void repeat ();
void merit_certificate_holder ();
void display_from_file ();
void totalstrength();
};
void student_login_page::teacher_or_student ()
{
cout << "\n 1.TEACHER \n 2.STUDENT \n Option(1/2/0 to exit):";
int ans;
cin >> ans;
if (ans == 2)
{
login_credential ();
}
else if (ans == 1)
{
teacher obj;
obj.display_all_options ();
}
else
{
exit(1);
cout << "\n ----END----\n";
}
}
void teacher::display_all_options ()
{
char passc[100]="12345678";
cout<<"\n To enter , input the correct passoword : ";
int i=0;
char pass[100]={0};
while(i<8)
{
pass[i]=getch();
cout<<"*";
i++;
}
if(strcmp(pass,passc)==0)
{ cout << "\n---------WELCOME--------\n";
cout <<"\n 1.DISPLAY \n 2.INSERT STUDENT RECORD \n 3.DELETE STUDENTRECORD \n 4.ENTER MARKS \n 5.PERCENTAGE CALCULATOR ";
cout << "\n 6.PERCENTAGE FILTER \n 7.FREQUENCY \n 8.TOPPER \n9.REPEAT \n10.MERIT CERTIFICATES \n 11.DISPLAY FROM FILE \n";
cout<<"12.POST NOTIFICATION \n 13 TOTAL STRENGTH \n 14 STUDENTS DELETED FROM LIST \n 15 LOGOUT \n Option number:";
int o;
cin >> o;
switch (o)
{
case 1:
display_record_of_each_student ();
break;
case 2:
insertion_of_a_new_stu_by_teacher ();
break;
case 3:
deletion_of_a_stu ();
break;
case 4:
marks_enter_of_stu ();
break;
case 5:
percentage_calculator ();
break;
case 6:
percentage_filter ();
break;
case 7:
frequency_of_students_at_percentage ();
break;
case 8:
topper ();
break;
case 9:
repeat ();
break;
case 10:
merit_certificate_holder ();
break;
case 11:
display_from_file ();
break;
case 12:
postnotification();
break;
case 13:
totalstrength();
break;
case 14:
cout<<"\n List of student's whose ID got\n deleted due to overflow\n in no of attempts of filling pass: \n ";
for(int i=0;i<deleted_students.size();i++)
{ cout<<i+1<<") ";
deleted_students[i].display();}
break;
default:
cout << "\n See you soon \n";
teacher_or_student ();
break;
}
}
else
{cout<<"\n Wrong passcode ";
teacher_or_student();
}
}
void teacher:: totalstrength()
{cout<<"\n Total strength is : "<<record.size();
cout<<"\n";
display_all_options();
}
void teacher::display_record_of_each_student ()
{
cout << "\n----------------------\n";
int j,k;
int n=record.size();
for(j=0;j<n;j++)
{ for(k=0;k<n-1;k++)
{if(record[k].admno>record[k+1].admno)
{ course_registration temp=record[k];
record[k]=record[k+1];
record[k+1]=temp;
}
}
}
for (int i = 0; i < record.size (); i++)
{
cout << "\n" << i + 1 << ".)";
record[i].display ();
cout << "\n";
}
display_all_options ();
void teacher::insertion_of_a_new_stu_by_teacher ()
{
course_registration ob;
ob.getdata ();
ob.add_record ();
record.push_back (ob);
display_all_options ();
}
void teacher::deletion_of_a_stu ()
{
cout << "\n -----DELETION-----\n";
if(record.size()!=0){
cout << "\n Enter admission number to be deleted:";
int a;
cin >> a;
ifstream f;
ofstream te;
course_registration o;
f.open ("recordd.txt", ios::in);
te.open ("tempp.txt", ios::out);
while (!f.eof ())
{
f.read ((char *) &o, sizeof (o));
if (o.admno != a)
{
te.write ((char *) &o, sizeof (o));
}
else if (o.admno == a)
{
cout <<
"\n The following student record is deleted from file :~ \n";
o.display ();
}
}
f.close ();
te.close ();
remove ("record.txt");
rename ("tempp.txt", "recordd.txt");
for (int i = 0; i < record.size (); i++)
{
if (record[i].admno == a)
{
cout << "\n Record found \n";
course_registration *rr = &record[i];
record.erase (record.begin () + i);
cout << a << " Deleted , now number of students are :" <<
record.size ();
break;
}
if (i == record.size () - 1)
cout << "\n Record not found";
}
cout << "\n Now number of students left : " << record.size ();
display_all_options ();
}
else
cout<<"\n UNDERFLOW \n";
}
void teacher::marks_enter_of_stu ()
{
cout << "\n-----MARKS PART-----\n";
s:
cout << "\n Enter adm number whose marks has to be added:";
int r, m;
cin >> r;
for (int i = 0; i < record.size (); i++)
{
if (r == record[i].admno)
{
cout << "\n Maths marks :";
cin >> m;
record[i].maths = m;
cout << "\n Science marks :";
cin >> m;
record[i].sci = m;
cout << "\n Sst marks :";
cin >> m;
record[i].sst = m;
record[i].tot = record[i].maths + record[i].sci + record[i].sst;
record[i].percentage = record[i].tot / 3;
break;
}
}
cout << "\n Press 1 to add marks of other : ";
int ans;
cin >> ans;
if (ans == 1)
goto s;
display_all_options ();
}
void teacher::percentage_calculator ()
{
cout << "\n-----PERCENTAGE----\n";
cout <<"\n 1.Show percentage of all students \n 2.show percentage of a particular student \n enter option :";
int opt;
cin >> opt;
if (opt == 2)
{
cout << "\n Enter admission number :";
int a;
cin >> a;
cout << "\n PERCENTAGE :";
for (int i = 0; i < record.size (); i++)
{
if (record[i].admno == a)
{
record[i].percentage = (record[i].tot / 3);
cout << record[i].percentage;
}
}
}
else if (opt == 1)
{
cout << "\n Percentage of all ----->\n";
for (int i = 0; i < record.size (); i++)
{
record[i].percentage = (record[i].tot / 3);
record[i].markss ();
}
}
display_all_options ();
}
void teacher::percentage_filter ()
{
cout << "\n-----PERCENTAGE FILTER------\n";
float l, u,frequency=0;
cout << "\n Enter the range , first enter lower value and then upper val:";
cin >> l >> u;
cout << "\n The following student lies in the range :\n";
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage >= l && record[i].percentage <= u)
{
frequency++;
record[i].markss ();
}
}
cout << "\n Total number of students in the range are :";
cout << frequency;
display_all_options ();
}
void teacher::frequency_of_students_at_percentage ()
{
float l, u;
frequency=0;
cout << "\n Enter the range , first enter lower value and then upper val:";
cin >> l >> u;
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage >= l && record[i].percentage < u)
{
frequency++;
}
}
cout << "\n Total number of students in the range are :";
cout << frequency;
display_all_options ();
}
void teacher::topper ()
{
cout << "\n---TOPPER---\n";
cout << "The follwing student/s has/have topped :";
float max = 0;
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage > max)
max = record[i].percentage;
}
int k = 1;
cout << "\n HIGHEST PERCENTAGE IS : " << max;
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage == max)
cout << k << ".) " << record[i].name, k++;
}
display_all_options ();
}
void teacher::repeat ()
{
cout << "\n---REPEAT---\n";
cout << "The follwing student/s has/have to repeat :";
int k = 1;
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage < 33.0)
cout << k << ".) " << record[i].name, k++;
}
display_all_options ();
}
void teacher::merit_certificate_holder ()
{
cout << "\n---MERIT CERTIFICATE HOLDERS---\n";
cout << "The follwing student/s recieves merit certificates :";
int k = 1;
for (int i = 0; i < record.size (); i++)
{
if (record[i].percentage >= 90)
cout << k << ".) " << record[i].name, k++;
}
display_all_options ();
}
void teacher::display_from_file ()
{
cout << "\n Display students info from file : ";
ifstream fin ("recordd.txt", ios::in);
course_registration o;
int i = 1;
while (!fin.eof ())
{
cout << i << ") ";
fin.read ((char *) &o, sizeof (o));
cout << o.name;
i++;
}
fin.close ();
}
void teacher::postnotification()
{cout<<"\n Enter notification : ";
string str;cin>>str;
notification.push_back(str);
teacher_or_student();
}
int main ()
{
student_login_page eg;
eg.teacher_or_student ();
return 0;
}
