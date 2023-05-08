count=0
for file in *
do
	count=$(( count +1 ))
done
echo "Total count of files and directory is $count"
for file in *
do
    if [ -f $file ]
    then
        echo "$file is a regular file"
    elif [ -d $file ]
    then
        echo "$file is a directory"
    fi
done
