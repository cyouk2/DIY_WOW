#!/bin/bash
check=$(netstat -nlt | grep ":8085" | wc -l)
if [ "${check}" -eq 0 ]; then
        screen -S mangosd ./mangosd
else
        echo "realmd is running"
fi
