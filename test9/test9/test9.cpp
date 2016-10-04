// test9.cpp : 定义控制台应用程序的入口点。
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
    auto ct=it2-it1;//vector<int>::difference_type;两个迭代器之间的距离
    cout<<ct<<ends;

    it2=it1+5;//it2移动到第五个元素位置

    vector<int> v2(it1,it2);//将it1到it2之间的数据初始化v2；
    cout<<v2.size()<<ends;


//forward_list


    vector<const char *> art={"a","bb","aaa"};

    forward_list<string> art1(art.begin(),art.end());//可以将一个const char * 类型转换成string类型
    auto art1_itb=art1.cbegin();
    auto art1_ite=art1.cend();
    for(;art1_itb!=art1_ite;art1_itb++)
        cout<<(*art1_itb)<<ends;//forward_list迭代器不支持递减操作,但支持递增,且不支持size,不支持push_back
    //cout << "Hello world!" << endl;
    auto prev=art1.before_begin();
    auto curr=art1.begin();//prev在curr之前，删除操作是删除指向的下一个元素
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

    array<int,10> sz={10,0};//array 必须指定大小，且不能被（）初始化
    array<int,10> sz1={0};//array 有赋值操作，且大小必须相同，但数组没有
    sz=sz1;
    sz1={0};//

//assign 操作

    list<string>name;
    vector<char *> old;
    //name=old;//error
    name.assign(old.cbegin(),old.cend());//正确
    name.assign(10,"hi");

//swap 操作

    vector<string> s1(10);
    vector<string> s2(24);
    swap(s1,s2);//除array之外，swap不对任何元素进行复制，删除和插入可以在常数时间内完成，他改变的是内部的数据结构
    //所以，除string 类型外其引用指针等操作还是指向原来位置，例如，iter指向s1[3],swap之后指向s2[3]

//push_front
    list<int> ilist;
    for(size_t ix=0;ix!=4;ix++)
        ilist.push_front(ix);//从头插入，结果为3,2,1,0

    for(auto b=ilist.cbegin();b!=ilist.cend();b++)
        cout<<(*b)<<ends;
    cout<<endl;


//deque
    deque<int>dq;//deque前后都可以插入
    for (size_t ix=0;ix!=4;ix++)
        dq.push_back(ix);
     for(size_t ix=0;ix!=4;ix++)
        dq.push_front(ix);
    for(auto b=dq.cbegin();b!=dq.cend();b++)
        cout<<(*b)<<ends;
    cout<<endl;


//insert
    list<string> slist{"hi"};
    slist.insert(slist.begin(),10,"ha");//在begin 之前插入10个“ha”
    slist.insert(slist.begin(),{"hello","world"});
    for(auto b=slist.begin();b!=slist.end();b++)
        cout<<(*b)<<ends;
    cout<<endl;

//emplace //emplace 会操作构造函数直接构造对象，而不是拷贝元素
    //c保存Sales_data数据
    //c.push_back("9999",3,4);//ERROR
    //c.emplace_back("9999".3,4);正确，emplace会调用Sales_data的构造函数直接生成元素=c.emplace_back(Sales_data("9999",3,4);)

//front back,at 下标都是返回的引用，所以可以改变

//front and back
    auto val=*(slist.begin());
    auto val1=slist.front();
    cout<<val<<ends<<val1<<endl;
    //auto last=slist.end();
    auto val2=*(--slist.end());//forward_list不能递减，而且list 不能-n
    auto val3=slist.back();//forward_list不支持back();
    cout<<val2<<ends<<val3<<endl;

//at and　下标／／只适用于string vector deque array
    cout<<dq[3]<<ends<<dq.at(3)<<endl;
    dq[3]=9;//下标返回的是引用，可以改变
    cout<<dq[3]<<endl;
    //cout<<dq.at(12)<<endl;//抛出异常

//pop_front and pop_back
    cout<<slist.front()<<ends;
    slist.pop_front();
    cout<<slist.front()<<ends;

//erase//删除元素
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

//容器适配器stack,queue,priority_queue
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
            //先处理*/在处理+-
			while(tp!=tmp.end())
            {

                switch (*tp)
                {
                    case '*':prev=*(--tp)-48;//符号前面那个数值
							b=tp;
							++tp;
							next=*(++tp)-48;//指向符号后面那个数值
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
