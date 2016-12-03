/*
 * Client.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */
#include <thread>
#include "Client.h"


void Client::set_attributes(const ClientAttributes& attr)
{
	client_attr = attr;
}

ClientAttributes Client::get_attributes()
{
	return client_attr;
}

void Client::initialize(const ClientAttributes& attr)
{
	set_attributes(attr);
	connections.clear();
	connections.resize(attr.num_of_connections);
}

void run_connection_thread(Connection& conn)
{

}
void Client::run_benchmark()
{
	std::thread connection_thread[client_attr.num_of_connections];
	for (int i=0;i<client_attr.num_of_connections;i++){
		connection_thread[i] =
				std::thread(run_connection_thread,std::ref(connections[i]));
	}

	for (int i=0;i<client_attr.num_of_connections;i++){
		connection_thread[i].join();
	}
}



