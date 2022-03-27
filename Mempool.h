#ifndef MEMPOOL_H
#define MEMPOOL_H
#include "includes.h"


std::set<int> compare(std::set<int>s0, std::set<int>s1);

//void mempool(int start, unsigned long long last, std::mutex mute, std::set<int> s[], int pool_num);

void mempool(unsigned long long start, unsigned long long last, std::mutex &mute, std::set<int> s[], int, int );

void mempool_com(const unsigned& start, const unsigned& last, std::set<int> *s[], const int& pool_num, const std::random_device& rand_d);

//void throwaway(std::set<int> s[])
//{
//	std::cout << "In throwaway func";
//}

//#pragma once
//class Mempool
//{
//private:
//	int first;
//	int last;
//
//
//public:
//	std::mutex mute;
//
//	Mempool(const int &first, const int &last)
//		:first(first), last(last)
//	{
//	}
//
//};
//
#endif // !MEMPOOL_H