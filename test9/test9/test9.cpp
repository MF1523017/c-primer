// test9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include<list>
#include<deque>
#include<vector>
#include<forward_list>
#include<array>
#include<stack>
#include<string>
using namespace std;

int main()
{
    /*
    list<deque<int>> ld;
    vector<int> v1;

    vector<double>::iterator iter;
    cout<<sizeof(iter)<<ends;
    cout<<v1.max_size()/1024<<endl;

    for(int i=0;i<10;i++)
        v1.push_back(i);
    auto it1=v1.begin();//vector<int>::iterator
    auto it2=v1.end();
    auto ct=it2-it1;//vector<int>::difference_type;����������֮��ľ���
    cout<<ct<<ends;

    it2=it1+5;//it2�ƶ��������Ԫ��λ��

    vector<int> v2(it1,it2);//��it1��it2֮������ݳ�ʼ��v2��
    cout<<v2.size()<<ends;


//forward_list


    vector<const char *> art={"a","bb","aaa"};

    forward_list<string> art1(art.begin(),art.end());//���Խ�һ��const char * ����ת����string����
    auto art1_itb=art1.cbegin();
    auto art1_ite=art1.cend();
    for(;art1_itb!=art1_ite;art1_itb++)
        cout<<(*art1_itb)<<ends;//forward_list��������֧�ֵݼ�����,��֧�ֵ���,�Ҳ�֧��size,��֧��push_back
    //cout << "Hello world!" << endl;
    auto prev=art1.before_begin();
    auto curr=art1.begin();//prev��curr֮ǰ��ɾ��������ɾ��ָ�����һ��Ԫ��
   // cout<<*(++curr)<<endl;
    while(curr!=art1.end())
    {
        if((*curr)=="bb")
            curr=art1.erase_after(prev);
        else
            prev=curr;
            ++curr;
    }
     for(auto art1_itb=art1.cbegin();art1_itb!=art1_ite;art1_itb++)
        cout<<(*art1_itb)<<ends;
//array

    array<int,10> sz={10,0};//array ����ָ����С���Ҳ��ܱ�������ʼ��
    array<int,10> sz1={0};//array �и�ֵ�������Ҵ�С������ͬ��������û��
    sz=sz1;
    sz1={0};//

//assign ����

    list<string>name;
    vector<char *> old;
    //name=old;//error
    name.assign(old.cbegin(),old.cend());//��ȷ
    name.assign(10,"hi");

//swap ����

    vector<string> s1(10);
    vector<string> s2(24);
    swap(s1,s2);//��array֮�⣬swap�����κ�Ԫ�ؽ��и��ƣ�ɾ���Ͳ�������ڳ���ʱ������ɣ����ı�����ڲ������ݽṹ
    //���ԣ���string ������������ָ��Ȳ�������ָ��ԭ��λ�ã����磬iterָ��s1[3],swap֮��ָ��s2[3]

//push_front
    list<int> ilist;
    for(size_t ix=0;ix!=4;ix++)
        ilist.push_front(ix);//��ͷ���룬���Ϊ3,2,1,0

    for(auto b=ilist.cbegin();b!=ilist.cend();b++)
        cout<<(*b)<<ends;
    cout<<endl;


//deque
    deque<int>dq;//dequeǰ�󶼿��Բ���
    for (size_t ix=0;ix!=4;ix++)
        dq.push_back(ix);
     for(size_t ix=0;ix!=4;ix++)
        dq.push_front(ix);
    for(auto b=dq.cbegin();b!=dq.cend();b++)
        cout<<(*b)<<ends;
    cout<<endl;


//insert
    list<string> slist{"hi"};
    slist.insert(slist.begin(),10,"ha");//��begin ֮ǰ����10����ha��
    slist.insert(slist.begin(),{"hello","world"});
    for(auto b=slist.begin();b!=slist.end();b++)
        cout<<(*b)<<ends;
    cout<<endl;

//emplace //emplace ��������캯��ֱ�ӹ�����󣬶����ǿ���Ԫ��
    //c����Sales_data����
    //c.push_back("9999",3,4);//ERROR
    //c.emplace_back("9999".3,4);��ȷ��emplace�����Sales_data�Ĺ��캯��ֱ������Ԫ��=c.emplace_back(Sales_data("9999",3,4);)

//front back,at �±궼�Ƿ��ص����ã����Կ��Ըı�

//front and back
    auto val=*(slist.begin());
    auto val1=slist.front();
    cout<<val<<ends<<val1<<endl;
    //auto last=slist.end();
    auto val2=*(--slist.end());//forward_list���ܵݼ�������list ����-n
    auto val3=slist.back();//forward_list��֧��back();
    cout<<val2<<ends<<val3<<endl;

//at and���±꣯��ֻ������string vector deque array
    cout<<dq[3]<<ends<<dq.at(3)<<endl;
    dq[3]=9;//�±귵�ص������ã����Ըı�
    cout<<dq[3]<<endl;
    //cout<<dq.at(12)<<endl;//�׳��쳣

//pop_front and pop_back
    cout<<slist.front()<<ends;
    slist.pop_front();
    cout<<slist.front()<<ends;

//erase//ɾ��Ԫ��
    for(auto b=dq.begin();b!=dq.end();b++)
    {
        if(*b==0)
            b=dq.erase(b);
    }
     for(auto b=dq.begin();b!=dq.end();b++)
    {
        cout<<*b<<ends;
    }
    cout<<endl;
*/

//����������stack,queue,priority_queue
    string exp;
    stack<char,vector<char>> c_stk;
    getline(cin,exp);
    for(auto b=exp.begin();b!=exp.end();b++)
    {
        if((*b)=='(')
        {
            //b++;
            for(auto c=b;*c!=')';c++){
                c_stk.push(*c);
                //cout<<c_stk.top()<<ends;
            }
            list<char>tmp;
            while(c_stk.top()!='('){
                  if(c_stk.top()!=' ')
                  {
                      tmp.push_front(c_stk.top());
                  }
                  c_stk.pop();
                    //int tmp=c_stk.top()-48;
                  }
            auto tp=tmp.begin();
            char result=0;
			char prev,next;
			auto b=tmp.begin();
			auto e=tmp.end();
            //�ȴ���*/�ڴ���+-
			while(tp!=tmp.end())
            {

                switch (*tp)
                {
                    case '*':prev=*(--tp)-48;//����ǰ���Ǹ���ֵ
							b=tp;
							++tp;
							next=*(++tp)-48;//ָ����ź����Ǹ���ֵ
							e=tp;
							//--tp;
							result=prev*next;
							
                            tmp.erase(b,++e);
							if(tmp.size()==0){
								tmp.push_back(result+48);
								tp=tmp.begin();
							}
							else{
								tmp.insert(e,result+48);
								tp=--e;
							}
                            break;
                    case '/':prev=*(--tp)-48;
							b=tp;
							++tp;
							next=*(++tp)-48;
							e=tp;
							//--tp;
							result=prev/next;
							
                           tmp.erase(b,++e);
							if(tmp.size()==0){
								tmp.push_back(result+48);
								tp=tmp.begin();
							}
							else{
								tmp.insert(e,result+48);
								tp=--e;
							}
                            break;
                }
                ++tp;
            }
            tp=tmp.begin();
			
            while(tp!=tmp.end())
            {
                switch (*tp)
                {
                    case '+':prev=*(--tp)-48;
							b=tp;
							++tp;
							next=*(++tp)-48;
							e=tp;
							//--tp;
							result=prev+next;
							
                            tmp.erase(b,++e);
							if(tmp.size()==0){
								tmp.push_back(result+48);
								tp=tmp.begin();
							}
							else{
								tmp.insert(e,result+48);
							tp=--e;	
							}
                            break;
                    case '-': prev=*(--tp)-48;
							b=tp;
							++tp;
							next=*(++tp)-48;
							e=tp;
							//--tp;
							result=prev-next;
							
                            tmp.erase(b,++e);
							if(tmp.size()==0){
								tmp.push_back(result+48);
								tp=tmp.begin();
							}
							else{
								tmp.insert(e,result+48);
								tp=--e;
							}
                            break;
                }
                ++tp;
            }
            if(tmp.size()==1){
                result=tmp.front()-48;
                cout<<(int)result;
                c_stk.push(result);
            }
            //c_stk.push(*c);
            //break;
        }
        //break;
    }



    return 0;
}
