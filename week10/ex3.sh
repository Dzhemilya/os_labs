chmod a-x _ex3.txt
chmod uo=rwx _ex3.txt | tee -a ex3.txt
chmod g=u _ex3.txt | tee -a ex3.txt
echo 660 means that user has a permission to read and write, group has a permission to read and write, others do not have an access to the file | tee -a ex3.txt
echo 775 means that user has a permission to read, write and execute, group has a permission to read, write and execute, others have a permission to read and execute | tee -a ex3.txt
echo 777 means thst user, group and others has all possible permissions: read, write, execute | tee -a ex3.txt
