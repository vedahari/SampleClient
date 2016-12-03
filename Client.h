/*
 * Client.h
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Common.h"

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
	static Client& getInstance()
	{
		static Client instance;
		return instance;
	}
	Client(Client const&) = delete;
    void operator=(Client const&)  = delete;



    void setAttributes(const ClientAttributes& attr);


private:
    Client(){}
    Client(const Client&);
    void operator=(const Client&);
    ClientAttributes mAttr;

};




#endif /* CLIENT_H_ */
