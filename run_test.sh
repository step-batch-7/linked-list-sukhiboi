cp list.c list.h test
cd test
rm -rf *.o
gcc -c *.c
gcc -o run_test *.o
echo "Running tests"
echo "----------------------------------------------"
./run_test
echo "\n"
rm -rf *.o
rm list.c list.h
rm run_test
