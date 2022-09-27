#!/bin/bash

echo "Compiling..."
make re >/dev/null
echo "done, launching containers..."
./containers > myVector.output

echo "Compiling..."
make clean real >/dev/null
echo "done, launching containers..."
./containers > realVector.output

echo -e "\n\t\tMY VECTOR\t\t\t\t\t\t\tREAL VECTOR\n"
diff -y -s myVector.output realVector.output
DIFF=$(diff -I '^TIME.*' myVector.output realVector.output)
if [[ -z "$DIFF" ]]
then
	echo -e "OK✅!!"
else
	echo -e "KO❌!!"
fi
