/********************************************************************************
 * 
 *  soc.h
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#ifndef SOC_H
#define SOC_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT 31100
#define SERVERPORTSTR "31100"
#define SERVERIP "199.17.28.80"
#define SERVERNAME "ahscentos"
#define BUFL 100
#define MAX_REQ 5

#endif
