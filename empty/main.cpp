//自上而下非递归语法分析
#include<iostream>
#include<stdlib.h>
#include<string>
#include<stack>
#include<queue>

using namespace std;

static string ahead="";//当前正待处理的输入记号
static string sub="";//当前待处理记号被处理后的输入


string str[16][11]= {{"5","error","error","4","error","error","error","error","1","2","3"}, //0
					{"error","6","error","error","error","7","error","acc"," "," "," "},    //1
					{"error","r3","8","error","r3","r3","9","r3"," "," "," "},              //2
					{"error","r6","r6","error","r6","r6","r6","r6"," "," "," "},            //3
					{"5","error","error","4","error","error","error","error","10","2","3"}, //4
					{"error","r8","r8","error","r8","r8","r8","r8"," "," "," "},            //5
					{"5","error","error","4","error","error","error","error"," ","11","3"}, //6
					{"5","error","error","4","error","error","error","error"," ","12","3"}, //7
					{"5","error","error","4","error","error","error","error"," "," ","13"}, //8
					{"5","error","error","4","error","error","error","error"," "," ","14"}, //9
					{"error","6","error","error","15","7","error","error"," "," "," "},     //10
					{"error","r1","8","error","r1","r1","9","r1"," "," "," "},              //11
					{"error","r2","8","error","r2","r2","9","r2"," "," "," "},              //12
					{"error","r4","r4","error","r4","r4","r4","r4"," "," "," "},            //13
					{"error","r5","r5","error","r5","r5","r5","r5"," "," "," "},            //14
					{"error","r7","r7","error","r7","r7","r7","r7"," "," "," "}};           //15   s5改写为5，方便移进时操作

string _end[11] = {"id","+","*","(",")","-","/","$","E","T","F"};
string wen[8] = {"E->E+T","E->E-T","E->T","T->T*F","T->T/F","T->F","F->(E)","F->id"};

int key(string s){
    if(s=="id")return 0;if(s=="+"||s=="E->E+T")return 1;
    if(s=="*"||s=="E->T")return 2;if(s=="("||s=="T->T*F")return 3;
    if(s==")"||s=="T->F")return 4;if(s=="-"||s=="F->(E)")return 5;
    if(s=="/"||s=="F->id")return 6;if(s=="$")return 7;
    if(s=="E")return 8;if(s=="T")return 9;if(s=="F")return 10;
}

void match(string t);
string nextToken();
void error();


queue<int>num1;
//保存数字
void num(char* str){
    string sub = str;
    int i = 0;
    for(int j = 0;j<sub.length();j++){
        if(str[j]>='0'&&str[j]<='9'){
            string sub1;
            for(i = j;str[i]>='0'&&str[i]<='9';i++){
                sub1 = sub1+str[i];
                j = i;
            }
            int s = atoi(sub1.c_str());
            num1.push(s);
        }

    }
}

void error()
{
    cout<<"error"<<endl;
}


string nextToken()//获取下一个词法记号
{
    if(sub[0]>='0'&&sub[0]<='9')
    for(int i = 0;i<sub.length();i++){
        if(sub[i]>='0'&&sub[i]<='9')
            continue;
        else{
            sub=sub.substr(i,sub.size()-i);
            return "id";
        }
    }

    else
    {
        string s=sub.substr(0,1);
        sub=sub.substr(1,sub.size()-1);
        return s;
    }
}

int main()
{
    //不用自己输入#
    char a[100]={};//保存用户输入
    cout<<"输入字符串："<<endl;
    cin.getline(a,100);//遇见回车表示输入结束
    sub=a;
    sub+='$';
    ahead=nextToken();

    num(a);

    stack<string> s;
    stack<int> num2;
    s.push("0");

    while(1){
    string top = s.top();               //移进
        if(str[atoi(top.c_str())][key(ahead)]=="4"||str[atoi(top.c_str())][key(ahead)]=="6"||
           str[atoi(top.c_str())][key(ahead)]=="7"||str[atoi(top.c_str())][key(ahead)]=="8"||str[atoi(top.c_str())][key(ahead)]=="9"||
           str[atoi(top.c_str())][key(ahead)]=="15"){
            s.push(ahead);
            s.push(str[atoi(top.c_str())][key(ahead)]);
            ahead = nextToken();
            cout<<"移进"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="5"){          //移进是数字的情况，把数字入栈
            s.push(ahead);
            s.push(str[atoi(top.c_str())][key(ahead)]);
            ahead = nextToken();

            num2.push(num1.front());
            num1.pop();
            cout<<"移进"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r1"){         //归约1~8
            for(int i  = 0;i<6;i++)
                s.pop();
            top = s.top();
            s.push("E");
            s.push(str[atoi(top.c_str())][key("E")]);

            int tem1 = num2.top();
            num2.pop();
            int tem2 = num2.top();
            num2.pop();
            num2.push(tem1+tem2);
            cout<<"按照"<<wen[0]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r2"){
            for(int i  = 0;i<6;i++)
                s.pop();
            top = s.top();
            s.push("E");
            s.push(str[atoi(top.c_str())][key("E")]);

            int tem1 = num2.top();
            num2.pop();
            int tem2 = num2.top();
            num2.pop();
            num2.push(tem2-tem1);
            cout<<"按照"<<wen[1]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r3"){
            for(int i  = 0;i<2;i++)
                s.pop();
            top = s.top();
            s.push("E");
            s.push(str[atoi(top.c_str())][key("E")]);
            cout<<"按照"<<wen[2]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r4"){
            for(int i  = 0;i<6;i++)
                s.pop();
            top = s.top();
            s.push("T");
            s.push(str[atoi(top.c_str())][key("T")]);

            int tem1 = num2.top();
            num2.pop();
            int tem2 = num2.top();
            num2.pop();
            num2.push(tem1*tem2);
            cout<<"按照"<<wen[3]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r5"){
            for(int i  = 0;i<6;i++)
                s.pop();
            top = s.top();
            s.push("T");
            s.push(str[atoi(top.c_str())][key("T")]);

            int tem1 = num2.top();
            num2.pop();
            int tem2 = num2.top();
            num2.pop();
            num2.push(tem2/tem1);
            cout<<"按照"<<wen[4]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r6"){
            for(int i  = 0;i<2;i++)
                s.pop();
            top = s.top();
            s.push("T");
            s.push(str[atoi(top.c_str())][key("T")]);
            cout<<"按照"<<wen[5]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r7"){
            for(int i  = 0;i<6;i++)
                s.pop();
            top = s.top();
            s.push("F");
            s.push(str[atoi(top.c_str())][key("F")]);
            cout<<"按照"<<wen[6]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="r8"){
            for(int i  = 0;i<2;i++)
                s.pop();
            top = s.top();
            s.push("F");
            s.push(str[atoi(top.c_str())][key("F")]);
            cout<<"按照"<<wen[7]<<"归约"<<endl;
        }else if(str[atoi(top.c_str())][key(ahead)]=="acc"){
            cout<<"分析完成"<<endl;
            cout<<num2.top()<<endl;
            break;
        }else{
            error();
            ahead = nextToken();
        }

    }

    return 0;
}
