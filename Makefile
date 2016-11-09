SRCDIR = .
OBJDIR = .

CFLAGS:= -g -Wall -Werror -Wno-deprecated -fPIC 
TARGET:= tool_tab
LDFLAGS:= 

SRC := $(wildcard $(SRCDIR)/*.cpp)

OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

DEPS = $(SRC:.cpp=.d) 
.PHONY : all deps clean veryclean install objs

all : $(TARGET)

deps : $(DEPS)

objs : $(OBJS)

$(OBJS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(SRCINC) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o 
	rm -f *.d
	rm -f $(TARGET)

$(TARGET) : $(OBJS) 
	$(CXX) $(OBJS) -o $(TARGET) $(LIBDIR) $(LDFLAGS)

