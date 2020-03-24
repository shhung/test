#include <iostream>
#include <fstream>
#include <string>
#include "hw2.h"

using namespace std;

_List *insert(_List *head, int n){
    _List *tmp = NULL;
    tmp = new _List;
    tmp->num = n;
    tmp->next = head;
    head = tmp;
    tmp = NULL;
    return head;
}
void ReadList(istream &in, _List* &head){
    int n;
    in >> n;
    head = insert(head, n);
    while(in.get() != '\n'){
        in >> n;
        head = insert(head, n);
    }    
}
void Avgs (_List *head, _Data* data){
    int Num = 0, NumP = 0, NumN = 0;
    float Sum = 0, SumP = 0, SumN = 0;
    _List *tmp = head;
    while(tmp != NULL){
        Sum += tmp->num;
        Num++;
        if(tmp->num > 0){
            SumP += tmp->num;
            NumP++;
        }
        else if(tmp->num < 0){
            SumN += tmp->num;
            NumN++;
        }
        tmp = tmp->next;
    }
    data->Ave = Sum/Num;
    data->AveN = SumN/NumN;
    data->AveP = SumP/NumP;
}
int Large (_List *head, _Data* data){
    _List *tmp = head;
    int max = tmp->num, min = tmp->num;
    while(tmp != NULL){
        if(tmp->num > max){
            max = tmp->num;
        }
        if(tmp->num < min){
            min = tmp->num;
        }
        tmp = tmp->next;
    } 
    data->Maximun = max;
    data->Minimum = min;
}
void Display (_List *head ,_Data &data){
    /*
    _List *tmp = head;
    while(tmp != NULL){
        cout << tmp->num << endl;
        tmp = tmp->next;
    }
    tmp = NULL;
    */
    cout << "Ave:" << data.Ave << endl;
    cout << "AveN:" << data.AveN << endl;
    cout << "AveP:" << data.AveP << endl;
    cout << "Max:" << data.Maximun << endl;
    cout << "Min:" << data.Minimum << endl;
}
int main(int argc, char** argv){
    ifstream in(argv[1]);
    _List *headptr = NULL;
    _Data data;

    ReadList(in, headptr);
    Avgs(headptr, &data);
    Large(headptr, &data);
    Display(headptr ,data);
    return 0;
}