#bin/bash

#Some variable
file="integer.txt" 
lock="${file}.lock"
#Check if file exists
if [ ! -f $file ]
then
	echo 0 > $file
fi

#Chech for another process using this file 
while [ -f $lock ]
do
	echo File is locked!
done
#when one process start using the file, we make another file with different i-node in order to prevent race conditions and copy the file 
ln ${file} ${lock}
#fill the file with sequential numbers from 0 to 999, read the last number in the file, add 1 to to it and append the file with this number
#for example if i do the following command: echo $(($(tail -n 1 test) + 1)) | tee -a i won't get a race condition because firstly process in foreground will proceed and secondly the process in background. thus, the last number in the #file will be 1998
for i in {1..999}
do
	echo $(($(tail -n 1 ${file}) + 1)) | tee -a  $file
done
#and here we delete the lock file, as now the file is free
rm ${lock}
# 1) How long does it take before a race condition manifests itself? - Almost immediately. Because two processes will overlap the results of each other.
# 2) What is the critical region? - The part of the program where the shared memory is accessed.
# 3) Successfullly modified the script 
