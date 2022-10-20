#!/bin/bash

echo "Compiling..."
make re >/dev/null 2>myVector.error

if [[ $? -ne 0 ]]
then
	echo "my vector compilation failed check myVector.error"
	exit 1
fi

echo "done, launching containers..."
./containers > myVector.output

echo "Compiling..."
make real >/dev/null 2>realVector.error

if [[ $? -ne 0 ]]
then
	echo "real vector compilation failed check realVector.error"
	make clean
	exit 1
fi

echo "done, launching containers..."
./containers > realVector.output


echo -e "\n\t\tMY CONTAINERS\t\t\t\t\t\t\tREAL CONTAINERS\n"
diff -y -s myVector.output realVector.output

DIFF=$(diff -I '^TIME.*' -I '^CAPACITY.*' myVector.output realVector.output)
if [[ -z "$DIFF" ]]
then
	echo -e "OK✅!!"
else
	echo -e "KO❌!!"
fi

make clean_error >/dev/null
