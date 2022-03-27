#include "Block.h"
//#include <fstream>
#include "Node.h"
#include "funcs.h"
#include "scale_tests.h"
#include "Mempool.h"

#define NUM_OF_ENTITY_TYPES 4

int main(void)
{



	//void mempool_com(const unsigned& start, const unsigned& last, std::set<int> * s[], const int& pool_num, std::random_device & rand_d)

	unsigned start{ 0 };
	unsigned last{ 100 };
	unsigned quorum_size{ 6 };
	std::set<int>* s1 = new std::set<int>[quorum_size];
	unsigned pool_num{ 0 };
	std::random_device rand_d;


	stest_helper();
//	mempool_com(start, last, s1, pool_num, rand_d);
















	//std::ofstream out("yar.csv");
	//commun_cost(2000, 2000, out);

	//auto duration = stest_1000(5000);
	//stest_1000(1000);

	//stest_2000();
	//stest_3000();
	std::vector<std::vector<Node*>> node_groups;
	std::vector<std::vector<Node*>> q_pools;
	//std::vector<Node*> manu_nodes;
	//make_the_nodes(q_pools, node_groups);


	/*mal_nodes_test(.10, 25000, 1);
	mal_nodes_test(.20, 25000, 1);

	mal_nodes_test(.30, 25000, 1);*/

	mal_nodes_test_run();

	std::string prev_block_str = "Hash of the previous blocks";

	int times_selected[4][20]{ 0 };
	std::cout << "Simulating quorum selection for 5,000 blocks:";
	int dist[40]{ 0 };
	int q_type_count[3]{ 0 };
	int types[4]{ 0 };
	//for (int i = 0; i < 5000; i++)
	//{

	//	prev_block_str = std::to_string(i);
	//	//quorum_selection_test(the_nodes, times_selected,  prev_block_str, i, dist);
	//	q_test(q_pools, prev_block_str, i, q_type_count, dist, types);
	//}
	
	//scale_test();


	//times_select(times_selected, node_groups);
	//std::ofstream out;
	//out.open("output.csv");

	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			out << node_groups[i][j]->get_times_selected() << ",";
		}
		out << "\n";
	}*/


}

