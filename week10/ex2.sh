link ../week01/file.txt _ex2.txt
find . -inum $(ls -i ../week01/file.txt | cut -f 1 -d " ") | tee -a ex2.txt
find . -inum $(ls -i ../week01/file.txt | cut -f 1 -d " ") -exec rm -rf {} \; | tee -a ex2.txt
