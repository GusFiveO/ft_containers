#!/bin/bash

echo "Compiling..."
make re >/dev/null
echo "done, launching containers..."
./containers

mv myVector.output myvector.output

echo "Compiling..."
make fclean real >/dev/null
echo "done, launching containers..."
./containers

echo -e "\n\t\tMY VECTOR\t\t\t\t\t\t\tREAL VECTOR\n"
diff -y -s --color myvector.output realVector.output
DIFF=$(diff -I '^TIME.*' myvector.output realVector.output)
if [[ -z "$DIFF" ]]
then
	echo -e "OK✅!!"
else
	echo -e "KO❌!!"
fi
