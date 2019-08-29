#include <iostream>
using namespace std;

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET& p)
{
	cin >> p.packet_no >> p.prior_level; // packet_no, prior_level 입력
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer(PACKET& p)
{
	PACKET *pac;

	pac = new PACKET();

	*pac = p;

	last_packet = &buffer;
	while (last_packet->next)
	{
		if (last_packet->next->prior_level > pac->prior_level)
			break;
		else
			last_packet = last_packet->next;
	}

	pac->next = last_packet->next;
	last_packet->next = pac;

	return SUCCESS;
}
int Get_Packet_from_Buffer(PACKET& p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	p = *buffer.next;
	delete buffer.next;

	buffer.next = p.next;

	return SUCCESS;
}

int main(void)
{
	int N;
	PACKET packet;

	cin >> N;	// 패킷의 수 입력

//	last_packet = &buffer;
	packet.next = NULL;

	// 패킷의 수신
	for (int i = 0; i < N; i++)
	{
		Input_Packet(packet);
		Put_Packet_to_Buffer(packet);
	}

	// 패킷 처리순서 출력
	while (Get_Packet_from_Buffer(packet) == SUCCESS)
	{
		cout << packet.packet_no << " ";
	}
	cout << endl;

	return 0;
}


