#Makefile Trabalho Final

CC=g++
LD=g++

#CPPFLAGS=$(pkg-config --cflags python3) -fPIE
CFLAGS=`python3.8-config --cflags` -fPIE
LDFLAGS=`/usr/python3.8-config --embed --ldflags`


MAINOBJS = main.o menu.o email.o emailFolder.o file.o

MAINEXEC = SpamClassifier

.cpp.o:
	$(CC) $(CFLAGS) -c $<

SpamClassifier: $(MAINOBJS)
		$(LD) -I/usr/include/python3.8 -o $@ $(MAINOBJS) -L /usr/lib/x86_64-linux-gnu/ -lpython3.8


clean:
	rm -f $(MAINOBJS)

clean-all: clean-lin

clean-lin:
	rm -f $(MAINOBJS) $(MAINEXEC)
clean-win: 
	-del $(MAINOBJS) $(MAINEXEC).exe
