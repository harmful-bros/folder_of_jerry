#!/usr/bin/env python3

import socket
import sys
from binascii import hexlify

def main() -> None:

    if len(sys.argv) < 3:
        print("Need to input parameters!")
        return

    skt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    skt.bind((sys.argv[1], int(sys.argv[2])))
    skt.listen()

    client, addr = skt.accept()
    for idx in range(5):
#        buf = b''
        while True:
            get_msg = client.recv(1024)
            if get_msg.decode() == "q":
                break;
            client.send(get_msg)
#            buf += get_msg
#        print(buf.decode())

    client.close()
    skt.close()

    print("Closed the server!")


if __name__ == "__main__":
    sys.exit(main() or 0)
