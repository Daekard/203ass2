PROG = sortbook 
OBJS = skel.o treeNode.cpp binaryTree.cpp
CC = g++
CFLAGS = -ansi -pedantic -Wall
LFLAGS =			#default path should be ok
LIBS = -lrt			#needed for timing code

$(PROG) : $(OBJS) 
	$(CC) $(LFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -rf $(OBJS)

realclean:
	rm -rf $(PROG) $(OBJS) core

#default rule for cpp to .o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@
