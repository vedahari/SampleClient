/*
 * Client.h
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <vector>

#include "Common.h"
#include "Connections.h"

struct ClientAttributes{
	uint16_t port;
	uint32_t ip_addr;
	uint16_t num_of_connections;
	uint16_t msgs_per_request;
	uint32_t num_of_msgs_per_connection;
	uint32_t delay;
	bool verbose;
	ClientAttributes():port(80),ip_addr(-1),num_of_connections(1),
			msgs_per_request(1),num_of_msgs_per_connection(1024),delay(0),
			verbose(false)
	{}
};

class Client{
public:
	static Client& get_instance()
	{
		static Client instance;
		return instance;
	}
	void initialize(const ClientAttributes& attr);
	Client(Client const&) = delete;
    void operator=(Client const&)  = delete;



    void set_attributes(const ClientAttributes& attr);
    ClientAttributes get_attributes();
    void run_benchmark();

private:
    Client(){}
    ClientAttributes client_attr;
    std::vector<Connection> connections;
};




#endif /* CLIENT_H_ */
