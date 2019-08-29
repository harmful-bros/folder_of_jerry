#########################################################################################################
#                                                                                                       #
#       FILE            : makefile( sub )								#
#       INTRODUCE       : makefile for low rank folder							#
#       AUTHOR          : Hertz9th leejaeseong                                                          #
#       DATE            : 2011/09/19                                                                    #
#       BRIEF           : compile the current folder.							#
#                         depends on the makefile in most significant folder.				#
#                                                                                                       #
#########################################################################################################

all :
	for file in $(wildcard *.c) ; do \
	$(CC) $(CFLAGS) $$file ; \
	done
