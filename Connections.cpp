/*
 * Connection.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: ved
 */
#include "Connections.h"
#include <sys/epoll.h>
#include <arpa/inet.h>

int Connection::start_tcp_connection(const uint32_t& ip_addr, const uint16_t& port)
{
	int socket_desc;
	struct sockaddr_in server;
	struct epoll_event ev;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (socket_desc == -1) {
		printf("Failed to create socket\n");
		exit(EXIT_FAILURE);
	}

	sock_fd = socket_desc;

	server.sin_addr.s_addr = ip_addr;
	server.sin_family = AF_INET;
	server.sin_port = port;

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		printf("Failed to connect to server\n");
		exit(-1);
	}

	ev.events = EPOLLOUT;
	ev.data.fd = socket_desc;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &ev);

	return socket_desc;
}


int Connection::stop_tcp_connection()
{
	epoll_ctl(epoll_fd, EPOLL_CTL_DEL, sock_fd, NULL);
	close(sock_fd);
	//TODO: If number of connections is not met start_tcp_conn again here

	return 0;
}

std::thread Connection::launch()
{
	return std::thread(&Connection::run_connection_thread,this);
}

int Connection::send_kvstore_request()
{
	struct epoll_event ev;

	/* TODO: Form the request message here*/

	//do write to the socket here

	ev.events = EPOLLIN;
	ev.data.fd = sock_fd;
	int result = epoll_ctl(epoll_fd, EPOLL_CTL_MOD, sock_fd, &ev);
	if (result == -1){
		cout<<" Error when changing epoll modify"<<endl;
		return -1;
	}
	return 0;
}

void Connection::run_connection_thread()
{
	epoll_fd = epoll_create1(0);
	if (epoll_fd == -1){
		cout<<"Error in epoll_create!"<<endl;
		exit(EXIT_FAILURE);
	}

	struct epoll_event* events = (struct epoll_event *)
			calloc(MAXIMUM_EVENT_SIZE,sizeof(struct epoll_event));

	if (NULL == events){
		cout<<"Error while allocating memory for fd_events";
		exit(EXIT_FAILURE);
	}

	/*TODO:: Add enough events through the start_tcp_connection method*/


	int num_events = epoll_wait(epoll_fd,events,MAXIMUM_EVENT_SIZE,-1);

	//Process the events here
	for (int i=0;i<num_events;i++){
		if (events[i].events& EPOLLERR){
			//handle error here
		}
		if (events[i].events & EPOLLIN){
			//do our read and validate the kvstore response
		}
		else if (events[i].events& EPOLLOUT){
			//do send_kvstore_request
		}
	}

}
