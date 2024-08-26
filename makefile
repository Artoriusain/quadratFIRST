WARNINGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
		   -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
		   -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe	 \
		   -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body    \
		   -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op            \
		   -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual   \
		   -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing         \
		   -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG \
		   -D_EJUDGE_CLIENT_SIDE

EXEC = exec.exe
OBJS = main tester input printor mymath

all: $(OBJS)
	@g++ main.o printor.o input.o mymath.o tester.o -o $(EXEC)

main: main.cpp
	@g++ main.cpp $(WARNINGS) -c
tester: tester.cpp
	@g++ tester.cpp $(WARNINGS) -c
input: input.cpp
	@g++ input.cpp $(WARNINGS) -c
printor: printor.cpp
	@g++ printor.cpp $(WARNINGS) -c
mymath: mymath.cpp
	@g++ mymath.cpp $(WARNINGS) -c

run:
	$(EXEC)

clean:
	@del *.o
	@del *.exe
