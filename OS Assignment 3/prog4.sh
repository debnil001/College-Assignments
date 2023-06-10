flag=0
ls
for file in *~;do
	if [ -f $file ]
	then
		echo "$file is deleted"
		rm $file
		flag=1
	fi
done
if [ $flag -eq 0 ]
then
	echo "No temporary files in directory"
else
	echo "All temporary files are deleted"
fi 

