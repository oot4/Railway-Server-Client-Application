#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/client.o \
	${OBJECTDIR}/filereader.o \
	${OBJECTDIR}/siding.o \
	${OBJECTDIR}/sidingslogisticsmain.o \
	${OBJECTDIR}/vehicle.o \
	${OBJECTDIR}/wagon.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sidingslogistics

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sidingslogistics: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sidingslogistics ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/client.o: client.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/client.o client.cpp

${OBJECTDIR}/filereader.o: filereader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filereader.o filereader.cpp

${OBJECTDIR}/siding.o: siding.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/siding.o siding.cpp

${OBJECTDIR}/sidingslogisticsmain.o: sidingslogisticsmain.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sidingslogisticsmain.o sidingslogisticsmain.cpp

${OBJECTDIR}/vehicle.o: vehicle.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/vehicle.o vehicle.cpp

${OBJECTDIR}/wagon.o: wagon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/boost_1_62_0/boost_debug/include -I/usr/local/boost_1_62_0/boost_debug/lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wagon.o wagon.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
