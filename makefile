
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
test: Clock.o Thing.o  Container.o Room.o MobileThing.o Direction.o Exit.o\
 all_test.o Clock_test.o  TCR_test.o MobileThing_test.o Direction_test.o \
 Exit_Room_test.o \
 $(LIB_BOOST_UTF)
	$(CXX)  -o $@ $^ 
	./$@

### file dependent created by command "make rule"
Clock.o: Clock.cpp Clock.hpp CallBack.hpp
Clock_test.o: Clock_test.cpp Clock.hpp CallBack.hpp
Container.o: Container.cpp Container.hpp Thing.hpp MobileThing.hpp
Direction.o: Direction.cpp Direction.hpp
Direction_test.o: Direction_test.cpp Direction.hpp
Exit.o: Exit.cpp Exit.hpp Direction.hpp Room.hpp Container.hpp Thing.hpp \
 MobileThing.hpp
Exit_Room_test.o: Exit_Room_test.cpp Thing.hpp Room.hpp Container.hpp \
 MobileThing.hpp
Exit_test.o: Exit_test.cpp Room.hpp Container.hpp Thing.hpp \
 MobileThing.hpp Exit.hpp Direction.hpp
MobileThing.o: MobileThing.cpp MobileThing.hpp Thing.hpp Container.hpp
MobileThing_test.o: MobileThing_test.cpp MobileThing.hpp Thing.hpp \
 Room.hpp Container.hpp
Room.o: Room.cpp Room.hpp Container.hpp Thing.hpp MobileThing.hpp
TCR_test.o: TCR_test.cpp Thing.hpp Container.hpp MobileThing.hpp Room.hpp
Thing.o: Thing.cpp Thing.hpp Container.hpp MobileThing.hpp
all_test.o: all_test.cpp Container.hpp Thing.hpp MobileThing.hpp \
 CallBack.hpp Clock.hpp
main.o: main.cpp Clock.hpp CallBack.hpp
