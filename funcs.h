#ifndef FUNCS_H
#define FUNCS_H
#pragma once
#include"Node.h"
#include "Quorum.h"




template <typename T>
void delete_pointed_to(T* const ptr)
{
    delete ptr;
}

void form_quorums(std::vector<std::shared_ptr<Quorum>>& the_quorums, std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::string& prev_block_hash, int & mal_quorums);

int get_quorum_size(const int& network_size);

void increment_entity_ids(std::vector<std::vector<Node* >>& all_nodes);

int mal_nodes_test(const double &percent_mal, const int& network_size, const int& iter);

void mal_nodes_test_run();

void mal_nodes_test_run_helper(int cur_arr[], const int& num_nodes);


void make_the_nodes(std::vector<std::vector<Node*>> &q_pools, std::vector<std::vector<Node*>> &node_groups, int num_per);

void make_the_nodes_inc_mal(std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::vector<std::vector<std::shared_ptr<Node>>>& node_groups, int num_per, const double& mal_percent);

void make_the_nodes_safe(std::vector<std::vector<std::shared_ptr<Node>>>& q_pools, std::vector<std::vector<std::shared_ptr<Node>>>& node_groups, int num_per);

void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int times_selected [4][20], std::string &prev_block_hash, int block_num, int []);


void q_test(std::vector<std::vector<Node*>>& q_pools,  std::string& prev_block_hash, int block_num, int[], int[], int[]);


void times_select(int times_selected[4][20], const std::vector<std::vector<Node*>>& node_groups);

void scale_test();


#endif
