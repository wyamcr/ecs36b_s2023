# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC 	= g++ -std=c++14
CFLAGS 	= -g
CXXFLAGS = "-mmacosx-version-min=11.1"
LDFLAGS = -L/opt/homebrew/lib -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client

# rules.
all: 	main

#
#

ecs36b_JSON.o:	ecs36b_JSON.cpp
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

Record.o:	Record.cpp Record.h main.h
	$(CC) -c $(CFLAGS) Record.cpp

GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h GPS.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h Person.h
	$(CC) -c $(CFLAGS) Thing.cpp

main.o:	main.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) main.cpp

main:	GPS.o main.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 main.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o main $(LDFLAGS)

clean:
	rm -f *.o *~ core main