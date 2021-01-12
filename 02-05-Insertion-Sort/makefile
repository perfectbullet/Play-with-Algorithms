#g++ compiler: options

# -std=c++0x enables ISO C++ 11 standard
# -I.. pulls in the Version_test.h file for conditional compilation
#      of code the uses features that might not yet be implemented

CC = g++
CCFLAGS = -std=c++0x -I..

all:main.exe

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file
# %.o: %.c  模式匹配   http://www.ruanyifeng.com/blog/2015/02/make.html

%.o: %.cc 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@

# rule that says how to make a .exe executable file from a .o object file
%.exe: %.o 
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@

# target to clean up the object files and any core files
# executing "make clean" in a subdirectory will remove all
# files named core or any file ending in .obj, or .stackdump
clean:
	rm -rf *.o core *.stackdump

# target to remove executable files as well as object and core files
clobber: clean
	rm -rf *.exe 




