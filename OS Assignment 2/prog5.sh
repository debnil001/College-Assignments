#echo "$*"
for i in $*
do
	echo "Disk Space occupied by the directory $i"
	bytes=`du -bs $i | cut -f1`
	echo "Size in byte $bytes"
	kilobytes=`du -sk $i | cut -f1`
	echo "Size in kilobyte $kilobytes KB"
	megabytes=`du -sm $i | cut -f1`
	echo "Size in megabyte $megabytes MB"
done 
