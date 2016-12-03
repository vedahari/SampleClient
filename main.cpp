/*
 * main.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */

#include <getopt.h>
#include <arpa/inet.h>

#include "Common.h"
#include "Utils.h"
#include "Client.h"



ClientAttributes process_args(int argc, char*argv[]){
	srand(time(NULL));
	int option;
	ClientAttributes cl_attr;
	uint8_t req_args = 0b11;
	while ((option = getopt(argc, argv, "vhi:p:c:m:d:n:")) != -1) {
		switch (option) {
		case 'i':
			cl_attr.ip_addr = inet_addr(optarg);
			req_args &= 0b10;
			break;
		case 'p':
			cl_attr.port = htons(atoi(optarg));
			req_args &= 0b01;
			break;
		case 'c':
			cl_attr.num_of_connections = atoi(optarg);
			break;
		case 'm':
			cl_attr.msgs_per_request = atoi(optarg);
			break;
		case 'n':
			cl_attr.num_of_msgs_per_connection = atoi(optarg);
			break;
		case 'd':
			cl_attr.delay = atoi(optarg);
			break;
		case 'v':
			cl_attr.verbose = true;
			break;
		case 'h':
			help(argv[0]);
			exit(EXIT_FAILURE);
			break;
		default:
			help(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (req_args != 0) {
		help(argv[0]);
		exit(EXIT_FAILURE);
	}
	return cl_attr;

}

// Sets up all the arguments that were passed to the program
// and then starts the benchmark
int main(int argc, char *argv[])
{
	ClientAttributes attr = process_args(argc,argv);
	Client::getInstance().setAttributes(attr);

	run_benchmark2(ip_addr, port, num_of_connections, msgs_per_request,
		      num_of_msgs_per_connection, delay);
	return 0;
}



