#!/bin/bash

# run as root

LOF=./lofsdisk

deps_fix () {
	mkdir -p $LOF/bin
	for d in $@; do
		cp -rfu "/bin/${d}" $LOF/bin
		list="$(ldd /bin/${d} | egrep -o '/lib.*\.[0-9]')"
		for i in $list; do mkdir -p $(dirname "${LOF}${i}") && cp -rfu "$i" "${LOF}${i}"; done
                list="$(ldd /bin/${d} | egrep -o '/lib64.*\.[0-9]')"
                for i in $list; do mkdir -p $(dirname "${LOF}${i}") && cp -rfu "$i" "${LOF}${i}"; done
                list="$(ldd /bin/${d} | egrep -o '/usr/lib.*\.[0-9]')"
                for i in $list; do mkdir -p $(dirname "${LOF}${i}") && cp -rfu "$i" "${LOF}${i}"; done
                list="$(ldd /bin/${d} | egrep -o '/usr/lib64.*\.[0-9]')"
                for i in $list; do mkdir -p $(dirname "${LOF}${i}") && cp -rfu "$i" "${LOF}${i}"; done
	done
}

./ex1.sh

echo "Dzhemilya" > $LOF/file1
echo "Gizutdinova" > $LOF/file2
gcc ex2.c -o ex2.out
gcc ex2.c -o $LOF/ex2.out

deps_fix {bash,cat,echo,ls}

echo "[+] From chroot:" > ex2.txt
chroot $LOF ./ex2.out >> ex2.txt
echo "" >> ex2.txt
echo "[+] From root:" >> ex2.txt
./ex2.out >> ex2.txt
