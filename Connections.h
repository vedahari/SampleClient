/*
 * Connection.h
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */

#ifndef CONNECTIONS_H_
#define CONNECTIONS_H_

#include <vector>
#include <thread>
#include "Common.h"

const int MAXIMUM_EVENT_SIZE = 50;

class Connection{
	int exec_core;
	bool close_connection;
	std::thread::id thread_id;
	int epoll_fd;
	int sock_fd;

public:
	int start_tcp_connection(const uint32_t& ip_addr, const uint16_t& port);
	int stop_tcp_connection();
	std::thread launch();
	void run_connection_thread();
	int send_kvstore_request();

};





#endif /* CONNECTIONS_H_ */
