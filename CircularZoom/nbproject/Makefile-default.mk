#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mTouchCapLib/mTouchCapAPI.c mTouchCapLib/mTouchCapApp_DirectKeys.c mTouchCapLib/mTouchCapLED.c mTouchCapLib/mTouchCapStatus.c mTouchCapLib/mTouchCapPhy.c mTouchCapLib/mTouchCapTmr.c mTouchCapLib/TimerCallbackFunc4.c mTouchCapLib/mTouchCapADC.c CoreMain.c Microchip/Common/TimeDelay.c LIB.c Screen_09.c Screen_Font.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o ${OBJECTDIR}/CoreMain.o ${OBJECTDIR}/Microchip/Common/TimeDelay.o ${OBJECTDIR}/LIB.o ${OBJECTDIR}/Screen_09.o ${OBJECTDIR}/Screen_Font.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d ${OBJECTDIR}/CoreMain.o.d ${OBJECTDIR}/Microchip/Common/TimeDelay.o.d ${OBJECTDIR}/LIB.o.d ${OBJECTDIR}/Screen_09.o.d ${OBJECTDIR}/Screen_Font.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o ${OBJECTDIR}/CoreMain.o ${OBJECTDIR}/Microchip/Common/TimeDelay.o ${OBJECTDIR}/LIB.o ${OBJECTDIR}/Screen_09.o ${OBJECTDIR}/Screen_Font.o

# Source Files
SOURCEFILES=mTouchCapLib/mTouchCapAPI.c mTouchCapLib/mTouchCapApp_DirectKeys.c mTouchCapLib/mTouchCapLED.c mTouchCapLib/mTouchCapStatus.c mTouchCapLib/mTouchCapPhy.c mTouchCapLib/mTouchCapTmr.c mTouchCapLib/TimerCallbackFunc4.c mTouchCapLib/mTouchCapADC.c CoreMain.c Microchip/Common/TimeDelay.c LIB.c Screen_09.c Screen_Font.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX470F512H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o: mTouchCapLib/mTouchCapAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o mTouchCapLib/mTouchCapAPI.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o: mTouchCapLib/mTouchCapApp_DirectKeys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o mTouchCapLib/mTouchCapApp_DirectKeys.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o: mTouchCapLib/mTouchCapLED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o mTouchCapLib/mTouchCapLED.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o: mTouchCapLib/mTouchCapStatus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o mTouchCapLib/mTouchCapStatus.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o: mTouchCapLib/mTouchCapPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o mTouchCapLib/mTouchCapPhy.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o: mTouchCapLib/mTouchCapTmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o mTouchCapLib/mTouchCapTmr.c   
	
${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o: mTouchCapLib/TimerCallbackFunc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d" -o ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o mTouchCapLib/TimerCallbackFunc4.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o: mTouchCapLib/mTouchCapADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o mTouchCapLib/mTouchCapADC.c   
	
${OBJECTDIR}/CoreMain.o: CoreMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CoreMain.o.d 
	@${RM} ${OBJECTDIR}/CoreMain.o 
	@${FIXDEPS} "${OBJECTDIR}/CoreMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/CoreMain.o.d" -o ${OBJECTDIR}/CoreMain.o CoreMain.c   
	
${OBJECTDIR}/Microchip/Common/TimeDelay.o: Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Microchip/Common" 
	@${RM} ${OBJECTDIR}/Microchip/Common/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/Microchip/Common/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/Microchip/Common/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Microchip/Common/TimeDelay.o.d" -o ${OBJECTDIR}/Microchip/Common/TimeDelay.o Microchip/Common/TimeDelay.c   
	
${OBJECTDIR}/LIB.o: LIB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LIB.o.d 
	@${RM} ${OBJECTDIR}/LIB.o 
	@${FIXDEPS} "${OBJECTDIR}/LIB.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/LIB.o.d" -o ${OBJECTDIR}/LIB.o LIB.c   
	
${OBJECTDIR}/Screen_09.o: Screen_09.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Screen_09.o.d 
	@${RM} ${OBJECTDIR}/Screen_09.o 
	@${FIXDEPS} "${OBJECTDIR}/Screen_09.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Screen_09.o.d" -o ${OBJECTDIR}/Screen_09.o Screen_09.c   
	
${OBJECTDIR}/Screen_Font.o: Screen_Font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Screen_Font.o.d 
	@${RM} ${OBJECTDIR}/Screen_Font.o 
	@${FIXDEPS} "${OBJECTDIR}/Screen_Font.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Screen_Font.o.d" -o ${OBJECTDIR}/Screen_Font.o Screen_Font.c   
	
else
${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o: mTouchCapLib/mTouchCapAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapAPI.o mTouchCapLib/mTouchCapAPI.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o: mTouchCapLib/mTouchCapApp_DirectKeys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapApp_DirectKeys.o mTouchCapLib/mTouchCapApp_DirectKeys.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o: mTouchCapLib/mTouchCapLED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapLED.o mTouchCapLib/mTouchCapLED.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o: mTouchCapLib/mTouchCapStatus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapStatus.o mTouchCapLib/mTouchCapStatus.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o: mTouchCapLib/mTouchCapPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapPhy.o mTouchCapLib/mTouchCapPhy.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o: mTouchCapLib/mTouchCapTmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapTmr.o mTouchCapLib/mTouchCapTmr.c   
	
${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o: mTouchCapLib/TimerCallbackFunc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o.d" -o ${OBJECTDIR}/mTouchCapLib/TimerCallbackFunc4.o mTouchCapLib/TimerCallbackFunc4.c   
	
${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o: mTouchCapLib/mTouchCapADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mTouchCapLib" 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d 
	@${RM} ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o 
	@${FIXDEPS} "${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o.d" -o ${OBJECTDIR}/mTouchCapLib/mTouchCapADC.o mTouchCapLib/mTouchCapADC.c   
	
${OBJECTDIR}/CoreMain.o: CoreMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CoreMain.o.d 
	@${RM} ${OBJECTDIR}/CoreMain.o 
	@${FIXDEPS} "${OBJECTDIR}/CoreMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/CoreMain.o.d" -o ${OBJECTDIR}/CoreMain.o CoreMain.c   
	
${OBJECTDIR}/Microchip/Common/TimeDelay.o: Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Microchip/Common" 
	@${RM} ${OBJECTDIR}/Microchip/Common/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/Microchip/Common/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/Microchip/Common/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Microchip/Common/TimeDelay.o.d" -o ${OBJECTDIR}/Microchip/Common/TimeDelay.o Microchip/Common/TimeDelay.c   
	
${OBJECTDIR}/LIB.o: LIB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LIB.o.d 
	@${RM} ${OBJECTDIR}/LIB.o 
	@${FIXDEPS} "${OBJECTDIR}/LIB.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/LIB.o.d" -o ${OBJECTDIR}/LIB.o LIB.c   
	
${OBJECTDIR}/Screen_09.o: Screen_09.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Screen_09.o.d 
	@${RM} ${OBJECTDIR}/Screen_09.o 
	@${FIXDEPS} "${OBJECTDIR}/Screen_09.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Screen_09.o.d" -o ${OBJECTDIR}/Screen_09.o Screen_09.c   
	
${OBJECTDIR}/Screen_Font.o: Screen_Font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Screen_Font.o.d 
	@${RM} ${OBJECTDIR}/Screen_Font.o 
	@${FIXDEPS} "${OBJECTDIR}/Screen_Font.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -MMD -MF "${OBJECTDIR}/Screen_Font.o.d" -o ${OBJECTDIR}/Screen_Font.o Screen_Font.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -Os -o dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -Os -o dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/CircularZoom.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
