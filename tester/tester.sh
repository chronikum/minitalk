sh -c './server.a >> ./out.p&'
PID=$(pgrep server.a)
./client.a ${PID} TESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTEST
echo "\n"
cat out.p
rm out.p
killall server.a