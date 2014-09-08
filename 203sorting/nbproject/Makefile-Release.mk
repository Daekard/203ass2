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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1292091561/binaryTree.o \
	${OBJECTDIR}/_ext/1292091561/skel.o \
	${OBJECTDIR}/_ext/1292091561/sorttest.o \
	${OBJECTDIR}/_ext/1292091561/treeNode.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/203sorting

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/203sorting: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/203sorting ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1292091561/binaryTree.o: ../../../ass2files/binaryTree.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1292091561
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1292091561/binaryTree.o ../../../ass2files/binaryTree.cpp

${OBJECTDIR}/_ext/1292091561/skel.o: ../../../ass2files/skel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1292091561
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1292091561/skel.o ../../../ass2files/skel.cpp

${OBJECTDIR}/_ext/1292091561/sorttest.o: ../../../ass2files/sorttest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1292091561
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1292091561/sorttest.o ../../../ass2files/sorttest.cpp

${OBJECTDIR}/_ext/1292091561/treeNode.o: ../../../ass2files/treeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1292091561
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1292091561/treeNode.o ../../../ass2files/treeNode.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/203sorting

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
