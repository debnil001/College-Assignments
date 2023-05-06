exp=`ls -l | awk '{print $5}'`
total=0
for i in $exp
do 
	total=$(( total + i ))
done
echo "Total space occupied by the current directory is "$total" Byte"
