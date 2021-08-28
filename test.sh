make
for ((i=1;i<=7;i++))
do
time ./main < testcase/$i.in > myout/$i.out
diff -q myout/$i.out testcase/$i.out
if [ $? -ne 0 ]; then
	echo WA
else
	echo OK
fi
done
