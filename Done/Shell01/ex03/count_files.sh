Files=$(find . -type f | wc -l)
Folders=$(find . -type d | wc -l)
sum=$((Files + Folders))
echo $sum
