#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

#define KEY_VALUE		(key_t)1524
#define MESSAGE_TYPE	1

#define MAX_BUF			4096

typedef struct message_queue
{
	long type;
	int int_data;
	double double_data;
	char char_data[MAX_BUF];
//	char *char_data;
}msg_que_t;

#endif
