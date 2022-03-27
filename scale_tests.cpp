#include "scale_tests.h"
#include "Node.h"
#include "funcs.h"
#include "Mempool.h"


//void commun_cost(const int& network_size, const int& num_trans, std::ofstream& out)
//{
//	const int quorum_size = std::ceil(std::log2((network_size / 2)));
//	unsigned fst_upper = num_trans / 3;
//	unsigned snd_upper = fst_upper * 2;
//
//
//	std::random_device rand_d; 
//	std::vector<std::thread*> q1;
//	std::vector<std::thread*> q2;
//	std::vector<std::thread*> q3;
//
//	//std::set<int> s[8];
//	std::set<int>* s1 = new std::set<int>[quorum_size];
//	std::set<int>* s2 = new std::set<int>[quorum_size];
//	std::set<int>* s3 = new std::set<int>[quorum_size];
//	
//	//throwaway(s1);
//	int i = 0;
//	mempool_com(0, fst_upper, &s1, i, rand_d);
//	//void mempool_com(const unsigned& start, const unsigned& last, std::set<int> *s[], const int& pool_num, const std::random_device & rand_d);
//	for (int i = 0; i < quorum_size; i++)
//	{
//		q1.push_back(new std::thread(mempool_com, 0, fst_upper, &(s1), i, rand_d));
//		q2.push_back(new std::thread(mempool_com, fst_upper, snd_upper, &(s2), i, rand_d));
//		q3.push_back(new std::thread(mempool_com, snd_upper, num_trans, &(s3), i, rand_d));
//	}
//
//	for (int i = 0; i < quorum_size; i++)
//	{
//		if (q1[i]->joinable())
//		{
//			q1[i]->join();
//		}
//		if (q2[i]->joinable())
//		{
//			q2[i]->join();
//		}
//		if (q3[i]->joinable())
//		{
//			q3[i]->join();
//		}
//	}
//
//
//
//
//	delete[]s1;
//	delete[]s2;
//	delete[]s3;
//
//
//	std::cout << "Done with com test";
//}




void commun_cost_helper()
{
	
	/*std::string first{ "first" };
	commun_cost(2000, 2000, first);*/


}


std::chrono::microseconds eight_memb(int num_trans)
{
	int fstupper = num_trans / 3;
	int sndupper = fstupper * 2;
	//std::cout << "Made the nodes stest 2000\n";

	std::mutex m1; std::mutex m2; std::mutex m3; std::mutex m4; std::mutex m5; std::mutex m6; std::mutex m7;
	std::mutex m8; std::mutex m9;

	std::set<int> s[8];
	std::set<int> s2[8];
	std::set<int> s3[8];
	auto startTime = std::chrono::high_resolution_clock::now();
	//std::thread t21(mempool, sndupper, num_trans, std::ref(m21), s3, 20, 14);
	std::thread t1(mempool, 0, fstupper, std::ref(m1), s, 0, 0);
	std::thread t2(mempool, 0, fstupper, std::ref(m2), s, 1, 0);
	std::thread t3(mempool, 0, fstupper, std::ref(m3), s, 2, 0);
	std::thread t4(mempool, 0, fstupper, std::ref(m4), s, 3, 0);
	std::thread t5(mempool, 0, fstupper, std::ref(m5), s, 4, 0);
	std::thread t6(mempool, 0, fstupper, std::ref(m6), s, 5, 0);
	std::thread t7(mempool, 0, fstupper, std::ref(m7), s, 6, 0);
	std::thread t8(mempool, 0, fstupper, std::ref(m8), s, 7, 0);
	
	std::mutex m10; std::mutex m11; std::mutex m12; std::mutex m13; std::mutex m14; std::mutex m15; std::mutex m16; std::mutex m17; std::mutex m18;
	std::thread t9(mempool, fstupper, sndupper, std::ref(m9), s2, 8, 8);
	std::thread t10(mempool, fstupper, sndupper, std::ref(m10), s2, 9, 8);
	std::thread t11(mempool, fstupper, sndupper, std::ref(m11), s2, 10, 8);
	std::thread t12(mempool, fstupper, sndupper, std::ref(m12), s2, 11, 8);
	std::thread t13(mempool, fstupper, sndupper, std::ref(m13), s2, 12, 8);
	std::thread t14(mempool, fstupper, sndupper, std::ref(m14), s2, 13, 8);
	std::thread t15(mempool, fstupper, sndupper, std::ref(m15), s2, 14, 8);
	std::thread t16(mempool, fstupper, sndupper, std::ref(m16), s2, 15, 8);
	
	
	std::mutex m19; std::mutex m20; std::mutex m21; std::mutex m22; std::mutex m23; std::mutex m24;
	std::thread t17(mempool, sndupper, num_trans, std::ref(m17), s3, 16, 16);
	std::thread t18(mempool, sndupper, num_trans, std::ref(m18), s3, 17, 16);
	std::thread t19(mempool, sndupper, num_trans, std::ref(m19), s3, 18, 16);
	std::thread t20(mempool, sndupper, num_trans, std::ref(m20), s3, 19, 16);
	std::thread t21(mempool, sndupper, num_trans, std::ref(m21), s3, 20, 16);
	std::thread t22(mempool, sndupper, num_trans, std::ref(m22), s3, 21, 16);
	std::thread t23(mempool, sndupper, num_trans, std::ref(m23), s3, 22, 16);
	std::thread t24(mempool, sndupper, num_trans, std::ref(m24), s3, 23, 16);
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
	if (t5.joinable())
		t5.join();
	if (t6.joinable())
		t6.join();
	if (t7.joinable())
		t7.join();
	if (t8.joinable())
		t8.join();
	if (t9.joinable())
		t9.join();
	if (t10.joinable())
		t10.join();
	if (t11.joinable())
		t11.join();
	if (t12.joinable())
		t12.join();
	if (t13.joinable())
		t13.join();
	if (t14.joinable())
		t14.join();
	if (t15.joinable())
		t15.join();
	if (t16.joinable())
		t16.join();
	if (t17.joinable())
		t17.join();
	if (t18.joinable())
		t18.join();
	if (t19.joinable())
		t19.join();
	if (t20.joinable())
		t20.join();
	if (t21.joinable())
		t21.join();
	if (t22.joinable())
		t22.join();
	if (t23.joinable())
		t23.join();
	if (t24.joinable())
		t24.join();

	double missing_total = 0.0;
	std::set<int> newS[8];
	for (int i = 0; i < 8; i++)
		newS[i] = s[i];
	for (int id = 0; id < 8; id++) {
		std::set<int>j[8];
		for (int index = 1; index < 8; index++) {

			j[index] = compare(newS[id], s[(index + id) % 8]);
			for (auto missing : j[index]) {
				newS[id].insert(missing);
				missing_total++;
			}
		}
	}
	//std::cout << "\nline 124";
	std::set<int> newS1[8];
	for (int i = 0; i < 8; i++)
		newS1[i] = s2[i];
	for (int id = 0; id < 8; id++) {
		std::set<int>j[8];
		for (int index = 1; index < 8; index++) {

			j[index] = compare(newS1[id], s2[(index + id) % 8]);
			for (auto missing : j[index]) {
				newS1[id].insert(missing);
				missing_total++;
			}
		}
	}
	//std::cout << "\nline 137\n";
	std::set<int> newS2[8];
	for (int i = 0; i < 8; i++)
		newS2[i] = s3[i];
	for (int id = 0; id < 8; id++) {
		std::set<int>j[8];
		for (int index = 1; index < 8; index++) {

			j[index] = compare(newS2[id], s3[(index + id) % 8]);
			for (auto missing : j[index]) {
				newS2[id].insert(missing);
				missing_total++;
			}
		}
	}


	missing_total /= 24.0;
	double total_C_C = (32 * (8 * 7) * (num_trans / 3.0) + missing_total * 512 * 8 + 32 * (8 * 7) + 256 * (8 * 7));
	
	total_C_C /= 1024;
	total_C_C /= 1024;

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	//std::cout << "\nsec: " << duration.count() / 1000000 << std::endl;

	//std::cout << "done test 1000";
	return duration;



}



void stest(int num_nodes, int num_trans)
{

}


std::chrono::microseconds sev_memb(unsigned long num_trans)
{


	/*std::vector<std::vector<std::shared_ptr<Node>>> node_groups;
	std::vector<std::vector<std::shared_ptr<Node>>> q_pools;
	std::vector<std::shared_ptr<Quorum>> the_quorums;*/
	//make_the_nodes_safe(q_pools, node_groups, 250);
	//std::string prev_block_hash = "hash";
	//form_quorums(the_quorums, q_pools, prev_block_hash);
	//quorums:3 size: 7
	int fstupper = num_trans / 3;
	int sndupper = fstupper * 2;


	//std::cout << "Made the nodes stest 1000\n";
	//std::srand(std::time(0));
	    // srand (time(NULL));
	
	   // std::cout << "PoH!\n" << std::endl;
		unsigned long long int start = 0; unsigned long long last = 20;
	    auto startTime = std::chrono::high_resolution_clock::now();
	    //mempool(1,100);
		std::mutex m1; std::mutex m2; std::mutex m3; std::mutex m4; std::mutex m5; std::mutex m6; std::mutex m7;
		std::set<int> s[7];
		std::set<int> s2[7];
		std::set<int> s3[7];
	    std::thread t1(mempool,0,fstupper, std::ref(m1), s, 0, 0);
	    std::thread t2(mempool,0,fstupper, std::ref(m2), s, 1, 0);
	    std::thread t3(mempool,0,fstupper, std::ref(m3), s, 2, 0);
	    std::thread t4(mempool,0,fstupper, std::ref(m4), s, 3, 0);
	    std::thread t5(mempool,0,fstupper, std::ref(m5), s, 4, 0);
	    std::thread t6(mempool,0,fstupper, std::ref(m6), s, 5, 0);
		std::thread t7(mempool,0,fstupper, std::ref(m7), s, 6, 0);
		int start_2 = 7;
		std::mutex m8; std::mutex m9; std::mutex m10; std::mutex m11; std::mutex m12; std::mutex m13; std::mutex m14;
		 std::thread t8(mempool, fstupper, sndupper, std::ref(m8), s2, 7, start_2);    //std::thread t1(mempool, 0, 1000, std::ref(m1), s, 0);
		 std::thread t9(mempool, fstupper, sndupper, std::ref(m9), s2, 8, start_2);
		std::thread t10(mempool, fstupper, sndupper, std::ref(m10), s2, 9, start_2);
		std::thread t11(mempool, fstupper, sndupper, std::ref(m11), s2, 10, start_2);
		std::thread t12(mempool, fstupper, sndupper, std::ref(m12), s2, 11, start_2);
		std::thread t13(mempool, fstupper, sndupper, std::ref(m13), s2, 12, start_2);
		std::thread t14(mempool, fstupper, sndupper, std::ref(m14), s2, 13, start_2);
		std::mutex m15; std::mutex m16; std::mutex m17; std::mutex m18; std::mutex m19; std::mutex m20; std::mutex m21;
		std::thread t15(mempool, sndupper, num_trans, std::ref(m15), s3, 14, 14);
		std::thread t16(mempool, sndupper, num_trans, std::ref(m16), s3, 15, 14);
		std::thread t17(mempool, sndupper, num_trans, std::ref(m17), s3, 16, 14);
		std::thread t18(mempool, sndupper, num_trans, std::ref(m18), s3, 17, 14);
		std::thread t19(mempool, sndupper, num_trans, std::ref(m19), s3, 18, 14);
		std::thread t20(mempool, sndupper, num_trans, std::ref(m20), s3, 19, 14);
		std::thread t21(mempool, sndupper, num_trans, std::ref(m21), s3, 20, 14);

	    if (t1.joinable())
	        t1.join();
	    if (t2.joinable())
	        t2.join();
	    if (t3.joinable())
	        t3.join();
	    if (t4.joinable())
	        t4.join();
	    if (t5.joinable())
	        t5.join();
	    if (t6.joinable())
	        t6.join();
		if (t7.joinable())
			t7.join();

		if (t8.joinable())
			t8.join();
		if (t9.joinable())
			t9.join();
		if (t10.joinable())
			t10.join();
		if (t11.joinable())
			t11.join();
		if (t12.joinable())
			t12.join();
		if (t13.joinable())
			t13.join();
		
		if (t14.joinable())
			t14.join();
		if (t15.joinable())
			t15.join();
		if (t16.joinable())
			t16.join();
		if (t17.joinable())
			t17.join();
		if (t18.joinable())
			t18.join();
		if (t19.joinable())
			t19.join();
		if (t20.joinable())
			t20.join();
		if (t21.joinable())
			t21.join();
		
		

		//std::set<int>j1; std::set<int>j2; std::set<int>j3; std::set<int>j4; std::set<int>j5; std::set<int>j6;
		//std::cout << "line 109";
		unsigned long missing_total = 0;
		int missing_count[7]{ 0 };
		   std:: set<int> newS[7];
		    for (int i = 0; i < 7; i++)
		        newS[i] = s[i];
		    for (int id = 0; id < 7; id++) {
		        std::set<int>j[7];
		        for (int index = 1; index < 7; index++) {
		
		            j[index] = compare(newS[id], s[(index + id) % 7]);
		            for (auto missing : j[index]) {
		                newS[id].insert(missing);
						missing_count[id]++;
						missing_total++;
		            }
		        }
		    }
			//std::cout << "\nline 124";
			int missing_2[7]{ 0 };
			std::set<int> newS1[7];
			for (int i = 0; i < 7; i++)
				newS1[i] = s2[i];
			for (int id = 0; id < 7; id++) {
				std::set<int>j[7];
				for (int index = 1; index < 7; index++) {

					j[index] = compare(newS1[id], s2[(index + id) % 7]);
					for (auto missing : j[index]) {
						newS1[id].insert(missing);
						missing_2[id]++;
						missing_total++;
					}
				}
			}
			//std::cout << "\nline 137\n";
			int missing_3[7]{ 0 };
			std::set<int> newS2[7];
			for (int i = 0; i < 7; i++)
				newS2[i] = s3[i];
			for (int id = 0; id < 7; id++) {
				std::set<int>j[7];
				for (int index = 1; index < 7; index++) {

					j[index] = compare(newS2[id], s3[(index + id) % 7]);
					for (auto missing : j[index]) {
						newS2[id].insert(missing);
						missing_3[id]++;
						missing_total++;
					}
				}
			}

			auto stopTime = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
			//std::cout << "\nsec: " << duration.count() / 1000000 << std::endl;

		//std::cout << "done test 1000";
		//double total_C_C = 256 * (q_size - 1) + 32 * (q_size - 1) + 256 * (q_size - 1);

			std::cout << "Missing total: " << missing_total;
			missing_total /= 21;
		//double total_C_C = 3 * (256 * (7 - 1) + 32 * (7 - 1) + 256 * (7 - 1)) + missing_total ;
		double total_C_C = (    32*( 7*6 )*(num_trans/3.0)  +                  missing_total * 512 * 7           +   32 * (7*6)                + 256 * (7 * 6)                      ) ; // 7 person quorum
		                      // everyone sends all trans headers to every other   //Reqst miss tx                             //exchange DB hash of all 
		// 36% transactions missing.
		total_C_C /= 1024;
		total_C_C /= 1024;
		return duration;
}



std::chrono::microseconds nine_memb(int num_trans)
{
	/*std::vector<std::vector<std::shared_ptr<Node>>> node_groups;
	std::vector<std::vector<std::shared_ptr<Node>>> q_pools;
	std::vector<std::shared_ptr<Quorum>> the_quorums; 
	make_the_nodes_safe(q_pools, node_groups, 500);
	std::string prev_block_hash = "hash";

	form_quorums(the_quorums, q_pools, prev_block_hash);*/
	//num:3 size: 9
	int fstupper = num_trans / 3;
	int sndupper = fstupper * 2;
	//std::cout << "Made the nodes stest 2000\n";

	std::mutex m1; std::mutex m2; std::mutex m3; std::mutex m4; std::mutex m5; std::mutex m6; std::mutex m7;
	std::mutex m8; std::mutex m9;

	std::set<int> s[9];
	std::set<int> s2[9];
	std::set<int> s3[9];
	auto startTime = std::chrono::high_resolution_clock::now();
	//std::thread t21(mempool, sndupper, num_trans, std::ref(m21), s3, 20, 14);
	std::thread t1(mempool, 0,fstupper, std::ref(m1), s, 0, 0 );
	std::thread t2(mempool, 0,fstupper, std::ref(m2), s, 1, 0 );
	std::thread t3(mempool, 0,fstupper, std::ref(m3), s, 2, 0 );
	std::thread t4(mempool, 0,fstupper, std::ref(m4), s, 3, 0 );
	std::thread t5(mempool, 0,fstupper, std::ref(m5), s, 4, 0 );
	std::thread t6(mempool, 0,fstupper, std::ref(m6), s, 5, 0 );
	std::thread t7(mempool, 0,fstupper, std::ref(m7), s, 6, 0 );
	std::thread t8(mempool, 0,fstupper, std::ref(m8), s, 7, 0 );
	std::thread t9(mempool, 0,fstupper, std::ref(m9), s, 8, 0 );
	std::mutex m10; std::mutex m11; std::mutex m12; std::mutex m13; std::mutex m14; std::mutex m15; std::mutex m16; std::mutex m17; std::mutex m18;
	std::thread t10(mempool, fstupper, sndupper, std::ref(m10), s2, 9, 9 );
	std::thread t11(mempool, fstupper, sndupper, std::ref(m11), s2, 10, 9);
	std::thread t12(mempool, fstupper, sndupper, std::ref(m12), s2, 11, 9);
	std::thread t13(mempool, fstupper, sndupper, std::ref(m13), s2, 12, 9);
	std::thread t14(mempool, fstupper, sndupper, std::ref(m14), s2, 13, 9); 
	std::thread t15(mempool, fstupper, sndupper, std::ref(m15), s2, 14, 9);
	std::thread t16(mempool, fstupper, sndupper, std::ref(m16), s2, 15, 9);
	std::thread t17(mempool, fstupper, sndupper, std::ref(m17), s2, 16, 9);
	std::thread t18(mempool, fstupper, sndupper, std::ref(m18), s2, 17, 9);
	std::mutex m19; std::mutex m20; std::mutex m21; std::mutex m22; std::mutex m23; std::mutex m24; std::mutex m25; std::mutex m26; std::mutex m27;
	std::thread t19(mempool, sndupper, num_trans, std::ref(m19), s3, 18, 18);
	std::thread t20(mempool, sndupper, num_trans, std::ref(m20), s3, 19, 18);
	std::thread t21(mempool, sndupper, num_trans, std::ref(m21), s3, 20, 18);
	std::thread t22(mempool, sndupper, num_trans, std::ref(m22), s3, 21, 18);
	std::thread t23(mempool, sndupper, num_trans, std::ref(m23), s3, 22, 18);
	std::thread t24(mempool, sndupper, num_trans, std::ref(m24), s3, 23, 18);
	std::thread t25(mempool, sndupper, num_trans, std::ref(m25), s3, 24, 18);
	std::thread t26(mempool, sndupper, num_trans, std::ref(m26), s3, 25, 18);
	std::thread t27(mempool, sndupper, num_trans, std::ref(m27), s3, 26, 18);
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
	if (t5.joinable())
		t5.join();
	if (t6.joinable())
		t6.join();
	if (t7.joinable())
		t7.join();
	if (t8.joinable())
		t8.join();
	if (t9.joinable())
		t9.join();
	if (t10.joinable())
		t10.join();
	if (t11.joinable())
		t11.join();
	if (t12.joinable())
		t12.join();
	if (t13.joinable())
		t13.join();
	if (t14.joinable())
		t14.join();
	if (t15.joinable())
		t15.join();
	if (t16.joinable())
		t16.join();
	if (t17.joinable())
		t17.join();
	if (t18.joinable())
		t18.join();
	if (t19.joinable())
		t19.join();
	if (t20.joinable())
		t20.join();
	if (t21.joinable())
		t21.join();
	if (t22.joinable())
		t22.join();
	if (t23.joinable())
		t23.join();
	if (t24.joinable())
		t24.join();
	if (t25.joinable())
		t25.join();
	if (t26.joinable())
		t26.join();
	if (t27.joinable())
		t27.join();


	double missing_total = 0.0;
	std::set<int> newS[9];
	for (int i = 0; i < 9; i++)
		newS[i] = s[i];
	for (int id = 0; id < 9; id++) {
		std::set<int>j[9];
		for (int index = 1; index < 9; index++) {

			j[index] = compare(newS[id], s[(index + id) % 9]);
			for (auto missing : j[index]) {
				newS[id].insert(missing);
				missing_total++;
			}
		}
	}
	//std::cout << "\nline 124";
	std::set<int> newS1[9];
	for (int i = 0; i < 9; i++)
		newS1[i] = s2[i];
	for (int id = 0; id < 9; id++) {
		std::set<int>j[9];
		for (int index = 1; index < 9; index++) {

			j[index] = compare(newS1[id], s2[(index + id) % 9]);
			for (auto missing : j[index]) {
				newS1[id].insert(missing);
				missing_total++;
			}
		}
	}
	//std::cout << "\nline 137\n";
	std::set<int> newS2[9];
	for (int i = 0; i < 9; i++)
		newS2[i] = s3[i];
	for (int id = 0; id < 9; id++) {
		std::set<int>j[9];
		for (int index = 1; index < 9; index++) {

			j[index] = compare(newS2[id], s3[(index + id) % 9]);
			for (auto missing : j[index]) {
				newS2[id].insert(missing);
				missing_total++;
			}
		}
	}

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	//std::cout << "\nsec: " << duration.count() / 1000000 << std::endl;
	missing_total /= 27;

	double total_C_C = (32 * (9 * 8) * (num_trans / 3.0) + missing_total * 512 * 9 + 32 * (9 * 8) + 256 * (9 * 8));
	//std::cout << "done test 1000";
	total_C_C /= 1024;
	total_C_C /= 1024;
	return duration;


}

void stest_3000()
{
	std::vector<std::vector<std::shared_ptr<Node>>> node_groups;
	std::vector<std::vector<std::shared_ptr<Node>>> q_pools;
	std::vector<std::shared_ptr<Quorum>> the_quorums;
	make_the_nodes_safe(q_pools, node_groups, 750);
	std::string prev_block_hash = "hash";

	//form_quorums(the_quorums, q_pools, prev_block_hash);                //////////////////////////////////////////// Uncomment later 
	//num:3 size:9 
	std::cout << "Made the nodes stest 3000\n";

	std::mutex m1; std::mutex m2; std::mutex m3; std::mutex m4; std::mutex m5; std::mutex m6; std::mutex m7;
	std::mutex m8; std::mutex m9;
	std::set<int> s[7];
	/*std::thread t1(mempool, 0, 1000, std::ref(m1), s, 0);
	std::thread t2(mempool, 0, 1000, std::ref(m2), s, 1);
	std::thread t3(mempool, 0, 1000, std::ref(m3), s, 2);
	std::thread t4(mempool, 0, 1000, std::ref(m4), s, 3);
	std::thread t5(mempool, 0, 1000, std::ref(m5), s, 4);
	std::thread t6(mempool, 0, 1000, std::ref(m6), s, 5);
	std::thread t7(mempool, 0, 1000, std::ref(m7), s, 6);
	std::thread t8(mempool, 0, 1000, std::ref(m8), s, 7);
	std::thread t9(mempool, 0, 1000, std::ref(m9), s, 8);
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
	if (t5.joinable())
		t5.join();
	if (t6.joinable())
		t6.join();
	if (t7.joinable())
		t7.join();
	if (t8.joinable())
		t8.join();
	if (t9.joinable())
		t9.join();*/





}

void stest_helper() /// update line 619, 614
{
	std::chrono::microseconds thou_nodes[4]{ std::chrono::microseconds(0) };
	std::chrono::microseconds eight_membs[4]{ std::chrono::microseconds(0) };
	std::chrono::microseconds nine_membs2[4]{ std::chrono::microseconds(0) };
	std::chrono::microseconds nine_membs3[4]{ std::chrono::microseconds(0) };
	std::chrono::microseconds nine_membs4[4]{ std::chrono::microseconds(0) };
	int num_trans = 21000;
	// to do 2, 4, 8, 16
	for (int j = 0; j < 100; j++)
	{
		std::cout << "iter: " << j << std::endl;
		//num_trans = 2000;

		for (int i = 0; i < 4; i++)
		{

			std::cout << i << std::endl;
			//thou_nodes[i] += sev_memb(num_trans);
			//eight_membs[i] += eight_memb(num_trans);
			nine_membs2[i] += nine_memb(num_trans);
			/*			nine_membs3[i] += nine_memb(num_trans);
			nine_membs4[i] += nine_memb(num_trans);*/
			//num_trans *= 2;
		}
	}


	/*num_trans = 2000;
	for (int i = 0; i < 4; i++)
	{
		nine_membs2[i] = stest_2000(num_trans);
		nine_membs3[i] = stest_2000(num_trans);
		nine_membs4[i] = stest_2000(num_trans);
		num_trans += 2000;
	}*/


	std::ofstream out;
	out.open("scal_output2.csv");
	out << "1000 nodes\n";
	for (int i = 0; i < 4; i++)
	{
		out << thou_nodes[i].count() / 100 << ",";
	}
	out << "\n2000 nodes\n";
	for (int i = 0; i < 4; i++)
	{
		out << eight_membs[i].count() / 100 << ",";
	}
	out << "3000 nodes\n";
	for (int i = 0; i < 4; i++)
	{
		out << nine_membs2[i].count() / 100 << ",";
	}
	out << "\n4000 nodes\n";
	for (int i = 0; i < 4; i++)
	{
		out << nine_membs3[i].count() / 100 << ",";
	}
	out << "\n5000 nodes\n";
	for (int i = 0; i < 4; i++)
	{
		out << nine_membs4[i].count() / 100 << ",";
	}

}