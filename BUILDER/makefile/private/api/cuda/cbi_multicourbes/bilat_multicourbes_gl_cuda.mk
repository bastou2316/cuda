# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_MULTICOURBES_GL_CUDA_MK__
__API_BILAT_MULTICOURBES_GL_CUDA_MK__=true

##########################################
#   		Bilat CUDA MULTICOURBES 	 #
##########################################


#dependance
include $(API_CUDA)/cuda.mk
include $(API)/openmp.mk
include $(API_BILAT_OPENGL)/bilat_opengl_tools.mk
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_displayable.mk
include ${API_BILAT_MULTICOURBES_CUDA}/bilat_multicourbes_version.mk

#path
BILAT_MULITCOURBES_GL_CUDA_PATH=${BILAT_MULTICOURBES_CUDA_PATH}/${BILAT_MULITCOURBES_GL_CUDA_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
override CODE_DEFINE_VARIABLES+=#
override API_INC+= ${BILAT_MULITCOURBES_GL_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_GL_CUDA_PATH}/,${BILAT_MULITCOURBES_GL_CUDA_INC})

#Linkage
#Use SrcAux car nom lib complexe!
override SRC_AUX+= ${BILAT_MULITCOURBES_GL_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_GL_CUDA_PATH}/,${BILAT_MULITCOURBES_GL_CUDA_LIB})  

#Runtime
override API_BIN+= ${BILAT_MULITCOURBES_GL_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_GL_CUDA_PATH}/,${BILAT_MULITCOURBES_GL_CUDA_BIN})

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)
	#rien
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)
	#rien	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	#rien	
endif

endif#win

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# ARM   #
############

ifeq  ($(ARCH),arm)
	ARM_FOLDER="_arm"
else
	ARM_FOLDER=#
endif

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)
	#rien		
endif

############
# INTEL   #
############

ifeq  ($(COMPILATEUR),INTEL)
	#rien	
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_MULTICOURBES_GL_CUDA_MK__
