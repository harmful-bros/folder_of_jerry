#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "../msg_que.h"

int main(void)
{
	/* create message queue */
	int msg_id = msgget(KEY_VALUE, IPC_CREAT| 0666);
	if (msg_id < 0)
	{
		printf("Failed to create message queue.\n");
		return -errno;
	}

	int ret;
	msg_que_t msg_que;
	memset(&msg_que, 0x00, sizeof(msg_que_t));

	while (1)
	{
		printf("Client > ");
		ret = msgrcv(msg_id, &msg_que, sizeof(msg_que_t), MESSAGE_TYPE, 0);
		if (ret < 0)
		{
			printf("Failed to receive message.\n");
			goto escape;
		}

		printf("int : %d dou : %lf char* : %s\n",
				msg_que.int_data,
				msg_que.double_data,
				msg_que.char_data);

		if (!strcmp(msg_que.char_data, "quit"))
			break;
	}

escape:
	return 0;
}
