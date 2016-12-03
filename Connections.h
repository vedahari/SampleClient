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

struct Connection{
	int exec_core;
	bool close_connection;
	std::thread::id thread_id;
};

class Connections{
public:
	void initialize(int size);
	Connections(int conn_cnt):connections(conn_cnt){};
	std::vector<Connection> connections;
};



#endif /* CONNECTIONS_H_ */
