CC = g++
FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
IFLAGS = -Iinclude
SRCDIR = src
OBJDIR = obj
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/stack.o $(OBJDIR)/vtor.o $(OBJDIR)/my_assert.o $(OBJDIR)/cmd_input.o $(OBJDIR)/hash.o $(OBJDIR)/input.o

all: $(OBJECTS)
	@$(CC) $(OBJECTS) -o Stack

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/stack.o: $(SRCDIR)/stack.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/vtor.o: $(SRCDIR)/vtor.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/my_assert.o: $(SRCDIR)/my_assert.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/cmd_input.o: $(SRCDIR)/cmd_input.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/hash.o: $(SRCDIR)/hash.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

$(OBJDIR)/input.o: $(SRCDIR)/input.cpp
	@$(CC) $(FLAGS) $(IFLAGS) -c $^  -o $@

clean:
	@rm -f $(OBJDIR)/*.o *~ core *~ *.exe

