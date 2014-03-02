#The flags, complain about everything, make it into an executable
# named main
CFLAGS    =-Wall -g
INCLUDES  =-Ithreads
#The libraries, includes the boost system and boost threading libs
LIBRARIES =-lboost_thread -lboost_system
CC        =g++
# Add to this if more .c files are necessary
SOURCES     = threads/thread.cpp
#TESTSOURCES =

all:
	$(CC) $(SOURCES) $(CFLAGS) $(INCLUDES) $(LIBRARIES) -o main

doxygen:
	doxygen Doxyfile
	cd latex;make

clean:
	echo "Do nothing for now"
