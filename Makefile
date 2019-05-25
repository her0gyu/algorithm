CXX = g++
CXXFLAGS = -g -O2
CXXFLAGS += -Wall -W
TARGET= btree
OBJECTS= btree_node.o btree.o
RM = rm -rf
.SUFFIXES : .cc .o

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

.cc .o :
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJECTS) $(TARGET)
