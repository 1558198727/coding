/**
* title :ģ����̵���---���ڶ༶���У��������ͼ
* author : liyunhao
* date:2018.04.17
* time : 23:42
*/
/*
���ȵ�˼�룬��Ϊ�����������С�
ÿ��ֻ�ӵ�һ��������ȡ�����̡�

ÿִ������һ�����еĽ��̷���һ�ζ��е�����

����ִ�У�ǰ�������������ȵ��ȣ����һ�����ȡ���̣�
Ϊ�����õ��������Ľ��̿����л���ִ��

�������Ӷ������к��������зֱ����ȡ������һ������
����һ������������뾺����

ֱ��һ�����п������еĽ���ִ�����
*/

#include<iostream>
#include<list>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <sstream>
using namespace std;
class tool{//������
public:
    int timeInterval;
    tool(){
        srand((unsigned)time( NULL ));//���������
        timeInterval = 100;//����ִ�еĵ�λ���
    }

    int getRandom(int a,int b){//����ָ����Χ�������
        int range = b - a;
        if(range==0){
            return 0;
        }else{
            return a + rand()%range;
        }

    }

};

class process{//������
public:
    int pid;    //���̱��
    int length;
    int level;
    process(int pid,int lengthOfProcess ){
        length = lengthOfProcess;
        if(length <= 0){
            cout<<"���̴���ʧ�ܣ�"<<endl;
        }else if(length <= 10){
            level = 1;
            this->pid = pid;
            cout<<"����"<<pid<<"����,����"<<length <<endl;
        }else if(length <= 20){
            level = 2;
            this->pid = pid;
            cout<<"����"<<pid<<"����,����"<<length <<endl;
        }else{
            level = 3;
            this->pid = pid;
            cout<<"����"<<pid<<"����,����"<<length <<endl;
        }
    }
    bool ajustLevel(){//�������̵����ȼ�
        if(length <= 0){
            cout<<"����������ϣ�"<<endl;
            return false;
        }else if(length <= 10){
            level = 1;
            return true;
        }else if(length <= 20){
            level = 2;
            return true;
        }else{
            level = 3;
            return true;
        }
    }
    bool doTheProcess(int timeLength){
        if(length <=0 ){
            cout<<"�����Ѿ�������ϣ�"<<endl;
            return false;
        }else{
            length -= timeLength;
            ajustLevel();
            if(length < 0){
                length = 0;
                return true;
            }else{
                return true;
            }
        }

    }
    bool finishThePro(){
        cout<<"����"<<pid<<"ִ�����"<<endl;
    }

};

class processQueue{
public:
    int level;  //���е����ȼ�
    list<process* > List[3];//������ͬ���ȼ��Ķ���
    processQueue(){
        ;
    }

    bool processIncoming(process*pro){
        int level = pro->level;
        int pid = pro->pid;
        if(level ==1){
            List[0].push_back(pro);
            cout<<"����"<<pid<<"�������"<<level<<endl;
            return true;
        }else if(level ==2){
            List[1].push_back(pro);
            cout<<"����"<<pid<<"�������"<<level<<endl;
            return true;
        }else if(level ==3){
            List[2].push_back(pro);
            cout<<"����"<<pid<<"�������"<<level<<endl;
            return true;
        }else{
            cout<<"δ֪�����ȼ���"<<endl;
            return false;
        }
    }

    //��ָ������������һ�����̣�����ԭ���Ķ���ɾ���ý���
    process* findProFromList(int listNum){
        listNum--;
        list<process*>::iterator itor;
        list<process*>::iterator delNode;
        int currentMin = 9999;
        process* shortestPro;
        if(List[listNum].size() == 0){
            //cout<<"����"<<listNum+1<<"�Ľ����Ѿ�ִ�����,��ȡʧ��"<<endl;
            return NULL;
        }else{
            //cout<<"Ԫ�ظ���"<<List1.size()<<endl;// ����list�е�Ԫ�ظ���
            for(itor = List[listNum].begin();itor!=List[listNum].end();itor ++){
                if((*itor)->length < currentMin){
                    currentMin = (*itor)->length;
                    shortestPro = (*itor);
                    delNode = itor;
                }
            }
            List[listNum].erase(delNode);//�ӽ��̶�����ɾ���ý���
            return shortestPro;
        }

    }


    process* findProFromListByRandom(int listNum){
        listNum--;
        list<process*>::iterator itor;
        int currentMin = 9999;
        process* shortestPro;
        tool atool;

        if(List[listNum].size() == 0){
            //cout<<"����"<<listNum+1<<"�Ľ����Ѿ�ִ�����,��ȡʧ��"<<endl;
            return NULL;
        }else{
            itor = List[listNum].begin();
            int queLen = List[listNum].size();
            //cout<<"queLen :"<<queLen<<endl;
            int randomNum = atool.getRandom(0,queLen-1);
            //cout<<"randomNum :"<<randomNum<<endl;
            //cout<<"���ѡȡ����"<<randomNum<<endl;
            advance(itor,randomNum);
            shortestPro = (*itor);
            List[listNum].erase(itor);//�ӽ��̶�����ɾ���ý���
            //printQue(1);
            return shortestPro;
        }


    }
    process* selectFromList1AndDoIt(){

        process* shortestPro;
        shortestPro = findProFromList(1);
        if(shortestPro!= NULL){
            shortestPro->finishThePro();
            //ajustLevelQueues();
            return shortestPro;
        }else{
            return NULL;
        }

    }
    process* selectList1ByRondomAndDoIt(){

        process* RondomPro;
        RondomPro = findProFromListByRandom(1);
        if(RondomPro!= NULL){
            RondomPro->finishThePro();
            //ajustLevelQueues();
            return RondomPro;
        }else{
            return NULL;
        }

    }
    bool ajustLevelQueues(){
        cout<<"����"<<endl;
        Sleep(500);
        process* p[3];
        p[0] = findProFromListByRandom(2);//�ӵڶ������������ȡ����
        p[1] = findProFromListByRandom(2);//�ӵڶ������������ȡ����
        p[2] = findProFromListByRandom(3);//�ӵ��������������ȡ����
        //process* p3 = findProFromList(3);//�ӵ����������л�ȡ���ʱ�����
        if( (p[0]==NULL) &&(p[1]==NULL) && (p[2]== NULL)){

            //cout<<"2,3�����Ѿ����ˣ�����ʧ��"<<endl;
            return false;
        }else if((p[0]==NULL)  && (p[2]!= NULL)){
            p[0] = findProFromListByRandom(3);//�ӵڶ������л�ȡ���ʱ�����
            p[1] = findProFromListByRandom(3);//�ӵ��������л�ȡ���ʱ�����
        }else if((p[0]!=NULL) &&(p[1]==NULL) && (p[2]!= NULL)){
            p[1] = findProFromListByRandom(3);//�ӵڶ������л�ȡ���ʱ�����
        }else if((p[0]!=NULL) &&(p[1]!=NULL) && (p[2]== NULL)){
            p[2] = findProFromListByRandom(2);//�ӵڶ������л�ȡ���ʱ�����
        }


        if(p[0]){
            p[0]->level = 1;
            cout<<"����"<<p[0]->pid<<endl;
            List[0].push_back(p[0]);//�����һ������
        }
        if(p[1]){
            p[1]->level = 1;
            cout<<"����"<<p[1]->pid<<endl;
            List[0].push_back(p[1]);//�����һ������
        }
        if(p[2]){
            p[2]->level = 1;
            cout<<"����"<<p[2]->pid<<endl;
            List[0].push_back(p[2]);//�����һ������
        }
        return true;
    }
    void printQue(int listNum){
        listNum--;
        list<process*>::iterator itor;
        for(itor = List[listNum].begin();itor!=List[listNum].end();itor ++){

                cout<<(*itor)->pid<<" ";
        }
        cout<<endl;
    }

};
class GanttChart{//�������ͼ����
public:
    string GamtString;
    GanttChart(){
        GamtString += "|";

    }
    string itoa(int pid){
        stringstream ss;
        ss<<pid;
        return ss.str();
    }
    bool add(process *p){
        //for(int i=0 ;i<p->length;i++){
            //char temp[10];
            string temp = itoa(p->pid);
            GamtString += temp;
        //}
        GamtString += "|";
    }
    void print(){
        cout<<"                 �ý��̵��ȵĸ���ͼ��"<<endl;
        cout<<"____________________________________________________________________"<<endl;
        cout<<GamtString<<endl;
        cout<<"��������������������������������������������������������������������"<<endl;
    }

};

class index{
public:

    void IndexGo(){
        tool tool1;
        processQueue proqueue;
        process* pro = NULL;
        process* proPrint=NULL;
        GanttChart gant;
        int timeInterval = tool1.timeInterval;

        for(int i=1;i<=25;i++){

            int Len = tool1.getRandom(1,50);
            //���ս��̳��ȵ�����˳������
            pro = new process(i,i+5);
            //������ɽ��̳���
            //pro = new process(i,rand()%30);
            proqueue.processIncoming(pro);
        }
        int pcCounter=0;
        //proqueue.findProFromListByRandom(1);
        //cout<<"proqueue.List[0].size() :"<<proqueue.List[0].size()<<endl;

        while(proqueue.List[0].size()>0){
            if(proqueue.List[0].size()>0){
                proPrint=proqueue.selectFromList1AndDoIt();
                Sleep(proPrint->length * timeInterval);
                gant.add(proPrint);
            }
            if(proqueue.List[0].size()>0){
                proPrint=proqueue.selectFromList1AndDoIt();
                Sleep(proPrint->length * timeInterval);
                gant.add(proPrint);

            }
            if(proqueue.List[0].size()>0){
                proPrint=proqueue.selectList1ByRondomAndDoIt();
                Sleep(proPrint->length * timeInterval);
                gant.add(proPrint);

            }
            //cout<<"proqueue.List[0].size() :"<<proqueue.List[0].size()<<endl;
            proqueue.ajustLevelQueues();


        }
        gant.print();
    }
};
int main(){
    cout<<"ģ����̵���---���ڶ༶����"<<endl;
    index inde;
    inde.IndexGo();
    return 0;
}

