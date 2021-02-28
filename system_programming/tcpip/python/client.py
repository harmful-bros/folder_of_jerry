#!/usr/bin/env python3

import socket
import sys

def main():
    skt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    skt.connect(("", 1524))

    buf = b''
    while True:
        msg = input("입력: ")
        if msg == "q":
            skt.send(msg.encode())
            break

        skt.send(msg.encode())
        buf = skt.recv(1024)
        print(buf.decode())
    
#    skt.send("Hello World!".encode())

    skt.close()
    print("Closed the client!")


if __name__ == "__main__":
    sys.exit(main() or 0)
