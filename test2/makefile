
CXX = g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = debug.o 

SRCS = debug.cpp

HEADERS = 

name: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o name

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

