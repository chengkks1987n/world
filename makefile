
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
test: Clock.o Clock_test.o Container.o NamedObject.o NamedObject_test.o Root.o \
 Thing.o all_test.o Room.o \
 $(LIB_BOOST_UTF)
	$(CXX)  -o $@ $^ 
	./$@


### file dependent created by command "make rule"

Clock.o: Clock.cpp Clock.hpp CallBack.hpp Root.hpp
Clock_test.o: Clock_test.cpp Clock.hpp CallBack.hpp Root.hpp
Container.o: Container.cpp Container.hpp Root.hpp Thing.hpp \
 NamedObject.hpp
NamedObject.o: NamedObject.cpp NamedObject.hpp Root.hpp
NamedObject_test.o: NamedObject_test.cpp Room.hpp Container.hpp Root.hpp \
 Thing.hpp NamedObject.hpp
Room.o: Room.cpp Room.hpp Container.hpp Root.hpp Thing.hpp \
 NamedObject.hpp
Root.o: Root.cpp Root.hpp
Thing.o: Thing.cpp Thing.hpp Container.hpp Root.hpp NamedObject.hpp
all_test.o: all_test.cpp
main.o: main.cpp Clock.hpp CallBack.hpp Root.hpp
