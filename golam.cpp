#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
//#include <bits/stdc++.h>
#include <list>
#include<mutex>
//#include <boost/iterator/counting_iterator.hpp>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
int size_of_tx = 1000000;

set<int> compare(set<int>s0, set<int>s1);
bool comp(int i, int j)
{
    return (i < j);
}

//set<int>s[0];set<int>s[1];set<int>s[2];set<int>s[3];set<int>s[4]R;set<int>s;
set<int> s[6];
std::mutex m1; std::mutex m2; std::mutex m3; std::mutex m4; std::mutex m5; std::mutex m6;
void mempool1(ull start, ull last)
{
    std::srand(std::time(0));
    m1.lock();
    for (ull i = start; i < last; ++i)
    {
        s[0].insert(rand() % last);
    }
    m1.unlock();
    // cout<<"Mempool Transactions of Quorum member 1 : ";
    std::this_thread::sleep_for(chrono::seconds(1));
    for (auto i : s[0])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}

void mempool2(ull start, ull last)
{
    // int j=1;
   // std::srand(std::time(0));
    m2.lock();
    for (ull i = start; i < last; ++i)
    {
        s[1].insert(rand() % last);
    }
    m2.unlock();
    // cout<<"Mempool Transactions of Quorum member 2 : ";
    std::this_thread::sleep_for(chrono::seconds(2));
    for (auto i : s[1])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}

void mempool3(ull start, ull last)
{
    // int j=1;
    srand(time(NULL) % 10000);
    m3.lock();
    for (ull i = start; i < last; ++i)
    {
        s[2].insert(rand() % last);
    }
    m3.unlock();
    // cout<<"Mempool Transactions of Quorum member 3 : ";
    std::this_thread::sleep_for(chrono::seconds(3));
    for (auto i : s[2])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}

void mempool4(ull start, ull last)
{
    // int j=1;
    std::srand(std::time(0) % 1000000);
    m4.lock();
    for (ull i = start; i < last; ++i)
    {
        s[3].insert(rand() % last);
    }
    m4.unlock();
    // cout<<"Mempool Transactions of Quorum member 4 : ";
    std::this_thread::sleep_for(chrono::seconds(4));
    for (auto i : s[3])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}

void mempool5(ull start, ull last)
{
    // int j=1;
    std::srand(std::time(0) % 10000);
    m5.lock();
    for (ull i = start; i < last; ++i)
    {
        s[4].insert(rand() % last);
    }
    //  cout<<"Mempool Transactions of Quorum member 5 : ";
    std::this_thread::sleep_for(chrono::seconds(5));
    m5.unlock();
    for (auto i : s[4])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}

void mempool6(ull start, ull last)
{
    std::srand(std::time(0) % 100000);
    m6.lock();
    for (ull i = start; i < last; ++i)
    {
        s[5].insert(rand() % last);
    }
    // cout<<"Mempool Transactions of Quorum member 6 : ";
    std::this_thread::sleep_for(chrono::seconds(6));
    m6.unlock();
    for (auto i : s[5])
        //cout<<"Tx"<<i<<",";
        cout << i << ",";
    cout << "\n--------------------------------------------------------------------------\n";
}



//int main()
//{
//    std::srand(std::time(0));
//    // srand (time(NULL));
//
//    cout << "PoH!\n" << endl;
//    ull start = 0, last = 20;
//    auto startTime = high_resolution_clock::now();
//    //mempool(1,100);
//
//    std::thread t1(mempool1, start, last);
//    std::thread t2(mempool2, start, last);
//    std::thread t3(mempool3, start, last);
//    std::thread t4(mempool4, start, last);
//    std::thread t5(mempool5, start, last);
//    std::thread t6(mempool6, start, last);
//
//    if (t1.joinable())
//        t1.join();
//    if (t2.joinable())
//        t2.join();
//    if (t3.joinable())
//        t3.join();
//    if (t4.joinable())
//        t4.join();
//    if (t5.joinable())
//        t5.join();
//    if (t6.joinable())
//        t6.join();
//    //t3.join();
//
//
//
//    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stopTime - startTime);
//    cout << "\nsec: " << duration.count() / 1000000 << endl;
//
//    set<int>j1; set<int>j2; set<int>j3; set<int>j4; set<int>j5; set<int>j6;
//
//
//    set<int> newS[6];
//    for (int i = 0; i < 6; i++)
//        newS[i] = s[i];
//    for (int id = 0; id < 6; id++) {
//        set<int>j[6];
//        for (int index = 1; index < 6; index++) {
//
//            j[index] = compare(newS[id], s[(index + id) % 6]);
//            for (auto missing : j[index]) {
//                newS[id].insert(missing);
//            }
//        }
//    }
//    for (int id = 0; id < 6; id++) {
//        for (auto i : newS[id])
//            cout << " " << i << ",";
//        cout << "************************" << endl;
//    }
//
//
//    //  //Master Block
//    for (int i = 0; i < 6; i++) {
//        for (int k = 0; k < 6; k++) {
//            if (newS[i] == newS[k]) {
//                printf("sets: true\n");
//            }
//            else
//            {
//                printf("sets: false\n");
//                std::set<int>::iterator it2 = newS[k].begin();
//                for (std::set<int>::iterator it1 = newS[i].begin(); it1 != newS[i].end(); it1++) {
//                    printf("\ns[%d]: %d  s[%d]: %d", k, *it1, i, *it2);
//                    it2++;
//                }
//            }
//        }
//    }
//
//
//
//    return 0;
//}
//
//set<int> compare(set<int>s0, set<int>s1)
//{
//    auto it11 = s0.begin();
//    auto it12 = s1.begin();
//    set<int> j1, j2;
//    while (it11 != s0.end() && it12 != s1.end())
//    {
//        if (*it11 < *it12) {
//            j1.insert(*it11++);
//        }
//        else if (*it12 < *it11) {
//            j2.insert(*it12++);
//        }
//        else {
//            it11++;
//            it12++;
//        }
//    }
//    while (it12 != s1.end()) {
//        j2.insert(*it12++);
//    }
//    for (auto i : j2)
//        cout << " " << i << ",";
//    cout << "************************" << endl;
//    return j2;
//}