for((i = 1; i<=100; ++i)); do
	echo $i
	./gen $i > in3
	./my < in3 > out2
	./his < in3 > out3
	diff -w out2 out3 || break
done
