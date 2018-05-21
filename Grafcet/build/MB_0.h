/* File generated by Beremiz (PlugGenerate_C method of modbus Plugin instance) */

/*
 * Copyright (c) 2016 Mario de Sousa (msousa@fe.up.pt)
 *
 * This file is part of the Modbus library for Beremiz and matiec.
 *
 * This Modbus library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this Modbus library.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This code is made available on the understanding that it will not be
 * used in safety-critical situations without a full and competent review.
 */

#include "mb_addr.h"
#include "mb_tcp_private.h"
#include "mb_master_private.h"



#define DEF_REQ_SEND_RETRIES 0

  // Used by the Modbus server node
#define MEM_AREA_SIZE 65536
typedef struct{
	    u16		ro_bits [MEM_AREA_SIZE];
	    u16		rw_bits [MEM_AREA_SIZE];
	    u16		ro_words[MEM_AREA_SIZE];
	    u16		rw_words[MEM_AREA_SIZE];
	} server_mem_t;

typedef struct{
	    const char *location;
	    u8		slave_id;
	    node_addr_t	node_address;
	    int		mb_nd;      // modbus library node used for this server 
	    int		init_state; // store how far along the server's initialization has progressed
	    pthread_t	thread_id;  // thread handling this server
	    server_mem_t	mem_area;
	} server_node_t;


  // Used by the Modbus client node
typedef struct{
	    const char *location;
	    node_addr_t	node_address;
	    int		mb_nd;
	    int		init_state; // store how far along the client's initialization has progressed
	    u64		comm_period;
	    int		prev_error; // error code of the last printed error message (0 when no error) 
	    pthread_t	thread_id;  // thread handling all communication with this client
	} client_node_t;


  // Used by the Modbus client plugin
typedef enum {
	    req_input,
	    req_output,
	    no_request		/* just for tests to quickly disable a request */
	} iotype_t;

#define REQ_BUF_SIZE 2000
typedef struct{
	    const char *location;
	    int		client_node_id;
	    u8		slave_id;
	    iotype_t	req_type;
	    u8		mb_function;
	    u16		address;
	    u16		count;
	    int		retries;
	    u8		error_code; // modbus error code (if any) of current request
	    int		prev_error; // error code of the last printed error message (0 when no error) 
	    struct timespec resp_timeout;
	      // buffer used to store located PLC variables
	    u16		plcv_buffer[REQ_BUF_SIZE];
	      // buffer used to store data coming from / going to server
	    u16		coms_buffer[REQ_BUF_SIZE]; 
	    pthread_mutex_t coms_buf_mutex; // mutex to access coms_buffer[]
	} client_request_t;


/* The total number of nodes, needed to support _all_ instances of the modbus plugin */
#define TOTAL_TCPNODE_COUNT       12
#define TOTAL_RTUNODE_COUNT       0
#define TOTAL_ASCNODE_COUNT       0

/* Values for instance 0 of the modbus plugin */
#define MAX_NUMBER_OF_TCPCLIENTS  10

#define NUMBER_OF_TCPSERVER_NODES 1
#define NUMBER_OF_TCPCLIENT_NODES 1
#define NUMBER_OF_TCPCLIENT_REQTS 3

#define NUMBER_OF_RTUSERVER_NODES 0
#define NUMBER_OF_RTUCLIENT_NODES 0
#define NUMBER_OF_RTUCLIENT_REQTS 0

#define NUMBER_OF_ASCIISERVER_NODES 0
#define NUMBER_OF_ASCIICLIENT_NODES 0
#define NUMBER_OF_ASCIICLIENT_REQTS 0

#define NUMBER_OF_SERVER_NODES (NUMBER_OF_TCPSERVER_NODES + \
                                NUMBER_OF_RTUSERVER_NODES + \
                                NUMBER_OF_ASCIISERVER_NODES)

#define NUMBER_OF_CLIENT_NODES (NUMBER_OF_TCPCLIENT_NODES + \
                                NUMBER_OF_RTUCLIENT_NODES + \
                                NUMBER_OF_ASCIICLIENT_NODES)

#define NUMBER_OF_CLIENT_REQTS (NUMBER_OF_TCPCLIENT_REQTS + \
                                NUMBER_OF_RTUCLIENT_REQTS + \
                                NUMBER_OF_ASCIICLIENT_REQTS)


/*initialization following all parameters given by user in application*/

static client_node_t		client_nodes[NUMBER_OF_CLIENT_NODES] = {
/*node 0.0*/
{"0.0", {naf_tcp, {.tcp = {"localhost", "5502", DEF_CLOSE_ON_SILENCE}}}, -1 /* mb_nd */, 0 /* init_state */, 100 /* communication period */, 0 /* prev_error */}
};


static client_request_t	client_requests[NUMBER_OF_CLIENT_REQTS] = {
/*request 0_0_0*/
{"0_0_0", 0, 1, req_input, 2, 0 , 111,
DEF_REQ_SEND_RETRIES, 0 /* error_code */, 0 /* prev_code */, {0, 10000000} /* timeout */,
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},

/*request 0_0_1*/
{"0_0_1", 0, 1, req_output, 15, 0 , 152,
DEF_REQ_SEND_RETRIES, 0 /* error_code */, 0 /* prev_code */, {0, 10000000} /* timeout */,
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},

/*request 0_0_2*/
{"0_0_2", 0, 1, req_output, 6, 0 , 1,
DEF_REQ_SEND_RETRIES, 0 /* error_code */, 0 /* prev_code */, {0, 10000000} /* timeout */,
{0}, {0}}
};


static server_node_t		server_nodes[NUMBER_OF_SERVER_NODES] = {
/*node 0.1*/
{"0.1", 0, {naf_tcp, {.tcp = {"127.0.0.1", "5503", DEF_CLOSE_ON_SILENCE}}}, -1 /* mb_nd */, 0 /* init_state */}
}
;

/*******************/
/*located variables*/
/*******************/

u16 *__IX0_0_0_0 = &client_requests[0].plcv_buffer[0];
u16 *__IX0_0_0_1 = &client_requests[0].plcv_buffer[1];
u16 *__IX0_0_0_76 = &client_requests[0].plcv_buffer[76];
u16 *__IX0_0_0_77 = &client_requests[0].plcv_buffer[77];
u16 *__IX0_0_0_78 = &client_requests[0].plcv_buffer[78];
u16 *__IX0_0_0_3 = &client_requests[0].plcv_buffer[3];
u16 *__IX0_0_0_19 = &client_requests[0].plcv_buffer[19];
u16 *__IX0_0_0_24 = &client_requests[0].plcv_buffer[24];
u16 *__IX0_0_0_40 = &client_requests[0].plcv_buffer[40];
u16 *__IX0_0_0_45 = &client_requests[0].plcv_buffer[45];
u16 *__IX0_0_0_61 = &client_requests[0].plcv_buffer[61];
u16 *__IX0_0_0_66 = &client_requests[0].plcv_buffer[66];
u16 *__IX0_0_0_73 = &client_requests[0].plcv_buffer[73];
u16 *__IX0_0_0_90 = &client_requests[0].plcv_buffer[90];
u16 *__IX0_0_0_104 = &client_requests[0].plcv_buffer[104];
u16 *__IX0_0_0_108 = &client_requests[0].plcv_buffer[108];
u16 *__IX0_0_0_109 = &client_requests[0].plcv_buffer[109];
u16 *__IX0_0_0_110 = &client_requests[0].plcv_buffer[110];
u16 *__IX0_0_0_94 = &client_requests[0].plcv_buffer[94];
u16 *__IX0_0_0_97 = &client_requests[0].plcv_buffer[97];
u16 *__IX0_0_0_100 = &client_requests[0].plcv_buffer[100];
u16 *__IX0_0_0_6 = &client_requests[0].plcv_buffer[6];
u16 *__IX0_0_0_13 = &client_requests[0].plcv_buffer[13];
u16 *__IX0_0_0_27 = &client_requests[0].plcv_buffer[27];
u16 *__IX0_0_0_34 = &client_requests[0].plcv_buffer[34];
u16 *__IX0_0_0_48 = &client_requests[0].plcv_buffer[48];
u16 *__IX0_0_0_55 = &client_requests[0].plcv_buffer[55];
u16 *__IX0_0_0_2 = &client_requests[0].plcv_buffer[2];
u16 *__IX0_0_0_12 = &client_requests[0].plcv_buffer[12];
u16 *__IX0_0_0_22 = &client_requests[0].plcv_buffer[22];
u16 *__IX0_0_0_23 = &client_requests[0].plcv_buffer[23];
u16 *__IX0_0_0_33 = &client_requests[0].plcv_buffer[33];
u16 *__IX0_0_0_43 = &client_requests[0].plcv_buffer[43];
u16 *__IX0_0_0_44 = &client_requests[0].plcv_buffer[44];
u16 *__IX0_0_0_54 = &client_requests[0].plcv_buffer[54];
u16 *__IX0_0_0_64 = &client_requests[0].plcv_buffer[64];
u16 *__IX0_0_0_65 = &client_requests[0].plcv_buffer[65];
u16 *__IX0_0_0_69 = &client_requests[0].plcv_buffer[69];
u16 *__IX0_0_0_71 = &client_requests[0].plcv_buffer[71];
u16 *__IX0_0_0_72 = &client_requests[0].plcv_buffer[72];
u16 *__IX0_0_0_89 = &client_requests[0].plcv_buffer[89];
u16 *__IX0_0_0_93 = &client_requests[0].plcv_buffer[93];
u16 *__IX0_0_0_103 = &client_requests[0].plcv_buffer[103];
u16 *__IX0_0_0_107 = &client_requests[0].plcv_buffer[107];
u16 *__IX0_0_0_96 = &client_requests[0].plcv_buffer[96];
u16 *__IX0_0_0_99 = &client_requests[0].plcv_buffer[99];
u16 *__IX0_0_0_102 = &client_requests[0].plcv_buffer[102];
u16 *__IX0_0_0_95 = &client_requests[0].plcv_buffer[95];
u16 *__IX0_0_0_98 = &client_requests[0].plcv_buffer[98];
u16 *__IX0_0_0_101 = &client_requests[0].plcv_buffer[101];
u16 *__IX0_0_0_5 = &client_requests[0].plcv_buffer[5];
u16 *__IX0_0_0_21 = &client_requests[0].plcv_buffer[21];
u16 *__IX0_0_0_26 = &client_requests[0].plcv_buffer[26];
u16 *__IX0_0_0_42 = &client_requests[0].plcv_buffer[42];
u16 *__IX0_0_0_47 = &client_requests[0].plcv_buffer[47];
u16 *__IX0_0_0_63 = &client_requests[0].plcv_buffer[63];
u16 *__IX0_0_0_68 = &client_requests[0].plcv_buffer[68];
u16 *__IX0_0_0_75 = &client_requests[0].plcv_buffer[75];
u16 *__IX0_0_0_92 = &client_requests[0].plcv_buffer[92];
u16 *__IX0_0_0_106 = &client_requests[0].plcv_buffer[106];
u16 *__IX0_0_0_4 = &client_requests[0].plcv_buffer[4];
u16 *__IX0_0_0_20 = &client_requests[0].plcv_buffer[20];
u16 *__IX0_0_0_25 = &client_requests[0].plcv_buffer[25];
u16 *__IX0_0_0_41 = &client_requests[0].plcv_buffer[41];
u16 *__IX0_0_0_46 = &client_requests[0].plcv_buffer[46];
u16 *__IX0_0_0_62 = &client_requests[0].plcv_buffer[62];
u16 *__IX0_0_0_67 = &client_requests[0].plcv_buffer[67];
u16 *__IX0_0_0_74 = &client_requests[0].plcv_buffer[74];
u16 *__IX0_0_0_91 = &client_requests[0].plcv_buffer[91];
u16 *__IX0_0_0_105 = &client_requests[0].plcv_buffer[105];
u16 *__IX0_0_0_7 = &client_requests[0].plcv_buffer[7];
u16 *__IX0_0_0_14 = &client_requests[0].plcv_buffer[14];
u16 *__IX0_0_0_28 = &client_requests[0].plcv_buffer[28];
u16 *__IX0_0_0_35 = &client_requests[0].plcv_buffer[35];
u16 *__IX0_0_0_49 = &client_requests[0].plcv_buffer[49];
u16 *__IX0_0_0_56 = &client_requests[0].plcv_buffer[56];
u16 *__IX0_0_0_10 = &client_requests[0].plcv_buffer[10];
u16 *__IX0_0_0_17 = &client_requests[0].plcv_buffer[17];
u16 *__IX0_0_0_31 = &client_requests[0].plcv_buffer[31];
u16 *__IX0_0_0_38 = &client_requests[0].plcv_buffer[38];
u16 *__IX0_0_0_52 = &client_requests[0].plcv_buffer[52];
u16 *__IX0_0_0_59 = &client_requests[0].plcv_buffer[59];
u16 *__IX0_0_0_11 = &client_requests[0].plcv_buffer[11];
u16 *__IX0_0_0_18 = &client_requests[0].plcv_buffer[18];
u16 *__IX0_0_0_32 = &client_requests[0].plcv_buffer[32];
u16 *__IX0_0_0_39 = &client_requests[0].plcv_buffer[39];
u16 *__IX0_0_0_53 = &client_requests[0].plcv_buffer[53];
u16 *__IX0_0_0_60 = &client_requests[0].plcv_buffer[60];
u16 *__IX0_0_0_8 = &client_requests[0].plcv_buffer[8];
u16 *__IX0_0_0_15 = &client_requests[0].plcv_buffer[15];
u16 *__IX0_0_0_29 = &client_requests[0].plcv_buffer[29];
u16 *__IX0_0_0_36 = &client_requests[0].plcv_buffer[36];
u16 *__IX0_0_0_50 = &client_requests[0].plcv_buffer[50];
u16 *__IX0_0_0_57 = &client_requests[0].plcv_buffer[57];
u16 *__IX0_0_0_9 = &client_requests[0].plcv_buffer[9];
u16 *__IX0_0_0_16 = &client_requests[0].plcv_buffer[16];
u16 *__IX0_0_0_30 = &client_requests[0].plcv_buffer[30];
u16 *__IX0_0_0_37 = &client_requests[0].plcv_buffer[37];
u16 *__IX0_0_0_51 = &client_requests[0].plcv_buffer[51];
u16 *__IX0_0_0_58 = &client_requests[0].plcv_buffer[58];
u16 *__IX0_0_0_87 = &client_requests[0].plcv_buffer[87];
u16 *__IX0_0_0_86 = &client_requests[0].plcv_buffer[86];
u16 *__IX0_0_0_85 = &client_requests[0].plcv_buffer[85];
u16 *__IX0_0_0_84 = &client_requests[0].plcv_buffer[84];
u16 *__IX0_0_0_83 = &client_requests[0].plcv_buffer[83];
u16 *__IX0_0_0_82 = &client_requests[0].plcv_buffer[82];
u16 *__IX0_0_0_81 = &client_requests[0].plcv_buffer[81];
u16 *__IX0_0_0_80 = &client_requests[0].plcv_buffer[80];
u16 *__IX0_0_0_79 = &client_requests[0].plcv_buffer[79];
u16 *__IX0_0_0_88 = &client_requests[0].plcv_buffer[88];
u16 *__QX0_0_1_0 = &client_requests[1].plcv_buffer[0];
u16 *__QX0_0_1_2 = &client_requests[1].plcv_buffer[2];
u16 *__QX0_0_1_7 = &client_requests[1].plcv_buffer[7];
u16 *__QX0_0_1_31 = &client_requests[1].plcv_buffer[31];
u16 *__QX0_0_1_39 = &client_requests[1].plcv_buffer[39];
u16 *__QX0_0_1_63 = &client_requests[1].plcv_buffer[63];
u16 *__QX0_0_1_71 = &client_requests[1].plcv_buffer[71];
u16 *__QX0_0_1_95 = &client_requests[1].plcv_buffer[95];
u16 *__QX0_0_1_103 = &client_requests[1].plcv_buffer[103];
u16 *__QX0_0_1_113 = &client_requests[1].plcv_buffer[113];
u16 *__QX0_0_1_126 = &client_requests[1].plcv_buffer[126];
u16 *__QX0_0_1_146 = &client_requests[1].plcv_buffer[146];
u16 *__QX0_0_1_132 = &client_requests[1].plcv_buffer[132];
u16 *__QX0_0_1_136 = &client_requests[1].plcv_buffer[136];
u16 *__QX0_0_1_140 = &client_requests[1].plcv_buffer[140];
u16 *__QX0_0_1_11 = &client_requests[1].plcv_buffer[11];
u16 *__QX0_0_1_22 = &client_requests[1].plcv_buffer[22];
u16 *__QX0_0_1_43 = &client_requests[1].plcv_buffer[43];
u16 *__QX0_0_1_54 = &client_requests[1].plcv_buffer[54];
u16 *__QX0_0_1_75 = &client_requests[1].plcv_buffer[75];
u16 *__QX0_0_1_86 = &client_requests[1].plcv_buffer[86];
u16 *__QX0_0_1_5 = &client_requests[1].plcv_buffer[5];
u16 *__QX0_0_1_20 = &client_requests[1].plcv_buffer[20];
u16 *__QX0_0_1_35 = &client_requests[1].plcv_buffer[35];
u16 *__QX0_0_1_37 = &client_requests[1].plcv_buffer[37];
u16 *__QX0_0_1_52 = &client_requests[1].plcv_buffer[52];
u16 *__QX0_0_1_67 = &client_requests[1].plcv_buffer[67];
u16 *__QX0_0_1_69 = &client_requests[1].plcv_buffer[69];
u16 *__QX0_0_1_84 = &client_requests[1].plcv_buffer[84];
u16 *__QX0_0_1_99 = &client_requests[1].plcv_buffer[99];
u16 *__QX0_0_1_101 = &client_requests[1].plcv_buffer[101];
u16 *__QX0_0_1_107 = &client_requests[1].plcv_buffer[107];
u16 *__QX0_0_1_109 = &client_requests[1].plcv_buffer[109];
u16 *__QX0_0_1_111 = &client_requests[1].plcv_buffer[111];
u16 *__QX0_0_1_124 = &client_requests[1].plcv_buffer[124];
u16 *__QX0_0_1_130 = &client_requests[1].plcv_buffer[130];
u16 *__QX0_0_1_144 = &client_requests[1].plcv_buffer[144];
u16 *__QX0_0_1_150 = &client_requests[1].plcv_buffer[150];
u16 *__QX0_0_1_135 = &client_requests[1].plcv_buffer[135];
u16 *__QX0_0_1_139 = &client_requests[1].plcv_buffer[139];
u16 *__QX0_0_1_143 = &client_requests[1].plcv_buffer[143];
u16 *__QX0_0_1_134 = &client_requests[1].plcv_buffer[134];
u16 *__QX0_0_1_138 = &client_requests[1].plcv_buffer[138];
u16 *__QX0_0_1_142 = &client_requests[1].plcv_buffer[142];
u16 *__QX0_0_1_1 = &client_requests[1].plcv_buffer[1];
u16 *__QX0_0_1_3 = &client_requests[1].plcv_buffer[3];
u16 *__QX0_0_1_8 = &client_requests[1].plcv_buffer[8];
u16 *__QX0_0_1_32 = &client_requests[1].plcv_buffer[32];
u16 *__QX0_0_1_40 = &client_requests[1].plcv_buffer[40];
u16 *__QX0_0_1_64 = &client_requests[1].plcv_buffer[64];
u16 *__QX0_0_1_72 = &client_requests[1].plcv_buffer[72];
u16 *__QX0_0_1_96 = &client_requests[1].plcv_buffer[96];
u16 *__QX0_0_1_104 = &client_requests[1].plcv_buffer[104];
u16 *__QX0_0_1_114 = &client_requests[1].plcv_buffer[114];
u16 *__QX0_0_1_127 = &client_requests[1].plcv_buffer[127];
u16 *__QX0_0_1_147 = &client_requests[1].plcv_buffer[147];
u16 *__QX0_0_1_133 = &client_requests[1].plcv_buffer[133];
u16 *__QX0_0_1_137 = &client_requests[1].plcv_buffer[137];
u16 *__QX0_0_1_141 = &client_requests[1].plcv_buffer[141];
u16 *__QX0_0_1_12 = &client_requests[1].plcv_buffer[12];
u16 *__QX0_0_1_23 = &client_requests[1].plcv_buffer[23];
u16 *__QX0_0_1_44 = &client_requests[1].plcv_buffer[44];
u16 *__QX0_0_1_55 = &client_requests[1].plcv_buffer[55];
u16 *__QX0_0_1_76 = &client_requests[1].plcv_buffer[76];
u16 *__QX0_0_1_87 = &client_requests[1].plcv_buffer[87];
u16 *__QX0_0_1_6 = &client_requests[1].plcv_buffer[6];
u16 *__QX0_0_1_21 = &client_requests[1].plcv_buffer[21];
u16 *__QX0_0_1_36 = &client_requests[1].plcv_buffer[36];
u16 *__QX0_0_1_38 = &client_requests[1].plcv_buffer[38];
u16 *__QX0_0_1_53 = &client_requests[1].plcv_buffer[53];
u16 *__QX0_0_1_68 = &client_requests[1].plcv_buffer[68];
u16 *__QX0_0_1_70 = &client_requests[1].plcv_buffer[70];
u16 *__QX0_0_1_85 = &client_requests[1].plcv_buffer[85];
u16 *__QX0_0_1_100 = &client_requests[1].plcv_buffer[100];
u16 *__QX0_0_1_102 = &client_requests[1].plcv_buffer[102];
u16 *__QX0_0_1_108 = &client_requests[1].plcv_buffer[108];
u16 *__QX0_0_1_110 = &client_requests[1].plcv_buffer[110];
u16 *__QX0_0_1_112 = &client_requests[1].plcv_buffer[112];
u16 *__QX0_0_1_125 = &client_requests[1].plcv_buffer[125];
u16 *__QX0_0_1_131 = &client_requests[1].plcv_buffer[131];
u16 *__QX0_0_1_145 = &client_requests[1].plcv_buffer[145];
u16 *__QX0_0_1_151 = &client_requests[1].plcv_buffer[151];
u16 *__QX0_0_1_10 = &client_requests[1].plcv_buffer[10];
u16 *__QX0_0_1_34 = &client_requests[1].plcv_buffer[34];
u16 *__QX0_0_1_42 = &client_requests[1].plcv_buffer[42];
u16 *__QX0_0_1_66 = &client_requests[1].plcv_buffer[66];
u16 *__QX0_0_1_74 = &client_requests[1].plcv_buffer[74];
u16 *__QX0_0_1_98 = &client_requests[1].plcv_buffer[98];
u16 *__QX0_0_1_106 = &client_requests[1].plcv_buffer[106];
u16 *__QX0_0_1_116 = &client_requests[1].plcv_buffer[116];
u16 *__QX0_0_1_129 = &client_requests[1].plcv_buffer[129];
u16 *__QX0_0_1_149 = &client_requests[1].plcv_buffer[149];
u16 *__QX0_0_1_9 = &client_requests[1].plcv_buffer[9];
u16 *__QX0_0_1_33 = &client_requests[1].plcv_buffer[33];
u16 *__QX0_0_1_41 = &client_requests[1].plcv_buffer[41];
u16 *__QX0_0_1_65 = &client_requests[1].plcv_buffer[65];
u16 *__QX0_0_1_73 = &client_requests[1].plcv_buffer[73];
u16 *__QX0_0_1_97 = &client_requests[1].plcv_buffer[97];
u16 *__QX0_0_1_105 = &client_requests[1].plcv_buffer[105];
u16 *__QX0_0_1_115 = &client_requests[1].plcv_buffer[115];
u16 *__QX0_0_1_128 = &client_requests[1].plcv_buffer[128];
u16 *__QX0_0_1_148 = &client_requests[1].plcv_buffer[148];
u16 *__QX0_0_1_16 = &client_requests[1].plcv_buffer[16];
u16 *__QX0_0_1_4 = &client_requests[1].plcv_buffer[4];
u16 *__QX0_0_1_17 = &client_requests[1].plcv_buffer[17];
u16 *__QX0_0_1_18 = &client_requests[1].plcv_buffer[18];
u16 *__QX0_0_1_19 = &client_requests[1].plcv_buffer[19];
u16 *__QX0_0_1_27 = &client_requests[1].plcv_buffer[27];
u16 *__QX0_0_1_28 = &client_requests[1].plcv_buffer[28];
u16 *__QX0_0_1_29 = &client_requests[1].plcv_buffer[29];
u16 *__QX0_0_1_30 = &client_requests[1].plcv_buffer[30];
u16 *__QX0_0_1_48 = &client_requests[1].plcv_buffer[48];
u16 *__QX0_0_1_49 = &client_requests[1].plcv_buffer[49];
u16 *__QX0_0_1_50 = &client_requests[1].plcv_buffer[50];
u16 *__QX0_0_1_51 = &client_requests[1].plcv_buffer[51];
u16 *__QX0_0_1_59 = &client_requests[1].plcv_buffer[59];
u16 *__QX0_0_1_60 = &client_requests[1].plcv_buffer[60];
u16 *__QX0_0_1_61 = &client_requests[1].plcv_buffer[61];
u16 *__QX0_0_1_62 = &client_requests[1].plcv_buffer[62];
u16 *__QX0_0_1_80 = &client_requests[1].plcv_buffer[80];
u16 *__QX0_0_1_81 = &client_requests[1].plcv_buffer[81];
u16 *__QX0_0_1_82 = &client_requests[1].plcv_buffer[82];
u16 *__QX0_0_1_83 = &client_requests[1].plcv_buffer[83];
u16 *__QX0_0_1_91 = &client_requests[1].plcv_buffer[91];
u16 *__QX0_0_1_92 = &client_requests[1].plcv_buffer[92];
u16 *__QX0_0_1_93 = &client_requests[1].plcv_buffer[93];
u16 *__QX0_0_1_94 = &client_requests[1].plcv_buffer[94];
u16 *__QX0_0_1_13 = &client_requests[1].plcv_buffer[13];
u16 *__QX0_0_1_14 = &client_requests[1].plcv_buffer[14];
u16 *__QX0_0_1_24 = &client_requests[1].plcv_buffer[24];
u16 *__QX0_0_1_25 = &client_requests[1].plcv_buffer[25];
u16 *__QX0_0_1_45 = &client_requests[1].plcv_buffer[45];
u16 *__QX0_0_1_46 = &client_requests[1].plcv_buffer[46];
u16 *__QX0_0_1_56 = &client_requests[1].plcv_buffer[56];
u16 *__QX0_0_1_57 = &client_requests[1].plcv_buffer[57];
u16 *__QX0_0_1_77 = &client_requests[1].plcv_buffer[77];
u16 *__QX0_0_1_78 = &client_requests[1].plcv_buffer[78];
u16 *__QX0_0_1_88 = &client_requests[1].plcv_buffer[88];
u16 *__QX0_0_1_89 = &client_requests[1].plcv_buffer[89];
u16 *__QX0_0_1_15 = &client_requests[1].plcv_buffer[15];
u16 *__QX0_0_1_26 = &client_requests[1].plcv_buffer[26];
u16 *__QX0_0_1_47 = &client_requests[1].plcv_buffer[47];
u16 *__QX0_0_1_58 = &client_requests[1].plcv_buffer[58];
u16 *__QX0_0_1_79 = &client_requests[1].plcv_buffer[79];
u16 *__QX0_0_1_90 = &client_requests[1].plcv_buffer[90];
u16 *__QX0_0_1_121 = &client_requests[1].plcv_buffer[121];
u16 *__QX0_0_1_122 = &client_requests[1].plcv_buffer[122];
u16 *__QX0_0_1_120 = &client_requests[1].plcv_buffer[120];
u16 *__QX0_0_1_119 = &client_requests[1].plcv_buffer[119];
u16 *__QX0_0_1_118 = &client_requests[1].plcv_buffer[118];
u16 *__QX0_0_1_117 = &client_requests[1].plcv_buffer[117];
u16 *__QX0_0_1_123 = &client_requests[1].plcv_buffer[123];
u16 *__IW0_0_2_0 = &client_requests[2].plcv_buffer[0];
u16 *__QX0_1_0_0 = &server_nodes[0].mem_area.rw_bits[0];
u16 *__QX0_1_0_5 = &server_nodes[0].mem_area.rw_bits[5];
u16 *__QX0_1_0_6 = &server_nodes[0].mem_area.rw_bits[6];
u16 *__QX0_1_0_7 = &server_nodes[0].mem_area.rw_bits[7];
u16 *__IX0_1_0_1 = &server_nodes[0].mem_area.rw_bits[1];
u16 *__IX0_1_0_2 = &server_nodes[0].mem_area.rw_bits[2];
u16 *__IX0_1_0_3 = &server_nodes[0].mem_area.rw_bits[3];
u16 *__IX0_1_0_4 = &server_nodes[0].mem_area.rw_bits[4];
u16 *__IX0_1_0_8 = &server_nodes[0].mem_area.rw_bits[8];
u16 *__IX0_1_0_0 = &server_nodes[0].mem_area.rw_bits[0];
u16 *__IW0_1_1_0 = &server_nodes[0].mem_area.rw_words[0];
u16 *__IW0_1_1_3 = &server_nodes[0].mem_area.rw_words[3];
u16 *__IW0_1_1_2 = &server_nodes[0].mem_area.rw_words[2];
u16 *__IW0_1_1_4 = &server_nodes[0].mem_area.rw_words[4];
u16 *__IW0_1_1_5 = &server_nodes[0].mem_area.rw_words[5];
u16 *__IW0_1_1_1 = &server_nodes[0].mem_area.rw_words[1];

