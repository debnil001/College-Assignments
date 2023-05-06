count=0
for file in *.sh
do
	count=$(( count+1 ))
done
echo "Total shell scripts in this directory is:: "$count
exp=`ls -l | awk '{print $5}'`
total=0
for i in $exp
do 
	total=$(( total + i ))
done
echo $total
