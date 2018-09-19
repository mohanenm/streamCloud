#make file - this is a comment section..........run  cat -e -t -v {Makefile} when missing sep
	
CC=gcc  #compiler
TARGET= /src/hw1/steps/bincount
	
all:
	$(CC) bincount.c  -o $(TARGET)
	
clean:
	rm $(TARGET)
