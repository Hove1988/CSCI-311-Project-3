
all: client serverc serverg

client: client.c soc.h shared.h
	$(CC) $(CFLAGS) -o client client.c
serverc: serverG.c soc.h shared.h
	$(CC) $(CLFAGS) -o serverG serverG.c 
serverg: serverC.c soc.h shared.h
	$(CC) $(CLFAGS) -o serverC serverC.c
clean:
	$(RM) client serverC serverG 