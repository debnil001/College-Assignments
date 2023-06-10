ls
count=0
flag=0
for file in *.sh;do
	if [ ${file%.xyz} ]
	then
		flag=1
		count=$(($count+1))
	fi
done
if [ $flag -eq 0 ]
then
	echo "No .sh file is there in the directory"
else
	echo "There are $count .sh files in the directory"
fi
