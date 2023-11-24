echo "until"
j=1
until[$j -gt 10]
do
echo"$j"
j='expr$j+1'
done

