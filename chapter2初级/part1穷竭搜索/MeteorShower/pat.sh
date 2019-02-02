while true; do
	python3 mock_meteor.py
	./correct.out < data > correctout
	./my.out < data > myout
	if diff correctout myout; then
		echo AC
		cat myout
	else
		echo WA
		cat data
		exit 0
	fi
done
