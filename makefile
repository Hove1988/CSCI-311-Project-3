
CFLAGS = -D_POSIX_SOURCE

all: client serverc serverg

client: client.c soc.c
	$(CC) $(CFLAGS) -o client client.c
serverc: serverG.c soc.c
	$(CC) $(CLFAGS) -o serverG serverG.c
serverg: serverC.c soc.c
	$(CC) $(CLFAGS) -o serverC serverC.c
clean:
 	$(RM) client serverC serverG 