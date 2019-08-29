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
	int msg_id = msgget(KEY_VALUE, IPC_CREAT | 0666);
	if (msg_id < 0)
	{
		printf("Failed to create message queue.\n");
		return -errno;
	}

	int ret;
	int cnt = 0;
	char buf[MAX_BUF];

	msg_que_t msg_que;
	memset(&msg_que, 0x00, sizeof(msg_que_t));

	while (1)
	{
		printf("Server > ");
		fgets(buf, MAX_BUF, stdin);
		buf[strlen(buf) - 1] = '\0';

		/* create message */
		msg_que.type = 1;
		msg_que.int_data = cnt;
		msg_que.double_data = (double)cnt;
		strcpy(msg_que.char_data, buf);
//		msg_que.char_data = buf;

		cnt++;

		/* send message */
		ret = msgsnd(msg_id, &msg_que, sizeof(msg_que_t), 0);
		if (ret < 0)
		{
			printf("Failed to send the message.\n");
			goto escape;
		}

		if (!strcmp(buf, "quit"))
			break;
	}

escape :
	ret = msgctl(msg_id, IPC_RMID, NULL);
	if (ret < 0)
		printf("Failed to delete message queue.\n");

	return 0;
}
