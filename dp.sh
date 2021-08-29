while true
do
    ./gen-small > s.in
    ./brute < s.in > s.ans
    ./main < s.in > s.out
    diff s.out s.ans
    if [ $? -ne 0 ]; then
    echo "wa"
    exit
    else
    echo "ok"
    fi
done