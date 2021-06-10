build.out:alpha1_client.o alpha1_server.o
	gcc alpha1_client.o alpha1_server.o
client.o:alpha1_client.c alpha1_server.h
	gcc -c alpha1_client.c 
server.o:alpha1_server.c alpha1_server.h
	gcc -c alpha1_server.c
