#include "funcs.h"
#include "sha256.h"



void form_quorums(std::vector<std::shared_ptr<Quorum>>& the_quorums, std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::string& prev_block_hash, int &mal_quorums)
{
	static int start_index = 0;
	int cur_index = start_index;
	int count{ 0 };
	if (start_index > q_pools.size())
	{
		start_index = 0;
	}
	const int num_of_quorums = q_pools.size();
	std::string cur_hash = sha256(prev_block_hash);
	unsigned long long hash_int_val{ 0 };
	unsigned pool_size{ 0 };
	

	int cur_selected{ 0 };

	int quorum_size{ 0 };
	bool duplicate{ false };

	while (count < num_of_quorums)
	{
		pool_size = q_pools[cur_index].size();
		quorum_size = std::ceil(std::log(pool_size));
		/*if (quorum_size % 2 == 0)  //// Decided against restricting odd quorum sizes 7/28/21 - Connor 
		{
			quorum_size += 1;
		}*/
		auto cur_quorum = std::make_shared<Quorum>(quorum_size);
		for (int j = 0; j < quorum_size; j++)
		{
			cur_hash = cur_hash + std::to_string(j);
			cur_hash = sha256(cur_hash);
			cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			hash_int_val = (std::stoull(cur_hash, nullptr, 16));
			cur_selected = hash_int_val % pool_size;
			duplicate = cur_quorum->add_member(q_pools[cur_index][cur_selected]);
			if (duplicate)
			{
				duplicate = false;
				j = j - 1;
				continue;
			}
		}
		the_quorums.push_back(cur_quorum);
		count++;
		cur_index++;
		if (cur_index == num_of_quorums)
		{
			cur_index = 0;
		}

	}

	for (int i = 0; i < num_of_quorums; i++)
	{
		mal_quorums += the_quorums[i]->get_mal_q();
	}

	for (int i = 0; i < num_of_quorums; i++)
	{
		the_quorums[i]->reset_membership();
	}

	start_index += 1;
	if (start_index == num_of_quorums)
	{
		start_index = 0;
	}
	

}


void increment_entity_ids(std::vector<std::vector<Node* >> &all_nodes)
{
	std::vector<std::vector<Node*>>::iterator begin = all_nodes.begin();
	std::vector<std::vector<Node*>>::iterator end = all_nodes.end();
	int num_nodes = 0;
	for (auto i = begin; i != end; i++)
	{
		num_nodes += i->size();

	}
	//std::cout << "Number of nodes " << num_nodes;
	for (auto i = begin; i != end; i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			(*j)->increment_stake_id(num_nodes);  
		}


	}
	

}


void make_the_nodes(std::vector<std::vector<Node*>>& q_pools, std::vector<std::vector<Node*>>& node_groups, int num_per)
{


	//std::vector<std::vector<Node*>> node_groups;
	std::vector<Node* > all_nodes;
	//std::vector<Node*> manu_nodes;
	
	/*for (int i = 60; i < 80; i++)
	{
		Node* cur_node = new Node("Manufacturer", i, 4);
		manu_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);
	}
	node_groups.push_back(manu_nodes);



	std::vector<Node*> whare_nodes;
	for (int i = 40; i < 60; i++)
	{
		Node* cur_node = new Node("Wharehouse", i, 3);
		whare_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);
	}
	node_groups.push_back(whare_nodes);



	std::vector<Node*> dist_nodes;
	for (int i = 20; i < 40; i++)
	{
		Node* cur_node = new Node("Distributer", i, 2);

		dist_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);

	}
	node_groups.push_back(dist_nodes);



	std::vector<Node*> pharm_nodes;
	for (int i = 0; i < 20; i++)
	{
		Node* cur_node = new Node("Pharmacy", i, 1);

		pharm_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);

	}
	node_groups.push_back(pharm_nodes);*/



	std::vector<Node*> manu_nodes;
	std::vector<Node*> whare_nodes;
	std::vector<Node*> dist_nodes;
	std::vector<Node*> pharm_nodes;
	std::vector<Node*> deliv_nodes;

	std::vector<Node*> manu_whare_nodes;
	std::vector<Node*> whare_dist_nodes;
	std::vector<Node*> dist_pharm_nodes;
	int counter = 0;

	int num_delivery = num_per / 5;
	for (int i = 0; i < num_delivery; i++, counter ++)
	{
		Node* cur_node = new Node("Deliver", counter, 4);
		deliv_nodes.push_back(cur_node);
		manu_whare_nodes.push_back(cur_node);
		whare_dist_nodes.push_back(cur_node);
		dist_pharm_nodes.push_back(cur_node);
	}


	for (int i = 0; i < num_per; i++)
	{
		for (int j = 0; j < 4; j++, counter++)
		{
			switch (j)
			{
			case 0:
			{
				Node* cur_node = new Node("Manufacturer", counter, 0);
				manu_whare_nodes.push_back(cur_node);
				manu_nodes.push_back(cur_node);
				break;
			}
			case 1:
			{
				Node* cur_node = new Node("Wharehouse", counter, 1);
				manu_whare_nodes.push_back(cur_node);
				whare_dist_nodes.push_back(cur_node);
				whare_nodes.push_back(cur_node);
				break;
			}
			case 2:
			{
				Node* cur_node = new Node("Pharmacy", counter, 3);
				dist_pharm_nodes.push_back(cur_node);
				pharm_nodes.push_back(cur_node);
				break;

			}
			case 3:
			{
				Node* cur_node = new Node("Distributer", counter, 2);
				whare_dist_nodes.push_back(cur_node);
				dist_pharm_nodes.push_back(cur_node);
				dist_nodes.push_back(cur_node);
				break;
			}
			}
		}
	}
	q_pools.push_back(manu_whare_nodes);
	q_pools.push_back(whare_dist_nodes);
	q_pools.push_back(dist_pharm_nodes);

	node_groups.push_back(manu_nodes);
	node_groups.push_back(whare_nodes);
	node_groups.push_back(dist_nodes);
	node_groups.push_back(pharm_nodes);
	node_groups.push_back(deliv_nodes);


}

void make_the_nodes_inc_mal(std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::vector<std::vector<std::shared_ptr<Node>>>& node_groups, int num_per, const double &mal_percent)
{
	std::vector<std::shared_ptr<Node>> manu_nodes;
	std::vector<std::shared_ptr<Node>> whare_nodes;
	std::vector<std::shared_ptr<Node>> dist_nodes;
	std::vector<std::shared_ptr<Node>> pharm_nodes;
	std::vector<std::shared_ptr<Node>> deliv_nodes;
	std::vector<std::shared_ptr<Node>> manu_whare_nodes;
	std::vector<std::shared_ptr<Node>> whare_dist_nodes;
	std::vector<std::shared_ptr<Node>> dist_pharm_nodes;
	int counter = 0;

	int num_mal = num_per * mal_percent; 
	/*int num_delivery = num_per / 5;
	for (int i = 0; i < num_delivery; i++, counter++)
	{

		auto cur_node = std::make_shared<Node>("Deliver", counter, 4);
		deliv_nodes.push_back(cur_node);
		manu_whare_nodes.push_back(cur_node);
		whare_dist_nodes.push_back(cur_node);
		dist_pharm_nodes.push_back(cur_node);
	}*/


	for (int i = 0; i < num_per; i++)
	{
		if (i < num_mal)
		{
			for (int j = 0; j < 4; j++, counter++)
			{
				switch (j)
				{
				case 0:
				{
					auto cur_node = std::make_shared<Node>("Manufacturer", counter, 0, true); // true - malicious
					manu_whare_nodes.push_back(cur_node);
					manu_nodes.push_back(cur_node);
					break;
				}
				case 1:
				{
					auto cur_node = std::make_shared<Node>("Wharehouse", counter, 1, true);
					manu_whare_nodes.push_back(cur_node);
					whare_dist_nodes.push_back(cur_node);
					whare_nodes.push_back(cur_node);
					break;
				}
				case 2:
				{
					auto cur_node = std::make_shared<Node>("Pharmacy", counter, 3, true);
					dist_pharm_nodes.push_back(cur_node);
					pharm_nodes.push_back(cur_node);
					break;

				}
				case 3:
				{
					auto cur_node = std::make_shared<Node>("Distributer", counter, 2, true);
					whare_dist_nodes.push_back(cur_node);
					dist_pharm_nodes.push_back(cur_node);
					dist_nodes.push_back(cur_node);
					break;
				}
				}
			}
		}
		else
		{
			for (int j = 0; j < 4; j++, counter++)
			{
				switch (j)
				{
				case 0:
				{
					auto cur_node = std::make_shared<Node>("Manufacturer", counter, 0); 
					manu_whare_nodes.push_back(cur_node);
					manu_nodes.push_back(cur_node);
					break;
				}
				case 1:
				{
					auto cur_node = std::make_shared<Node>("Wharehouse", counter, 1);
					manu_whare_nodes.push_back(cur_node);
					whare_dist_nodes.push_back(cur_node);
					whare_nodes.push_back(cur_node);
					break;
				}
				case 2:
				{
					auto cur_node = std::make_shared<Node>("Pharmacy", counter, 3);
					dist_pharm_nodes.push_back(cur_node);
					pharm_nodes.push_back(cur_node);
					break;

				}
				case 3:
				{
					auto cur_node = std::make_shared<Node>("Distributer", counter, 2);
					whare_dist_nodes.push_back(cur_node);
					dist_pharm_nodes.push_back(cur_node);
					dist_nodes.push_back(cur_node);
					break;
				}
				}
			}
		}
		
	}
	q_pools.push_back(manu_whare_nodes);
	q_pools.push_back(whare_dist_nodes);
	q_pools.push_back(dist_pharm_nodes);

	node_groups.push_back(manu_nodes);
	node_groups.push_back(whare_nodes);
	node_groups.push_back(dist_nodes);
	node_groups.push_back(pharm_nodes);
	node_groups.push_back(deliv_nodes);
}

void make_the_nodes_safe(std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::vector<std::vector<std::shared_ptr<Node>>>& node_groups, int num_per)
{

	//std::vector<Node* > all_nodes;
	



	std::vector<std::shared_ptr<Node>> manu_nodes;
	std::vector<std::shared_ptr<Node>> whare_nodes;
	std::vector<std::shared_ptr<Node>> dist_nodes;
	std::vector<std::shared_ptr<Node>> pharm_nodes;
	std::vector<std::shared_ptr<Node>> deliv_nodes;
	std::vector<std::shared_ptr<Node>> manu_whare_nodes;
	std::vector<std::shared_ptr<Node>> whare_dist_nodes;
	std::vector<std::shared_ptr<Node>> dist_pharm_nodes;
	int counter = 0;

	int num_delivery = num_per / 5;
	for (int i = 0; i < num_delivery; i++, counter++)
	{

		auto cur_node = std::make_shared<Node>("Deliver", counter, 4);
		deliv_nodes.push_back(cur_node);
		manu_whare_nodes.push_back(cur_node);
		whare_dist_nodes.push_back(cur_node);
		dist_pharm_nodes.push_back(cur_node);
	}


	for (int i = 0; i < num_per; i++)
	{
		for (int j = 0; j < 4; j++, counter++)
		{
			switch (j)
			{
			case 0:
			{
				auto cur_node = std::make_shared<Node>("Manufacturer", counter, 0);
				manu_whare_nodes.push_back(cur_node);
				manu_nodes.push_back(cur_node);
				break;
			}
			case 1:
			{
				auto cur_node = std::make_shared<Node>("Wharehouse", counter, 1);
				manu_whare_nodes.push_back(cur_node);
				whare_dist_nodes.push_back(cur_node);
				whare_nodes.push_back(cur_node);
				break;
			}
			case 2:
			{
				auto cur_node = std::make_shared<Node>("Pharmacy", counter, 3);
				dist_pharm_nodes.push_back(cur_node);
				pharm_nodes.push_back(cur_node);
				break;

			}
			case 3:
			{
				auto cur_node = std::make_shared<Node>("Distributer", counter, 2);
				whare_dist_nodes.push_back(cur_node);
				dist_pharm_nodes.push_back(cur_node);
				dist_nodes.push_back(cur_node);
				break;
			}
			}
		}
	}
	q_pools.push_back(manu_whare_nodes);
	q_pools.push_back(whare_dist_nodes);
	q_pools.push_back(dist_pharm_nodes);

	node_groups.push_back(manu_nodes);
	node_groups.push_back(whare_nodes);
	node_groups.push_back(dist_nodes);
	node_groups.push_back(pharm_nodes);
	node_groups.push_back(deliv_nodes);


}




int mal_nodes_test(const double &percent_mal, const int &network_size, const int &iter)
{

	std::vector<std::vector<std::shared_ptr<Node>>> node_groups;
	std::vector<std::vector<std::shared_ptr<Node>>> q_pools;
	std::vector<std::shared_ptr<Quorum>> the_quorums;
	int num_per = network_size / 4; 
	//make_the_nodes_safe(q_pools, node_groups, 500);
	make_the_nodes_inc_mal(q_pools, node_groups, num_per, percent_mal); // need to update make_the_nodes_inc_mal
	std::string prev_block_str = "Hash of the previous blocks";
	int mal_quorums{ 0 };
	for (int i = 0; i < 5000; i++)
	{

		
		prev_block_str = std::to_string(i) + std::to_string(iter);
		//quorum_selection_test(the_nodes, times_selected,  prev_block_str, i, dist);
		//q_test(q_pools, prev_block_str, i, q_type_count, dist, types);
		form_quorums(the_quorums, q_pools, prev_block_str, mal_quorums);
		the_quorums.clear();
		//std::cout << i << std::endl;
	}

	std::cout << "Number of malicious quorums at " << network_size << " nodes, 5000 blocks " << percent_mal * 100 << ": " << mal_quorums << std::endl;
	//std::cout << "end of mal test" << std::endl;
	return mal_quorums;
}


void mal_nodes_test_run()
{
	int num_mal_1thou[5]{ 0 };
	//int num_mal_9thou[5]{ 0 };
	int num_mal_13thou[5]{ 0 };
	int num_mal_25thou[5]{ 0 };
	double percent_mal = .10;

	//mal_nodes_test_run_helper(num_mal_1thou, 1000);
	//mal_nodes_test_run_helper(num_mal_13thou, 13000);
	mal_nodes_test_run_helper(num_mal_25thou, 25000);


	std::ofstream out;
	out.open("mal_nodes25.csv");
	out << "1000 nodes\n";
	/*for (int i = 0; i < 5; i++)
	{
		out << num_mal_1thou[i] / 100 << ",";
	}
	out << "\n13000 nodes\n";
	for (int i = 0; i < 5; i++)
	{
		out << num_mal_13thou[i] / 100 << ",";
	}*/
	out << "\n25000 nodes\n";
	for (int i = 0; i < 5; i++)
	{
		out << num_mal_25thou[i] / 100 << ",";
	}
	std::cout << "Done";
	
}

void mal_nodes_test_run_helper(int cur_arr[], const int &num_nodes)
{
	double percent_mal = .10;

	for (int j = 0; j < 100; j++)
	{
		std::cout << "Iter: " << j << std::endl;

		for (int i = 0; i < 5; i++)
		{
			cur_arr[i] += mal_nodes_test(percent_mal, num_nodes, j);
			percent_mal += .05;
		}
		percent_mal = .10;
	}

}



void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int times_selected[4][20], std::string& prev_block_hash, int block_num, int dist[])
{

	/*if ((block_num % 10) == 0)
	{
		increment_entity_ids(all_nodes);
	}*/

	std::string cur_hash = sha256(prev_block_hash);
	const int num_of_quorums = all_nodes.size() - 1;
	//std::cout << "Quorum selection test: \n" << "Number of potential quorums: " << num_of_quorums << std::endl;

	//std::cout << "Quorum size: " << quorum_size << std::endl;

	//increment_entity_ids(all_nodes);
	unsigned long long hash_int_val = 0;
	int cur_option = 0;
	std::vector<Quorum*> the_quorums;
	//const int quorum_size = std::ceil(std::log(all_nodes.size())); ///////CHANGE this connor. Not getting enough since length is num of vectors since we switched to multiple quorums
	unsigned short quorum_size = 0;
	/// ask if all quorums should be odd or if even is okay. 
	std::hash<std::string> hash_string;
	unsigned int pool_size = 0;
	unsigned int pool_1_size = 0;
	unsigned int pool_2_size = 0;
	unsigned int cur_selected = 0;
	bool i_plus_one = false;
	bool duplicate = false; // cur node selected already in a pool?? or not. false obvs means not.
	int i = 0;

	cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
	hash_int_val = (std::stoull(cur_hash, nullptr, 16));

	while (i < num_of_quorums)
	{
		std::vector<Node*> q_members;
		/*int q_src_1 = i;
		int q_src_2 = i + 1;*/
		pool_1_size = all_nodes[i].size();
		pool_2_size = all_nodes[i + 1].size();
		quorum_size = std::ceil(std::log(pool_1_size + pool_2_size));
		Quorum* cur_quorum = new Quorum(quorum_size);
		pool_size = pool_1_size + pool_2_size;
		
		std::default_random_engine rand_gen(hash_int_val);
		std::uniform_int_distribution<int> distribution(0, pool_size-1);
		/*if (quorum_size % 2 == 0) ////////////////////////////////////////// Decided against restricting even quorum size 7/28/21 - Connor 
		{
			quorum_size += 1;
		}*/
		for (int j = 0; j < quorum_size; j++)
		{
			
			//cur_hash = hash_string(cur_hash);
			cur_hash = cur_hash + std::to_string(j);
			cur_hash = sha256(cur_hash);
			//std::cout << cur_hash;

			//cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			//hash_int_val = (std::stoull(cur_hash, nullptr, 16));



			//cur_selected = hash_int_val % pool_size;
			cur_selected = distribution(rand_gen);
			dist[cur_selected] += 1;
			

			if (cur_selected > pool_1_size - 1) // cur selected is from entity group i + 1
			{
				duplicate = cur_quorum->add_member(all_nodes[i + 1][cur_selected - pool_1_size]);
				if (!duplicate)
				{
					times_selected[i + 1][cur_selected - pool_1_size] += 1;
				}
			}
			else
			{
				duplicate = cur_quorum->add_member(all_nodes[i][cur_selected]);
				if (!duplicate)
				{
					times_selected[i][cur_selected] += 1;
				}
				
			}
			//std::stoi(cur_hash, NULL, 16);

			//cur_option = hash_int_val % 2000;
			if (duplicate)
			{

				//std::cout << "duplicate";
				duplicate = false;
				j = j - 1;
				continue;
			}
			else
			{
				//times selected +=1
			}



		}
		/*std::cout << "Quorum " << i << ": \n";
		cur_quorum->print_quorum();*/
		the_quorums.push_back(cur_quorum);
		i++;

	}
	//for (int i = 0; i < num_of_quorums; i++)
	//{

	//	

	//	switch (i)
	//	{
	//	case 0: //size of selection pool == 2000, 1000 manufacturer, 1000 wharehouse 
	//	{
	//		
	//	}
	//		break;
	//	case 1: // size of selection pool == 2250, 1000 wharehouse, 1250 distributer
	//		break;
	//	case 2:
	//		break; //size of selection pool == 3000, 1750 pharmacy, 1250 distributer

	//	default:
	//		std::cout << "Error, code needs updating to support this number of quoroms. Disregard all results. Contact Connor.";

	//	}





	//	

	//	the_quorums.push_back(cur_quorum);


	for (int i = 0; i < num_of_quorums; i++)
	{
		the_quorums[i]->reset_membership();
	}
	//std::cout << "\nDone";
	//delete Quorum;



	//}

}



void q_test(std::vector<std::vector<Node*>>& q_pools, std::string& prev_block_hash, int block_num, int q_type_count[], int distrib[], int types[])
{


	static int start_index = 0;
	int cur_index = start_index;
	int count{ 0 };
	if (start_index > q_pools.size())
	{
		start_index = 0;
	}
	const int num_of_quorums = q_pools.size();
	std::string cur_hash = sha256(prev_block_hash);
	unsigned long long hash_int_val{ 0 };
	unsigned pool_size{ 0 };
	std::vector<Quorum*> the_quorums;

	int cur_selected{ 0 };
	
	int quorum_size{ 0 };
	bool duplicate{ false };

	while (count < num_of_quorums)
	{

		q_type_count[cur_index] += 1;
		pool_size = q_pools[cur_index].size();
		quorum_size = std::ceil(std::log(pool_size));
		/*if (quorum_size % 2 == 0)       ///////////// Decided against restricting even quorum numbers 7/28/21 - Connor 
		{
			quorum_size += 1;
		}*/
		Quorum* cur_quorum = new Quorum(quorum_size);
		for (int j = 0; j < quorum_size; j++)
		{
			cur_hash = cur_hash + std::to_string(j);
			cur_hash = sha256(cur_hash);
			cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			hash_int_val = (std::stoull(cur_hash, nullptr, 16));
			cur_selected = hash_int_val % pool_size;
			distrib[cur_selected] += 1;
			duplicate = cur_quorum->add_member(q_pools[cur_index][cur_selected]);
			if (duplicate)
			{
				duplicate = false;
				j = j - 1;
				continue;
			}
			else
			{
				types[q_pools[cur_index][cur_selected]->get_group()] += 1;
			}
		}
		the_quorums.push_back(cur_quorum);
		count++;
		cur_index++;
		if (cur_index == num_of_quorums)
		{
			cur_index = 0;
		}

	}
	
	for (int i = 0; i < num_of_quorums; i++)
	{
		the_quorums[i]->reset_membership();
	}

	start_index += 1;
	if (start_index == num_of_quorums)
	{
		start_index = 0;
	}







	



	/*for (int i = 0; i < num_of_quorums; i++)
	{
		q_type_count[i] += 1;
		pool_size = q_pools[i].size();
		quorum_size = std::ceil(std::log(pool_size));
		if (quorum_size % 2 == 0)
		{
			quorum_size += 1;
		}
		Quorum* cur_quorum = new Quorum(quorum_size);
		for (int j = 0; j < quorum_size; j++)
		{
			cur_hash = cur_hash + std::to_string(j);
			cur_hash = sha256(cur_hash);
			cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			hash_int_val = (std::stoull(cur_hash, nullptr, 16));
			cur_selected = hash_int_val % pool_size;
			distrib[cur_selected] += 1;
			duplicate = cur_quorum->add_member(q_pools[i][cur_selected]);
			if (duplicate)
			{
				duplicate = false;
				j = j - 1;
				continue;
			}
			else
			{
				types[q_pools[i][cur_selected]->get_group()] += 1;
			}
		}
		the_quorums.push_back(cur_quorum);
	}
	for (int i = 0; i < num_of_quorums; i++)
	{
		the_quorums[i]->reset_membership();
	}

	start_index += 1;
	if (start_index == num_of_quorums)
	{
		start_index = 0;
	}*/

}





void single_quorum_test(std::vector<std::vector<Node*>>& all_nodes, int num_entity_types, std::string& prev_block_hash)
{
	///Code following is code for forming a single quorum -- needs updating however, hash is not what should be used. Connor 7/6/21

//const int num_of_quorums = std::ceil(std::log(all_nodes.size()));


int num_nodes = all_nodes.size();
//int* q_members = new int[quorum_size];



std::string prev_hash = "dummy_str";

//time_t cur_time;
//time(&cur_time);

//auto prev_hash = cur_time;

//bool duplicate = false;
//for (int i = 0; i < quorum_size; i++)
//{
//	std::hash<int> cur_hash;

//	prev_hash = (cur_hash((prev_hash) + (i)));
//	
//	int cur_option = (prev_hash) % num_nodes;

//	for (int j = 0; j < i; j++)
//	{
//		if (q_members[j] == cur_option)
//		{
//			duplicate = true;
//		}

//	}
//	if (duplicate)
//	{
//		i = i - 1;
//		std::cout << "Duplicate averted...";
//		continue;
//	}
//	q_members[i] = cur_option;



//}

//std::cout << "Current quorum members: \n";
//for (int i = 0; i < quorum_size; i++)
//{
//	std::cout << "Member " << i << ": " << q_members[i] << std::endl;
//}


//delete[] q_members;
	


///Code following is code for forming a single quorum -- needs updating however, hash is not what should be used. Connor 7/6/21

//const int num_of_quorums = std::ceil(std::log(all_nodes.size()));


//int num_nodes = all_nodes.size();
//int* q_members = new int[quorum_size];



////std::string prev_hash = "dummy_str";

//time_t cur_time;
//time(&cur_time);

//auto prev_hash = cur_time;

//bool duplicate = false;
//for (int i = 0; i < quorum_size; i++)
//{
//	std::hash<int> cur_hash;

//	prev_hash = (cur_hash((prev_hash) + (i)));
//	
//	int cur_option = (prev_hash) % num_nodes;

//	for (int j = 0; j < i; j++)
//	{
//		if (q_members[j] == cur_option)
//		{
//			duplicate = true;
//		}

//	}
//	if (duplicate)
//	{
//		i = i - 1;
//		std::cout << "Duplicate averted...";
//		continue;
//	}
//	q_members[i] = cur_option;



//}

//std::cout << "Current quorum members: \n";
//for (int i = 0; i < quorum_size; i++)
//{
//	std::cout << "Member " << i << ": " << q_members[i] << std::endl;
//}


//delete[] q_members;

}


void times_select(int times_selected[4][20], const std::vector<std::vector<Node*>> &node_groups)
{


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			switch (i)
			{
			case 0:
			{
				times_selected[i][j] += node_groups[i][j]->get_times_selected();
				break;
			}
			case 1:
			{
				times_selected[i][j] += node_groups[i][j]->get_times_selected();
				break;
			}
			case 2:
			{
				times_selected[i][j] += node_groups[i][j]->get_times_selected();
				break;
			}
			case 3:
			{
				times_selected[i][j] += node_groups[i][j]->get_times_selected();
				break;
			}
			}
		}
	}
}


void scale_test()
{
	int times_selected_0[4][20]{ 0 };
	int times_selected_1[4][40]{ 0 };
	int times_selected_2[4][60]{ 0 };
	int times_selected_3[4][80]{ 0 };
	std::vector<std::vector<Node*>> q_pools;
	std::vector<std::vector<Node*>> node_groups;
	int q_type_count[3]{ 0 };
	int q_type_count2[3]{ 0 };
	int dist[40]{ 0 };
	//int q_type_count[3]{ 0 };
	int types[4]{ 0 };
	int types2[5]{ 0 };
	std::string prev_block_str;

	std::ofstream out;
	out.open("scal_output_pharm_block.csv");

	make_the_nodes(q_pools, node_groups, 20);
	for (int i = 0; i < 5000; i++)
	{

		prev_block_str = std::to_string(i);
		//quorum_selection_test(the_nodes, times_selected,  prev_block_str, i, dist);
		q_test(q_pools, prev_block_str, i, q_type_count, dist, types);
	}

	//out << "\n\n" << "20 per group, 20/5 for delivery\n";

	for (auto & row: node_groups)
	{
		/*for (int j = 0; j < 20; j++)
		{
			out << node_groups[i][j]->get_times_selected() << ",";
			if (i == 4 && j == 3)
			{
				
			}
		}*/
		for (auto& col : row)
		{
			out << col->get_times_selected() << ",";
		}
		out << "\n";
	}


	

	q_pools.clear();
	node_groups.clear();
	
	std::vector<std::vector<Node*>> q_pools1;
	std::vector<std::vector<Node*>> node_groups1;
	make_the_nodes(q_pools1, node_groups1, 40);
	for (int i = 0; i < 5000; i++)
	{

		prev_block_str = std::to_string(i);
		//quorum_selection_test(the_nodes, times_selected,  prev_block_str, i, dist);
		q_test(q_pools1, prev_block_str, i, q_type_count, dist, types);
	}
	out << "\n\n" << "40 per group 40/5 for delivery\n";

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			out << node_groups[i][j]->get_times_selected() << ",";
		}
		out << "\n";
	}*/
	for (auto& row : node_groups1)
	{
		for (auto& col : row)
		{
			out << col->get_times_selected() <<",";
		}
		out << "\n";
	}


	
	std::vector<std::vector<Node*>> q_pools2;
	std::vector<std::vector<Node*>> node_groups2;
	out << "\n\n" << "80 per group, 80/5 for delivery\n";
	make_the_nodes(q_pools2, node_groups2, 80);
	for (int i = 0; i < 5000; i++)
	{

		prev_block_str = std::to_string(i);
		//quorum_selection_test(the_nodes, times_selected,  prev_block_str, i, dist);
		q_test(q_pools2, prev_block_str, i, q_type_count2, dist, types2);
	}

	for (auto& row : node_groups2)
	{
		for (auto& col : row)
		{
			out << col->get_times_selected() <<",";
		}
		out << "\n";
	}
	q_pools2.clear();
	node_groups2.clear();
	std::cout <<  "Done with scalibility test\n";

}
