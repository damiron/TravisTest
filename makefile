#------------------------------------------------------------------------
#  makefile SOFTNET-S7/LINUX
#------------------------------------------------------------------------

#------------------------------------------------------------------------
#   Directives & Variables
#------------------------------------------------------------------------

CC = g++

CFLAGS = -g

OBJECTS = main.o

INCLUDES = -I/usr/share/doc/libxsd

LIBS = -lxerces-c

DEMO = xercesExample

#------------------------------------------------------------------------
#   Source Instructions
#------------------------------------------------------------------------

all:		$(DEMO)

main.o:	main.cpp
		@echo "compiling $@ ..."
		$(CC) $(CFLAGS) -c -o main.o main.cpp $(INCLUDES)
		@echo "finished compiling $@ ..."


$(DEMO):	makefile $(OBJECTS)
		@echo "creating $@ ..."
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(DEMO)
		@echo "finished $@ ..."

clean:
		rm -f $(DEMO) *.o

#------------------------------------------------------------------------
#   End
#------------------------------------------------------------------------
