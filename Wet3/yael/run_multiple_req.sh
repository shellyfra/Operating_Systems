#!/bin/bash
for i in 1 2 3
do
   #./client 127.0.0.1 8000 output${i}.cgi &
   ./client 127.0.0.1 8000 output.cgi &
done
