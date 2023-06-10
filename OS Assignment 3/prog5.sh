ls -l $1
src=$1
flag=0
ex=exe
for file in *.sh;do
	if cmp -s "$file" "$src"
	then
		flag=1
		mv "$src" "${file%.sh}.exe"
	fi
done

if [ $flag -eq 0 ]
then
	echo "No such File '$src' existed"
else
	echo "$src is renamed to ${src%.sh}.exe"
fi

