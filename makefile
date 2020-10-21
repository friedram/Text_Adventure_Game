##Program Name: makefile
##Author:       Andrew Friedrich
##Date:         06/01/2019
##Description:  CS162 Final_Project Makefile - used video on CS162 to assist in creation
##This makefile was largely taken and inspired by the OSU CS162 video series
##Specifically the Lecture File I/O series 1, 2 & 3 and additional inspiration
##comes from the makefile provided as a "TA's Makefile Example" - written by
## author - Harlan James <waldroha@oregonstate.edu>

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic -errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = menu.o boss.o fountain.o Game.o Goblin.o inputValidation.o Introduction_Space_Location.o Item.o Player.o pray.o rockey.o Space.o stone.o main.o

SRCS = menu.cpp boss.cpp fountain.cpp Game.cpp Goblin.cpp inputValidation.cpp Introduction_Space_Location.cpp Item.cpp Player.cpp pray.cpp rockey.cpp Space.cpp stone.cpp main.cpp

HEADERS = menu.hpp boss.hpp fountain.hpp Game.hpp Goblin.hpp inputValidation.hpp Introduction_Space_Location.hpp Item.hpp Player.hpp pray.hpp rockey.hpp Space.hpp stone.hpp

Recursive: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o FinalProject
	
${OBJS}:  ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm *.o FinalProject