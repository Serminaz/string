LOG_FILE=$1
PROG_NAME=$2
valgrind --log-file=$LOG_FILE ./$PROG_NAME $3
clear
cat $LOG_FILE | grep "lost"
