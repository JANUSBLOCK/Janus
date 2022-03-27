#include "Mempool.h"

std::set<int> compare(std::set<int>s0, std::set<int>s1)
{
    auto it11 = s0.begin();
    auto it12 = s1.begin();
    std::set<int> j1, j2;
    while (it11 != s0.end() && it12 != s1.end())
    {
        if (*it11 < *it12) {
            j1.insert(*it11++);
        }
        else if (*it12 < *it11) {
            j2.insert(*it12++);
        }
        else {
            it11++;
            it12++;
        }
    }
    while (it12 != s1.end()) {
        j2.insert(*it12++);
    }
    /*for (auto i : j2)
        std::cout << " " << i << ",";
    std::cout << "************************" << std::endl;*/
    return j2;
}

void mempool(unsigned long long start, unsigned long long last, std::mutex &mute, std::set<int> s[], int pool_num, int start_index)
{

    std::default_random_engine gen;
    gen.seed(std::time(NULL)+pool_num);
    std::uniform_real_distribution<double> dist(0.0, 1.0);



    //std::srand(std::time(NULL)+pool_num);
    mute.lock();
    for (unsigned long long i = start; i < last; ++i)
    {
       // s[pool_num-start_index].insert(rand() % (last - start) + start) ;
        s[pool_num - start_index].insert(int(dist(gen) * (last - start) + start));
       // s[pool_num - start_index].insert(int(dist(gen) * (last)));
    }
    mute.unlock();
    // cout<<"Mempool Transactions of Quorum member 1 : ";
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    //for (auto i : s[pool_num-start_index])
        //cout<<"Tx"<<i<<",";
        //std::cout << i << ",";
    //std::cout << "\n--------------------------------------------------------------------------\n";
}

//void mempool_com(const unsigned& start, const unsigned& last, std::set<int>* s[], const int& pool_num, const std::random_device& rand_d)
void mempool_com(const unsigned& start, const unsigned& last, std::set<int> *s[], const int& pool_num, std::random_device& rand_d)
{

    std::mt19937 eng{ rand_d() };
    std::uniform_int_distribution<int> distrib(start, last);

    //std::srand(std::time(NULL) + pool_num);
   // mute.lock();
    for (unsigned i = start; i < last; ++i)
    {
        s[pool_num]->insert( distrib(eng));
    }
    //mute.unlock();
    // cout<<"Mempool Transactions of Quorum member 1 : ";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    //for (auto i : s[pool_num-start_index])
        //cout<<"Tx"<<i<<",";
        //std::cout << i << ",";
    //std::cout << "\n--------------------------------------------------------------------------\n";
}
