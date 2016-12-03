/*
 * Utils.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */

#ifndef UTILS_CPP_
#define UTILS_CPP_
#include "Utils.h"
#include <cstdio>

void usage(char *name)
{
	printf("%s -i <ip_addr> -p <port> -c <num_of_connections> -m <msg_num> -n <req_num> -d <milliseconds> -v -h\n", name);
	printf("Example: %s -i 0.0.0.0 -p 12345 -c 12 -m 100 -d 0 -n 100000\n", name);
}

void help(char * name)
{
	usage(name);
	printf("\n-i: The IP address of the server you are connecting to\n");
	printf("-p: The port of the server you are connecting to\n");
	printf("-c(default=1): The number of socket connections you want to send messages from\n");
	printf("-m(default=1): The number of messages that are sent per request\n");
	printf("-d(default=0): Time to delay in milliseconds after each request\n");
	printf("-n: The number of requests you want to send per socket in total\n");
	printf("-v: Run the program in verbose mode\n");
	printf("-h: Displays this message\n");

}


#endif /* UTILS_CPP_ */
