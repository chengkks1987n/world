
CXXFLAGS=-Wall -g
INCLUDE=/home/ck/boost-lib/include/
LIB_BOOST=/home/ck/boost-lib/lib
CPPFLAGS=-I$(INCLUDE)

LIB_BOOST_UTF=$(LIB_BOOST)/libboost_unit_test_framework.a 


all: main.o Clock.o
	$(CXX) -o $@ $^

### others

rule:
	$(CXX) -MM *.cpp

clean:
	-rm -rf *~ 
	-rm -rf *.o 
	-rm -rf world all
	-rm -rf test tmp.cpp

### testing
test: Clock.o Container.o NamedObject.o Room.o Thing.o \
 all_test.o  Clock_test.o Room_test.o \
 $(LIB_BOOST_UTF)
	$(CXX)  -o $@ $^ 
	./$@

### file dependent created by command "make rule"

Clock.o: Clock.cpp Clock.hpp CallBack.hpp
Clock_test.o: Clock_test.cpp Clock.hpp CallBack.hpp
Container.o: Container.cpp Container.hpp Thing.hpp NamedObject.hpp
NamedObject.o: NamedObject.cpp NamedObject.hpp
Room.o: Room.cpp Room.hpp Container.hpp Thing.hpp NamedObject.hpp
Room_test.o: Room_test.cpp Thing.hpp Container.hpp NamedObject.hpp \
 Room.hpp
Thing.o: Thing.cpp Thing.hpp Container.hpp NamedObject.hpp
all_test.o: all_test.cpp Container.hpp Thing.hpp NamedObject.hpp \
 CallBack.hpp Clock.hpp
main.o: main.cpp Clock.hpp CallBack.hpp
