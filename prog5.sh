files=`ls *.sh`
exten="exe"
count=0
for file in $files
do
	mv $file ${file%.sh}.$exten
done 

#find . -name '*~' -type f -delete