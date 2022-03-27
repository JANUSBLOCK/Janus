#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.h"
#include <string>
#include <vector>
#include <ctime>
#pragma once

class Block
{
private:
	
	std::vector<Transaction> trans_list; 
	std::vector<std::string> valid_sigs;
	std::string  prev_hash_str;  //
	//std::string type_of_transaction_str; 
	time_t time_stamp;//time stamp

public:

	Block(unsigned long int block_index, const std::vector<Transaction> &transactions, const std::vector<std::string> &sigs, const std::string &prev_hash)
	{
		this->trans_list = transactions;
		this->valid_sigs = sigs;
		this->prev_hash_str = prev_hash;
		//this->type_of_trans_str = type_of_trans;
		time(&time_stamp);
	}
	
	//std::string get_trans_type() { return type_of_transaction_str; }

	std::string get_prev_hash() { return prev_hash_str; }

	std::vector<std::string> get_sigs() { return valid_sigs; }

	std::vector<Transaction> get_trans() { return trans_list; }
	
	//auto get_time{ return time_stamp; }



};


#endif